#include <chrono>
#include <cstdint>
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

extern "C" int pmem_read(uint32_t raddr, mem_read_t read_type) {
#if defined (CONFIG_MTRACE) || defined (CONFIG_DTRACE)
  const char *str_type[] = { "inst", "data", "debug" };
#endif
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  if (raddr == 0x10000004) { // 时钟低32位
    IFDEF(CONFIG_DTRACE, _Log("[dtrace] rtc read: addr = " FMT_PADDR ", low 32 bits\n", raddr));
    return static_cast<uint32_t>(rtc_snapshot);
  }
  if (raddr == 0x10000008) { // 时钟高32位
    IFDEF(CONFIG_DTRACE, _Log("[dtrace] rtc read: addr = " FMT_PADDR ", high 32 bits\n", raddr));
    auto now = std::chrono::steady_clock::now();
    rtc_snapshot = std::chrono::duration_cast<std::chrono::microseconds>(now - boot_time).count();
    return static_cast<uint32_t>(rtc_snapshot >> 32);
  }

  const uint32_t mem_addr = static_cast<uint32_t>(raddr - start_pc) & ~0x3u;

  if(read_type == MEM_READ_INST || read_type == MEM_READ_DATA) {
    Assert(mem_addr + 4 <= MEM_SIZE, "pmem_read out of bounds at address 0x%x", raddr);
  }
  else {
    if(read_type != MEM_READ_DEBUG) {
      printf(ANSI_FG_RED "pmem_read invalid read_type %d at address 0x%x" ANSI_NONE "\n", read_type, raddr);
      assert(false);
    }
    // assert(read_type == MEM_READ_DEBUG);
    if(mem_addr + 4 > MEM_SIZE){
      printf(ANSI_FG_RED "pmem_read out of bounds at address 0x%x" ANSI_NONE "\n", raddr);
      assert(false);
    }
  }

  IFDEF(CONFIG_MTRACE, _Log("[mtrace] pmem_read (%s): addr = " FMT_PADDR "\n", str_type[read_type], raddr));

  return *reinterpret_cast<int*>(pmem + mem_addr);
}

extern "C" void pmem_write(uint32_t waddr, int wdata, uint8_t wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;

  if(waddr == 0x10000000) { // 串口
    uint8_t uart_data = wdata & byte_mask & 0xFF;
    IFDEF(CONFIG_DTRACE, _Log("[dtrace] uart write: addr = " FMT_PADDR ", data = 0x%02x\n", waddr, uart_data));
    putchar(uart_data);
    return;
  }

  const uint32_t mem_addr = static_cast<uint32_t>(waddr - start_pc) & ~0x3u;
  Assert(mem_addr + 4 <= MEM_SIZE, "pmem_write out of bounds at address 0x%x", waddr);

  uint32_t *p = reinterpret_cast<uint32_t *>(pmem + mem_addr);
  uint32_t pmem_data = (*p & ~byte_mask) | (wdata & byte_mask);
  IFDEF(CONFIG_MTRACE, _Log("[mtrace] pmem_write: addr = " FMT_PADDR ", data = 0x%08x\n", waddr, pmem_data));

  *p = pmem_data;
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
