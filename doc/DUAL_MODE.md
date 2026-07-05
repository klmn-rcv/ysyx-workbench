# riscv32e-npc / riscv32e-ysyxsoc 双模式修复方案

这份文档只说明怎么修，不直接改源码。目标是让同一套 CPU 同时支持：

- `riscv32e-npc`：裸 NPC 仿真，程序第一条指令在 `0x80000000`。
- `riscv32e-ysyxsoc`：接入 ysyxSoC 仿真，程序从 SoC flash `0x30000000` 启动。

核心结论：

```text
riscv32e-npc:
  reset PC = 0x80000000
  IMG 加载到 pmem
  Verilator 顶层 = Top
  Top = ysyx_26050145 + 裸 NPC 仿真 AXI 设备

riscv32e-ysyxsoc:
  reset PC = 0x30000000
  IMG 加载到 flash
  Verilator 顶层 = ysyxSoCFull
  ysyx_26050145 继续作为 SoC 内的 CPU 顶层
```

裸 NPC 模式不要使用 `0x30000000` trampoline 作为主方案。`0x30000000` 是 ysyxSoC flash 地址，在不接 SoC 的 `riscv32e-npc` 里没有自然语义。

## 历史证据

接入 ysyxSoC 的提交是：

```bash
git show --name-status --oneline e088620 -- npc/src/top.scala npc/Makefile npc/csrc/sim_main.cpp npc/csrc/dpi-c.cpp npc/include/sim.h
```

结果显示 `e088620 feat(npc): integrate NPC into ysyxSoC` 删除了旧的裸 NPC 顶层：

```text
D npc/src/top.scala
M npc/Makefile
M npc/csrc/sim_main.cpp
M npc/csrc/dpi-c.cpp
M npc/include/sim.h
```

接入 SoC 前的版本 `e07c64c` 中：

```bash
git show e07c64c:npc/src/IFU.scala | rg -n 'RegEnable|80000000|30000000'
```

旧版 IFU reset PC 是：

```scala
val pc = RegEnable(dnpc, "h80000000".U(32.W), io.out.fire)
```

旧版 `npc/src/top.scala` 的结构是：

```text
Top
 ├── CPU
 ├── AXI4LiteArbiter
 ├── Xbar
 ├── Mem
 ├── UART
 └── CLINT
```

旧版 `npc/Makefile` 用：

```makefile
--top-module Top
-f build/filelist.f
./obj_dir/VTop $(ARGS) $(IMG)
```

旧版 `npc/csrc/sim_main.cpp` 里：

```cpp
VTop* top = new VTop;
char pmem[MEM_SIZE];
std::fread(pmem, 1, MEM_SIZE, fp);
```

旧版 `npc/csrc/dpi-c.cpp` 里：

```cpp
static const uint32_t start_pc = 0x80000000;
```

所以裸 NPC 的历史实现语义就是 `0x80000000`，不是 `0x30000000`。

## 当前代码的问题

当前代码已经切到 SoC 语义：

- `/home/jihonglu/ysyx-workbench/npc/src/IFU.scala` 固定：

```scala
val pc = RegEnable(dnpc, "h30000000".U(32.W), io.out.fire)
```

- `/home/jihonglu/ysyx-workbench/npc/src/ysyx_26050145.scala` 里 `ysyx_26050145` 没有 reset vector 参数。
- `/home/jihonglu/ysyx-workbench/npc/Makefile` 固定：

```makefile
TOP_MODULE = ysyxSoCFull
```

- `/home/jihonglu/ysyx-workbench/npc/csrc/sim_main.cpp` 固定实例化 `VysyxSoCFull`，并把镜像加载到 `flash`。
- `/home/jihonglu/ysyx-workbench/npc/csrc/dpi-c.cpp` 固定用 `FLASH_BASE` 作为普通 `pmem_read/pmem_write` 的基址。
- `/home/jihonglu/ysyx-workbench/npc/csrc/dut.cpp` 的 difftest reset vector 固定是 `FLASH_BASE`，并把 `flash` 拷给参考机。
- `/home/jihonglu/ysyx-workbench/npc/csrc/reg.cpp` 硬编码了 `VysyxSoCFull` 的 Verilator 内部层级。
- `/home/jihonglu/ysyx-workbench/abstract-machine/scripts/platform/npc.mk` 明确把裸 NPC 程序链接到：

