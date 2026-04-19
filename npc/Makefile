BUILD_DIR = ./build
YOSYS_STA_DIR ?= ../yosys-sta

IMG ?=
LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
VERILOG_STAMP = $(BUILD_DIR)/.verilog.stamp

CHISEL_SRCS := $(shell find src -name '*.scala' | sort)
VERILOG_RESOURCES := $(shell find resources -name '*.sv' | sort)
VERILOG_DEPS := $(CHISEL_SRCS) $(VERILOG_RESOURCES) Makefile

CSRCS := $(wildcard csrc/*.cpp)
CFLAGS += -I../include
CFLAGS += -I../tools/capstone/repo/include
LDFLAGS += -lreadline
LDFLAGS += -ldl
ARGS ?=

SYN_RTL_FILES = $(sort $(wildcard $(BUILD_DIR)/*.sv))

test:
	mill -i test

$(VERILOG_STAMP): $(VERILOG_DEPS)
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i runMain Elaborate --target-dir $(BUILD_DIR)
	touch $(VERILOG_STAMP)

verilog: $(VERILOG_STAMP)

help:
	mill -i runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

bsp:
	mill -i mill.bsp.BSP/install

idea:
	mill -i mill.idea.GenIdea/idea

clean:
	-rm -rf $(BUILD_DIR)

$(LIBCAPSTONE):
	$(MAKE) -C tools/capstone

sim: $(VERILOG_STAMP) $(LIBCAPSTONE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall -Wno-fatal --cc -f build/filelist.f -Ibuild \
			--top-module Top --trace --exe $(CSRCS) \
			-CFLAGS "$(CFLAGS)" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && ./obj_dir/VTop $(ARGS) $(IMG)


gdb: $(VERILOG_STAMP) $(LIBCAPSTONE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall -Wno-fatal --cc -f build/filelist.f -Ibuild \
			--top-module Top --trace --exe $(CSRCS) \
			-CFLAGS "$(CFLAGS) -g" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && gdb --args ./obj_dir/VTop $(ARGS) $(IMG)

syn: $(VERILOG_STAMP)
	$(MAKE) -C $(YOSYS_STA_DIR) sta \
		DESIGN=Top \
		CLK_PORT_NAME=clock \
		RTL_FILES="$(abspath $(SYN_RTL_FILES))"


.PHONY: test verilog syn help reformat checkformat clean sim

-include ../Makefile
