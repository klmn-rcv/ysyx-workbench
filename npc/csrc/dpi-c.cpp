#include <chrono>
#include <cstdint>
#include "common.h"
#include "cpu-exec.h"
#include "dpi-c.h"
#include "sim.h"
#include "state.h"
#include "debug.h"
#ifdef CONFIG_DIFFTEST
#include "difftest.h"
#endif

extern char mrom[];  // mask rom

extern char pmem[];  // memory

static uint64_t rtc_snapshot = 0; // 防止直接读系统时间可能导致的高32位和低32位不一致
static auto boot_time = std::chrono::steady_clock::now();
static const uint32_t start_pc = 0x20000000;
// static const uint32_t start_pmem = 0x80000000;

extern "C" void sim_halt(int exit_code, uint32_t exit_pc) {
  npc_state.state = NPC_END;
  npc_state.halt_ret = exit_code;
  npc_state.halt_pc = exit_pc;
}

extern "C" int pmem_read(uint32_t raddr, mem_read_t read_type) {//, uint8_t *need_skip_ref) {
#if defined (CONFIG_MTRACE) || defined (CONFIG_DTRACE)
  const char *str_type[] = { "inst", "data", "debug" };
#endif
  // *need_skip_ref = 0;
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  // if (raddr == 0x10000004) { // 时钟低32位
  //   // IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
  //   *need_skip_ref = 1;

  //   IFDEF(CONFIG_DTRACE, _Log("[dtrace] rtc read: addr = " FMT_PADDR ", low 32 bits\n", raddr));
  //   return static_cast<uint32_t>(rtc_snapshot);
  // }
  // if (raddr == 0x10000008) { // 时钟高32位
  //   // IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
  //   *need_skip_ref = 1;

  //   IFDEF(CONFIG_DTRACE, _Log("[dtrace] rtc read: addr = " FMT_PADDR ", high 32 bits\n", raddr));
  //   auto now = std::chrono::steady_clock::now();
  //   rtc_snapshot = std::chrono::duration_cast<std::chrono::microseconds>(now - boot_time).count();
  //   return static_cast<uint32_t>(rtc_snapshot >> 32);
  // }

  const uint32_t mem_addr = static_cast<uint32_t>(raddr - start_pc) & ~0x3u;

  if(read_type == MEM_READ_INST || read_type == MEM_READ_DATA) {
    Assert(mem_addr + 4 <= MEM_SIZE, "pmem_read out of bounds at address 0x%x, read type is %d", raddr, read_type);
  }
  else {
    if(read_type != MEM_READ_DEBUG) {
      printf(ANSI_FG_RED "pmem_read invalid read_type %d at address 0x%x" ANSI_NONE "\n", read_type, raddr);
      IFDEF(CONFIG_GEN_WAVE, end_wave());
      assert(false);
    }
    // assert(read_type == MEM_READ_DEBUG);
    if(mem_addr + 4 > MEM_SIZE){
      printf(ANSI_FG_RED "pmem_read out of bounds at address 0x%x, read type is %d" ANSI_NONE "\n", raddr, read_type);
      IFDEF(CONFIG_GEN_WAVE, end_wave());
      assert(false);
    }
  }

  IFDEF(CONFIG_MTRACE, _Log("[mtrace] pmem_read (%s): addr = " FMT_PADDR "\n", str_type[read_type], raddr));

  return *reinterpret_cast<int*>(pmem + mem_addr);
}

extern "C" void pmem_write(uint32_t waddr, int wdata, uint8_t wmask) {//, uint8_t *need_skip_ref) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  wmask &= 0xf;  // 长度为4位的掩码
  uint32_t byte_mask = 0;
  if (wmask & 0x1) byte_mask |= 0x000000FF;
  if (wmask & 0x2) byte_mask |= 0x0000FF00;
  if (wmask & 0x4) byte_mask |= 0x00FF0000;
  if (wmask & 0x8) byte_mask |= 0xFF000000;

  // *need_skip_ref = 0;
  // if(waddr == 0x10000000) { // 串口
  //   // IFDEF(CONFIG_DIFFTEST, difftest_skip_ref()) ;
  //   *need_skip_ref = 1;
  //
  //   uint8_t uart_data = wdata & byte_mask & 0xFF;
  //   IFDEF(CONFIG_DTRACE, _Log("[dtrace] uart write: addr = " FMT_PADDR ", data = 0x%02x\n", waddr, uart_data));
  //   fputc(uart_data, stderr);
  //   return;
  // }

  const uint32_t mem_addr = static_cast<uint32_t>(waddr - start_pc) & ~0x3u;
  Assert(mem_addr + 4 <= MEM_SIZE, "pmem_write out of bounds at address 0x%x", waddr);

  uint32_t *p = reinterpret_cast<uint32_t *>(pmem + mem_addr);
  uint32_t pmem_data = (*p & ~byte_mask) | (wdata & byte_mask);
  IFDEF(CONFIG_MTRACE, _Log("[mtrace] pmem_write: addr = " FMT_PADDR ", data = 0x%08x\n", waddr, pmem_data));

  *p = pmem_data;
}