```makefile
--defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
```

也就是说，AM 的 `riscv32e-npc` 已经要求程序在 `0x80000000`，但当前 NPC RTL/C++ 仿真框架按 SoC flash `0x30000000` 跑。

## 修复总览

需要做五组修改：

```text
1. RTL reset vector 参数化
2. 恢复裸 NPC 仿真顶层 Top
3. 增加裸 NPC 用的 AXI4 平台设备模型
4. Makefile / AM 脚本按 MODE 选择 npc 或 ysyxsoc
5. C++ 仿真框架按 MODE 选择顶层、镜像加载、DPI 基址、difftest、寄存器层级
```

推荐模式名：

```makefile
MODE ?= ysyxsoc
```

其中：

```text
MODE=ysyxsoc  -> 当前 SoC 仿真
MODE=npc      -> 裸 NPC 仿真
```

## 1. RTL reset vector 参数化

修改 `/home/jihonglu/ysyx-workbench/npc/src/IFU.scala`。

当前：

```scala
class IFU extends Module with HasYsyxModuleName {
```

改成：

```scala
class IFU(resetVector: Long = 0x30000000L) extends Module with HasYsyxModuleName {
```

当前：

```scala
val pc = RegEnable(dnpc, "h30000000".U(32.W), io.out.fire)
```

改成：

```scala
val pc = RegEnable(dnpc, resetVector.U(32.W), io.out.fire)
```

修改 `/home/jihonglu/ysyx-workbench/npc/src/cpu.scala`。

当前：

```scala
class CPU extends Module with HasYsyxModuleName {
```

改成：

```scala
class CPU(resetVector: Long = 0x30000000L) extends Module with HasYsyxModuleName {
```

当前：

```scala
val ifu = Module(new IFU)
```

改成：

```scala
val ifu = Module(new IFU(resetVector))
```

修改 `/home/jihonglu/ysyx-workbench/npc/src/ysyx_26050145.scala`。

当前：

```scala
class ysyx_26050145 extends Module {
```

改成：

```scala
class ysyx_26050145(resetVector: Long = 0x30000000L) extends Module {
```

当前：

```scala
val core = Module(new CPU)
```

改成：

```scala
val core = Module(new CPU(resetVector))
```

这样默认行为仍然是 SoC 版 `0x30000000`，裸 NPC 顶层可以显式传 `0x80000000`。

## 2. 恢复裸 NPC 顶层 Top

新增 `/home/jihonglu/ysyx-workbench/npc/src/top.scala`。

旧版 `Top` 直接实例化 `CPU + Mem + UART + CLINT`。新的裸 NPC `Top` 仍然按这个结构写，只是把旧版 AXI4Lite 总线升级成当前 AXI4：

```scala
package cpu

import chisel3._

class Top extends Module {
  val core = Module(new CPU(resetVector = 0x80000000L))
  val arbiter = Module(new AXI4Arbiter)
  val xbar = Module(new npc.Xbar)
  val mem = Module(new npc.Mem)
  val uart = Module(new npc.UART)
  val clint = Module(new npc.CLINT)

  core.io.inst_mem_axi <> arbiter.io.if_iw
  core.io.data_mem_axi <> arbiter.io.ls_lsw
  core.io.data_mem_r_need_skip_ref := arbiter.io.ls_lsw_r_need_skip_ref
  core.io.data_mem_b_need_skip_ref := arbiter.io.ls_lsw_b_need_skip_ref

  arbiter.io.xbar <> xbar.io.in
  arbiter.io.ls_lsw_load := core.io.ls_lsw_load
  arbiter.io.xbar_r_need_skip_ref := xbar.io.r_need_skip_ref
  arbiter.io.xbar_b_need_skip_ref := xbar.io.b_need_skip_ref

  xbar.io.mem <> mem.axi
  xbar.io.uart <> uart.io.axi
  xbar.io.clint <> clint.io.axi
  xbar.io.uart_b_need_skip_ref := uart.io.b_need_skip_ref
  xbar.io.clint_r_need_skip_ref := clint.io.r_need_skip_ref

  mem.clk := clock
  mem.rst := reset.asBool
}
```

