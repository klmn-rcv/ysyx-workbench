#include <chrono>
#include "common.h"
#include "dpi-c.h"
#include "sim.h"
#include "state.h"
#include "debug.h"

extern char pmem[];  // memory

static uint64_t rtc_snapshot = 0; // 防止直接读系统时间可能导致的高32位和低32位不一致
static auto boot_time = std::chrono::steady_clock::now();
static const uint32_t start_pc = 0x80000000;

extern "C" void sim_halt(int exit_code, uint32_t exit_pc) {
  npc_state.state = NPC_END;
  npc_state.halt_ret = exit_code;
  npc_state.halt_pc = exit_pc;
}

extern "C" int pmem_read(uint32_t raddr, uint8_t src_type) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  if (raddr == 0x10000004) { // 时钟低32位
    return static_cast<uint32_t>(rtc_snapshot);
  }
  if (raddr == 0x10000008) { // 时钟高32位
    auto now = std::chrono::steady_clock::now();
    rtc_snapshot = std::chrono::duration_cast<std::chrono::microseconds>(now - boot_time).count();
    return static_cast<uint32_t>(rtc_snapshot >> 32);
  }
  const uint32_t mem_addr = static_cast<uint32_t>(raddr - start_pc) & ~0x3u;

  if(src_type == MEM_SRC_INST || src_type == MEM_SRC_DATA) {
    Assert(mem_addr + 4 <= MEM_SIZE, "pmem_read out of bounds at address 0x%x", raddr);
  }
  else {
    if(src_type != MEM_SRC_DEBUG) {
      printf(ANSI_FG_RED "pmem_read invalid src_type %d at address 0x%x" ANSI_NONE "\n", src_type, raddr);
      assert(false);
    }
    // assert(src_type == MEM_SRC_DEBUG);
    if(mem_addr + 4 > MEM_SIZE){
      printf(ANSI_FG_RED "pmem_read out of bounds at address 0x%x" ANSI_NONE "\n", raddr);
      assert(false);
    }
  }

  return *reinterpret_cast<int*>(pmem + mem_addr);
}

extern "C" void pmem_write(uint32_t waddr, int wdata, uint8_t wmask, uint8_t src_type) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  if(waddr == 0x10000000) { // 串口
    putchar(wdata & 0xFF);
    return;
  }
  const uint32_t mem_addr = static_cast<uint32_t>(waddr - start_pc) & ~0x3u;

  assert(src_type != MEM_SRC_INST);
  if(src_type == MEM_SRC_DATA) {
    Assert(mem_addr + 4 <= MEM_SIZE, "pmem_write out of bounds at address 0x%x", waddr);
  }
  else {
    assert(src_type == MEM_SRC_DEBUG);
    if(mem_addr + 4 > MEM_SIZE){
      printf(ANSI_FG_RED "pmem_write out of bounds at address 0x%x" ANSI_NONE "\n", waddr);
      assert(false);
    }
  }

  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;
  int *p = reinterpret_cast<int *>(pmem + mem_addr);
  *p = (*p & ~byte_mask) | (wdata & byte_mask);
}

extern "C" void itrace(uint32_t pc, uint32_t inst) {
#ifdef CONFIG_ITRACE
  s.inst = inst;
  s.pc = pc;
#endif
}

extern "C" void iringbuf_before_ifetch(uint32_t pc) {
#ifdef CONFIG_ITRACE
  iringbuf_push_pc(pc);
#endif
}

extern "C" void iringbuf_after_ifetch(uint32_t pc, uint32_t inst) {
#ifdef CONFIG_ITRACE
  iringbuf_backfill_inst(pc, inst);
#endif
}
