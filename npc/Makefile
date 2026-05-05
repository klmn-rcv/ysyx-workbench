BUILD_DIR = ./build
YOSYS_STA_DIR ?= ../yosys-sta
NPC_CONFIG_H := $(abspath include/config.h)
SOC_VERILOG := $(SOC_HOME)/build/ysyxSoCFull.v

IMG ?=
LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
VERILOG_STAMP = $(BUILD_DIR)/.verilog.stamp

TOP_MODULE = ysyxSoCFull

CHISEL_SRCS := $(shell find src -name '*.scala' | sort)
VERILOG_RESOURCES := $(shell find resources -name '*.sv' | sort)
GENERATED_VERILOG_SRCS := $(sort $(wildcard $(BUILD_DIR)/*.sv))
VERILOG_SRCS := $(GENERATED_VERILOG_SRCS) $(shell find $(SOC_HOME)/perip -name '*.v' | sort) $(SOC_VERILOG)
VERILOG_DEPS := $(CHISEL_SRCS) $(VERILOG_RESOURCES) $(VERILOG_SRCS) Makefile

VERILATOR_FLAGS += -Wall -Wno-fatal --cc -Ibuild
VERILATOR_FLAGS += -I$(SOC_HOME)/perip/uart16550/rtl
VERILATOR_FLAGS += -I$(SOC_HOME)/perip/spi/rtl
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += --top-module $(TOP_MODULE) --trace  --autoflush

CSRCS := $(wildcard csrc/*.cpp)
CFLAGS += -I../include
CFLAGS += -I../tools/capstone/repo/include
LDFLAGS += -lreadline
LDFLAGS += -ldl
ARGS ?=

SYN_RTL_FILES = $(sort $(wildcard $(BUILD_DIR)/*.sv))

test:
	mill -i test

$(SOC_VERILOG): $(NPC_CONFIG_H)
	$(MAKE) -B -C $(SOC_HOME) verilog

$(VERILOG_STAMP): $(VERILOG_DEPS)
	$(call git_commit, "generate verilog")
	rm -rf $(BUILD_DIR)
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
	verilator $(VERILATOR_FLAGS) \
			$(VERILOG_SRCS) \
			--exe $(CSRCS) \
			-CFLAGS "$(CFLAGS)" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && ./obj_dir/V$(TOP_MODULE) $(ARGS) $(IMG)


gdb: $(VERILOG_STAMP) $(LIBCAPSTONE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) \
			$(VERILOG_SRCS) \
			--exe $(CSRCS) \
			-CFLAGS "$(CFLAGS) -g" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && gdb --args ./obj_dir/V$(TOP_MODULE) $(ARGS) $(IMG)

syn: $(VERILOG_STAMP)
	$(MAKE) -C $(YOSYS_STA_DIR) sta \
		DESIGN=$(TOP_MODULE) \
		CLK_PORT_NAME=clock \
		RTL_FILES="$(abspath $(SYN_RTL_FILES))"


.PHONY: test verilog syn help reformat checkformat clean sim

-include ../Makefile