`Top` 是 Verilator 裸 NPC 仿真的顶层，不用于流片，不传给 ysyxSoC。

## 3. 增加裸 NPC 用的 AXI4 平台设备模型

这部分不是说历史上完全没有 Mem/UART/CLINT。`riscv32e-npc` 本来就应该有这些平台设备。当前缺的是一套“按当前 AXI4 接口实现的裸 NPC 平台设备模型”。

历史版本 `e07c64c` 有这些文件：

```text
npc/src/top.scala
npc/resources/Mem.sv
npc/resources/LFSR.sv
npc/src/UART.scala
npc/src/CLINT.scala
```

但它们在接入 SoC 的提交 `e088620` 里被删掉或改成了 SoC 版本：

```text
D npc/src/top.scala
D npc/resources/Mem.sv
D npc/resources/LFSR.sv
D npc/src/UART.scala
M npc/src/CLINT.scala
M npc/src/Xbar.scala
```

而且旧版 `Mem.sv` 接的是旧版 `AXI4Lite` 信号：

```text
axi_ar_araddr
axi_ar_arvalid
axi_ar_arready
axi_r_rdata
axi_r_rvalid
...
```

当前 `ysyx_26050145.io.master` 是完整 AXI4，多了这些关键信号：

```text
arid / awid
arlen / awlen
arsize / awsize
arburst / awburst
rid / bid
rlast
wlast
```

所以不能把旧版 `Mem.sv` 原样拷回来直接用。可以复用旧版 `Mem.sv` 的状态机和 DPI-C 访存思路，但接口要升级到当前 AXI4，并且要补上裸 NPC 需要的 UART/timer 地址。

不推荐让裸 NPC 继续经过当前 `ysyx_26050145` 里的 SoC 版 `Xbar`。当前 `/home/jihonglu/ysyx-workbench/npc/src/Xbar.scala` 只把：

```text
0x80000000..0x803fffff
```

作为 PSRAM 地址转发给外部 `io.master`，但 `/home/jihonglu/ysyx-workbench/abstract-machine/am/src/riscv/npc/trm.c` 把裸 NPC PMEM 视为：

```text
0x80000000..0x87ffffff
```

如果沿用 SoC 版 `Xbar`，还要额外参数化地址表，容易把 SoC 平台语义混进裸 NPC。

推荐恢复旧版那种 CPU 级裸 NPC 顶层。

```text
Top
 ├── CPU(resetVector = 0x80000000)
 ├── AXI4Arbiter
 ├── Xbar
 ├── Mem
 ├── UART
 └── CLINT
```

意思是：裸 NPC 的 `Top` 不实例化当前 `ysyx_26050145`，而是像历史版本一样直接实例化 `CPU`，再自己接仲裁器、地址译码、内存、串口和 timer。

这更贴近旧版 `e07c64c` 的结构，也更自然地支持裸 NPC 的 `0x80000000..0x87ffffff` PMEM。当前 `cpu.Xbar` 和 `cpu.CLINT` 已经被 SoC 版占用，因此裸 NPC 版建议放到子包里保留历史短名字，例如：

```text
cpu.npc.Xbar
cpu.npc.Mem
cpu.npc.UART
cpu.npc.CLINT
```

这样不是给模块乱加 `Npc` 前缀，而是用 Scala 包名区分两个平台版本。`Top` 里写成：

```scala
val xbar = Module(new npc.Xbar)
val mem = Module(new npc.Mem)
val uart = Module(new npc.UART)
val clint = Module(new npc.CLINT)
```

这种结构需要把旧版 `Mem/UART/CLINT/Xbar` 从 AXI4Lite 升级到当前 AXI4，但不需要实现 AXI4 的复杂功能。当前 IFU/LSU 发出的访问都是单 beat：

```text
arlen = 0
awlen = 0
wlast = 1
```

所以升级接口的实际工作主要是：

```text
读请求：接收 arid/araddr/arsize，返回 rid/rdata/rresp/rlast
写请求：接收 awid/awaddr/awsize 和 wdata/wstrb/wlast，返回 bid/bresp
约束：assert arlen == 0，assert awlen == 0，assert wlast
```

不用实现 burst、多 outstanding、乱序返回、cache/coherency。

按历史结构拆成四个模块：