// 没有定义CONFIG_ITRACE时，这个函数也会记录inst和pc，因为要维护s给difftest使用
extern "C" void itrace(uint32_t pc, uint32_t inst, uint32_t dnpc, uint8_t need_skip_ref) {
  // printf("[itrace] DEBUG: submit pc = 0x%08x, now g_nr_commit is %" PRIu64 "\n", pc, g_nr_commit + 1);
  submit.inst = inst;
  submit.pc = pc;
  submit.dnpc = dnpc;
  submit.need_skip_ref = need_skip_ref;
  g_nr_commit++;
}

extern "C" void iringbuf_reset(void) {
#ifndef CONFIG_ITRACE
  iringbuf_clear_all();
#endif
}

extern "C" void iringbuf_before_ifetch(uint32_t pc) {
#ifdef CONFIG_ITRACE
  // printf("DEBUG: iringbuf_push_pc called with pc = 0x%08x\n", pc);
  iringbuf_push_pc(pc);
#endif
}

extern "C" void iringbuf_after_ifetch(uint32_t pc, uint32_t inst) {
#ifdef CONFIG_ITRACE
  // printf("DEBUG: iringbuf_backfill_inst called with pc = 0x%08x, inst = 0x%08x\n", pc, inst);
  iringbuf_backfill_inst(pc, inst);
#endif
}

extern "C" void iringbuf_flush_after_ifetch(uint32_t pc) {
#ifdef CONFIG_ITRACE
  // printf("DEBUG: iringbuf_flush_refill_pos called with pc = 0x%08x\n", pc);
  iringbuf_flush_refill_pos(pc);
#endif
}

extern "C" void ftrace(uint32_t pc, uint32_t target_pc, bool is_jalr, int rd, int rs1, int imm) {
#ifdef CONFIG_FTRACE
  static int call_depth = 0;
  char func_name[128];
  bool is_func_entry = false;
  if(is_jalr && rd == 0 && (rs1 == 1 || rs1 == 5) && imm == 0) { // ret
    call_depth--;
    assert(call_depth >= 0); // sanity check
    if(func_array_search(func_name, pc, &is_func_entry)) {
      _Log("[ftrace] 0x%08x: %*sret [%s]\n", pc, call_depth * 2, "", func_name);
    }
    else {
      _Log("[ftrace] 0x%08x: %*sret [unknown]\n", pc, call_depth * 2, "");
    }
  }
  else if (func_array_search(func_name, target_pc, &is_func_entry) && is_func_entry) {  // call
    if((!is_jalr && rd == 0) || (is_jalr && rd == 0)) { // jal/jalr with rd = 0 is (likely) a tail call, so do not increase call_depth
      _Log("[ftrace] 0x%08x: %*stailcall [%s@0x%08x]\n", pc, call_depth * 2, "", func_name, target_pc);
    }
    else {
      _Log("[ftrace] 0x%08x: %*scall [%s@0x%08x]\n", pc, call_depth * 2, "", func_name, target_pc);
      call_depth++;
    }
  }
#endif
}

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) {
  // *data = 0x00100073;  // ebreak
  // static int times = 0;
  // times++;
  // if(times < 10) {  // 只打印前10次调用
  //   printf("DEBUG: mrom_read called with addr = 0x%08x, mrom[addr - start_pc] = 0x%08x\n", addr, static_cast<uint32_t>(mrom[addr - start_pc]));
  // }
  const uint32_t mrom_addr = addr - start_pc;
  Assert(mrom_addr + 4 <= MROM_SIZE, "mrom_read out of bounds at address 0x%x", addr);
  *data = *reinterpret_cast<int32_t *>(mrom + mrom_addr);
  IFDEF(CONFIG_MTRACE, _Log("[mtrace] mrom_read: addr = 0x%08x, data = 0x%08x\n", addr, *data));
}