```text
Xbar:
  0x10000000            -> UART
  0x10000004/0x10000008 -> CLINT
  其他地址              -> Mem

Mem:
  读 0x80000000..0x87ffffff -> 调 DPI-C pmem_read(addr, MEM_READ_INST/DATA)
  写 0x80000000..0x87ffffff -> 调 DPI-C pmem_write(addr, data, wstrb)

UART:
  写 0x10000000 -> 输出字符

CLINT:
  读 0x10000004/0x10000008 -> 返回 timer 低/高 32 位
```

当前 AM 的裸 NPC timer 路径是：

```text
/home/jihonglu/ysyx-workbench/abstract-machine/am/src/riscv/npc/timer.c
  0x10000004
  0x10000008
```

所以裸 NPC 顶层必须支持这两个地址。

`Mem` 仍然按历史版本做成 Chisel `ExtModule` + SystemVerilog 资源文件，只是接口从 `AXI4Lite` 改成当前 `AXI4`。例如放在 `cpu.npc` 子包里：

```scala
package cpu.npc

import chisel3._
import cpu._

class Mem extends ExtModule {
  val clk = IO(Input(Clock()))
  val rst = IO(Input(Bool()))
  val axi = IO(Flipped(new AXI4(32, 32, 4)))

  addResource("/npc/Mem.sv")
}
```

对应新增资源文件：

```text
/home/jihonglu/ysyx-workbench/npc/resources/npc/Mem.sv
```

`Mem.sv` 里直接 import 现有 DPI-C：

```systemverilog
import "DPI-C" function int pmem_read(input int unsigned raddr, input byte unsigned read_type);
import "DPI-C" function void pmem_write(input int unsigned waddr, input int wdata, input byte unsigned wmask);
```

读指令时传 `0`，读数据时传 `1`。可以按 `arid == 0` 传 `0`，`arid == 1` 传 `1`，这样能保留 mtrace 分类。

`UART` 和 `CLINT` 可以用 Scala 写，直接从旧版 `UART.scala`、`CLINT.scala` 改接口即可。`CLINT` 的地址必须是裸 NPC 历史地址：

```text
0x10000004
0x10000008
```

不是当前 SoC 版的：

```text
0x0200bff8
0x0200bffc
```

实现时按单拍 AXI4 做，因为当前 IFU/LSU 发出的访问是单 beat：

```text
arlen = 0
awlen = 0
wlast = 1
```

读通道最小状态机：

```text
IDLE:
  arvalid && arready 时锁存 araddr/arid
  下一拍给 rvalid/rdata/rid/rlast

RESP:
  rvalid && rready 后回到 IDLE
```

写通道最小状态机：

```text
分别锁存 AW 和 W
两者都到达后执行写入
给 bvalid/bid
bvalid && bready 后回到 IDLE
```

## 4. Elaborate 按 MODE 生成不同顶层

修改 `/home/jihonglu/ysyx-workbench/npc/src/Elaborate.scala`。

当前固定生成：

```scala
circt.stage.ChiselStage.emitSystemVerilogFile(new cpu.ysyx_26050145(), args, firtoolOptions)
```

改成按环境变量选择：

```scala
val mode = sys.env.getOrElse("NPC_ELAB_MODE", "ysyxsoc")

val dut = mode match {
  case "ysyxsoc" => new cpu.ysyx_26050145(resetVector = 0x30000000L)
  case "npc"     => new cpu.Top
  case other     => throw new IllegalArgumentException(s"unknown NPC_ELAB_MODE: $other")
}

circt.stage.ChiselStage.emitSystemVerilogFile(dut, args, firtoolOptions)
```

推荐使用两个 build 目录，避免两个模式互相覆盖：

```text
MODE=ysyxsoc -> npc/build
MODE=npc     -> npc/build-npc
```

## 5. Makefile 按 MODE 分开

修改 `/home/jihonglu/ysyx-workbench/npc/Makefile`。

建议结构：

```makefile
MODE ?= ysyxsoc

ifeq ($(MODE),npc)
BUILD_DIR = ./build-npc
TOP_MODULE = Top
SIM_MODE_CFLAGS = -DSIM_MODE_NPC=1
SIM_DEPS =
SIM_CSRCS =
SIM_VERILOG_INPUTS = -f $(BUILD_DIR)/filelist.f
else
BUILD_DIR = ./build
TOP_MODULE = ysyxSoCFull
SIM_MODE_CFLAGS = -DSIM_MODE_YSYXSOC=1
SIM_DEPS = $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE) $(SOC_VERILOG)
SIM_CSRCS = $(SRC_AUTO_BIND)
SIM_VERILOG_INPUTS = $(BUILD_DIR)/ysyx_26050145.sv \
                     $(shell find $(SOC_HOME)/perip -name '*.v' | sort) \
                     $(SOC_VERILOG)
endif
```

`$(VERILOG_STAMP)` 里把环境变量传给 Elaborate：

```makefile
$(VERILOG_STAMP): $(VERILOG_DEPS)
	$(call git_commit, "generate verilog")
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	NPC_ELAB_MODE=$(MODE) mill -i runMain Elaborate --target-dir $(BUILD_DIR)
	$(POST_PROCESS_VERILOG)
	touch $(VERILOG_STAMP)
```

SoC/CI 模式需要把 `filelist.f` 中的生成文件合并成 `build/ysyx_26050145.sv`。否则 CI 的 STA 阶段只拿这个单文件时会缺子模块。

可以加：

```makefile
ifeq ($(MODE),ysyxsoc)
POST_PROCESS_VERILOG = \
	tmp="$(BUILD_DIR)/ysyx_26050145.sv.tmp"; \
	rm -f "$$tmp"; \
	while IFS= read -r f; do \
	  f="$${f#./}"; \
	  [ -z "$$f" ] || { cat "$(BUILD_DIR)/$$f" >> "$$tmp"; printf '\n' >> "$$tmp"; }; \
	done < "$(BUILD_DIR)/filelist.f"; \
	mv "$$tmp" "$(BUILD_DIR)/ysyx_26050145.sv";
else
POST_PROCESS_VERILOG =
endif
```

SoC 仿真时，Verilator 输入要用合并后的 `build/ysyx_26050145.sv`，不要再同时传 `build/*.sv` 或 `-f build/filelist.f`，否则会重复定义模块。

裸 NPC 仿真时，`build-npc` 不需要合并单文件，直接用：

```makefile
-f build-npc/filelist.f
```

`sim` 目标改成：

```makefile
CSRCS := $(wildcard csrc/*.cpp) $(SIM_CSRCS)
CFLAGS += $(SIM_MODE_CFLAGS)
CFLAGS += -DTOP_CLASS=V$(TOP_MODULE)
CFLAGS += -DTOP_HEADER=\"V$(TOP_MODULE).h\"

sim: $(VERILOG_STAMP) $(LIBCAPSTONE) $(SIM_DEPS)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) \
			$(SIM_VERILOG_INPUTS) \
			$(if $(filter ysyxsoc,$(MODE)),$(NVBOARD_ARCHIVE),) \
			--exe $(CSRCS) \
			-CFLAGS "$(CFLAGS)" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && ./obj_dir/V$(TOP_MODULE) $(ARGS) $(IMG)
```

`gdb` 目标同理。

## 6. AM 脚本传 MODE

修改 `/home/jihonglu/ysyx-workbench/abstract-machine/scripts/platform/npc.mk`。

当前：

```makefile
$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin ARGS="$(NPCARGS) --batch"
```

改成：

```makefile
$(MAKE) -C $(NPC_HOME) sim MODE=npc IMG=$(IMAGE).bin ARGS="$(NPCARGS) --batch"
```

`debug` 和 `gdb` 也加 `MODE=npc`。

修改 `/home/jihonglu/ysyx-workbench/abstract-machine/scripts/platform/ysyxsoc.mk`。

可以显式写：

```makefile
$(MAKE) -C $(NPC_HOME) sim MODE=ysyxsoc IMG=$(IMAGE).bin ARGS="$(NPCARGS) --batch"
```

`debug` 和 `gdb` 同理。即使 Makefile 默认是 `ysyxsoc`，显式传参更清楚。

## 7. C++ 顶层类型按 MODE 选择

修改 `/home/jihonglu/ysyx-workbench/npc/include/sim.h`。

当前：

```cpp
#include "VysyxSoCFull.h"
extern VysyxSoCFull* top;
```

改成：

```cpp
#include TOP_HEADER
extern TOP_CLASS* top;
```

修改 `/home/jihonglu/ysyx-workbench/npc/csrc/sim_main.cpp`。

当前：

```cpp
#include <nvboard.h>
VysyxSoCFull* top = new VysyxSoCFull;
void nvboard_bind_all_pins(TOP_NAME* top);
```

改成：

```cpp
#ifndef SIM_MODE_NPC
#include <nvboard.h>
void nvboard_bind_all_pins(TOP_CLASS* top);
#endif

TOP_CLASS* top = new TOP_CLASS;
```

NVBoard 初始化也只在 SoC 模式执行：

```cpp
#ifndef SIM_MODE_NPC
  nvboard_bind_all_pins(top);
  nvboard_init();
#endif
```

复位周期可以分开：

```cpp
#ifdef SIM_MODE_NPC
  const int reset_cycles = 2;
#else
  const int reset_cycles = 10;
#endif
```

循环里 `nvboard_update()` 也只在 SoC 模式调用。

## 8. 镜像加载按 MODE 选择

修改 `/home/jihonglu/ysyx-workbench/npc/csrc/sim_main.cpp` 的 `load_image()`。

裸 NPC：

```cpp
#ifdef SIM_MODE_NPC
  const long n = std::fread(pmem, 1, MEM_SIZE, fp);
  printf("[sim] loaded %ld bytes from %s to pmem\n", n, path);
#else
  const long n = std::fread(flash, 1, FLASH_SIZE, fp);
  printf("[sim] loaded %ld bytes from %s to flash\n", n, path);
#endif
```

这对应：

```text
riscv32e-npc     -> pmem @ 0x80000000
riscv32e-ysyxsoc -> flash @ 0x30000000
```

## 9. DPI-C 访存基址按 MODE 选择

修改 `/home/jihonglu/ysyx-workbench/npc/csrc/dpi-c.cpp`。

当前：

```cpp
static const uint32_t start_pc = FLASH_BASE;
```

改成：

```cpp
#ifdef SIM_MODE_NPC
static const uint32_t start_pc = MEM_BASE;
#else
static const uint32_t start_pc = FLASH_BASE;
#endif
```

另外，SoC 专用的 Verilator 内部结构头文件只在 SoC 模式 include：

```cpp
#ifndef SIM_MODE_NPC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull_sdramChisel.h"
#include "VysyxSoCFull_sdramChisel_2.h"
#include "VysyxSoCFull_bank_mem_4194304x16.h"
#endif
```

`debug_mem_read()` 里访问 SoC 内部 SRAM/SDRAM 的代码也只在 SoC 模式存在。裸 NPC 模式的 debug read 直接读 `pmem`：

```cpp
#ifdef SIM_MODE_NPC
static uint32_t debug_mem_read(uint32_t raddr) {
  const uint32_t aligned_addr = raddr & ~0x3u;
  const uint32_t mem_addr = aligned_addr - MEM_BASE;
  Assert(mem_addr + 4 <= MEM_SIZE, "debug_mem_read out of bounds at address 0x%x", raddr);
  return *reinterpret_cast<uint32_t *>(pmem + mem_addr);
}
#else
// 保留当前 SoC debug_mem_read()
#endif
```

`pmem_read()` 和 `pmem_write()` 继续使用 `start_pc`，就能同时覆盖两种模式。

## 10. difftest 初始化按 MODE 选择

修改 `/home/jihonglu/ysyx-workbench/npc/csrc/dut.cpp`。

当前：

```cpp
extern char flash[];
static const paddr_t RESET_VECTOR = FLASH_BASE;
ref_difftest_memcpy(RESET_VECTOR, flash, img_size, DIFFTEST_TO_REF);
cpu.pc = RESET_VECTOR;
```

改成：

```cpp
extern char flash[];
extern char pmem[];

#ifdef SIM_MODE_NPC
static const paddr_t RESET_VECTOR = MEM_BASE;
#else
static const paddr_t RESET_VECTOR = FLASH_BASE;
#endif
```

拷贝镜像时：

```cpp
#ifdef SIM_MODE_NPC
  ref_difftest_memcpy(RESET_VECTOR, pmem, img_size, DIFFTEST_TO_REF);
#else
  ref_difftest_memcpy(RESET_VECTOR, flash, img_size, DIFFTEST_TO_REF);
#endif
```

`cpu.pc = RESET_VECTOR;` 保持不变。

## 11. reg.cpp 按 MODE 选择 Verilator 层级

修改 `/home/jihonglu/ysyx-workbench/npc/csrc/reg.cpp`。

当前所有路径都是：

```cpp
top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core...
```

裸 NPC 顶层 `Top` 的路径会变成类似：

```cpp
top->rootp->Top__DOT__cpu__DOT__core...
```

具体名字以 Verilator 生成的 `obj_dir/VTop___024root.h` 为准。生成一次裸 NPC 后用：

```bash
rg -n "regfile_0|submit_dnpc|__DOT__core" /home/jihonglu/ysyx-workbench/npc/obj_dir/VTop___024root.h
```

然后给每个访问点加：

```cpp
#ifdef SIM_MODE_NPC
  return top->rootp->Top__DOT__cpu__DOT__core__DOT__...
#else
  return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__...
#endif
```

需要覆盖这些函数：

```text
get_gpr()
get_pc()
get_if_pc()
get_iw_pc()
get_id_pc()
get_ex_pc()
get_ls_pc()
get_lsw_pc()
get_wb_pc()
get_csr()
get_priv()
```

如果裸 NPC 初期只跑 batch，并且暂时关闭 `CONFIG_DIFFTEST`、`CONFIG_DEBUGPOINT`，`reg.cpp` 的完整适配可以稍后做。但只要要开 difftest，就必须把 `get_gpr()`、`get_pc()`、`get_csr()`、`get_priv()` 适配好。

## 12. 验证顺序

先验证 SoC 默认路径没有被破坏：

```bash
make -C /home/jihonglu/ysyx-workbench/npc clean
make -C /home/jihonglu/ysyx-workbench/npc verilog MODE=ysyxsoc
```

确认 SoC/CI 单文件存在：

```bash
test -f /home/jihonglu/ysyx-workbench/npc/build/ysyx_26050145.sv
rg -n '^module ' /home/jihonglu/ysyx-workbench/npc/build/ysyx_26050145.sv | head
```

验证裸 NPC 能生成 RTL：

```bash
make -C /home/jihonglu/ysyx-workbench/npc clean MODE=npc
make -C /home/jihonglu/ysyx-workbench/npc verilog MODE=npc
test -f /home/jihonglu/ysyx-workbench/npc/build-npc/Top.sv
```

验证 `riscv32e-npc`：

```bash
make -C /home/jihonglu/ysyx-workbench/am-kernels/tests/cpu-tests ARCH=riscv32e-npc ALL=dummy run
```

再跑一个带访存的测试：

```bash
make -C /home/jihonglu/ysyx-workbench/am-kernels/tests/cpu-tests ARCH=riscv32e-npc ALL=load-store run
```

再跑 SoC：

```bash
make -C /home/jihonglu/ysyx-workbench/am-kernels/tests/cpu-tests ARCH=riscv32e-ysyxsoc ALL=dummy run
```

如果 `cpu-tests` 的具体 `ALL` 名称和本地目录不一致，先看：

```bash
ls /home/jihonglu/ysyx-workbench/am-kernels/tests/cpu-tests/tests
```

## 最终应该达到的状态

`riscv32e-npc` 路径：

```text
am-kernels
  -> abstract-machine/scripts/platform/npc.mk
  -> make -C npc sim MODE=npc
  -> Verilator top = Top
  -> reset PC = 0x80000000
  -> image loaded to pmem
  -> AXI read/write handled by Xbar/Mem/UART/CLINT
```

`riscv32e-ysyxsoc` 路径：

```text
am-kernels
  -> abstract-machine/scripts/platform/ysyxsoc.mk
  -> make -C npc sim MODE=ysyxsoc
  -> Verilator top = ysyxSoCFull
  -> reset PC = 0x30000000
  -> image loaded to flash
  -> memory/peripheral handled by ysyxSoC
```

CI/STA 路径：

```text
make -C npc verilog
  -> 默认 MODE=ysyxsoc
  -> build/ysyx_26050145.sv 是自包含单文件
  -> STA 使用 ysyx_26050145，而不是 Top
```
