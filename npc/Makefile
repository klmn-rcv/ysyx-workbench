MODE ?= ysyxsoc
YOSYS_STA_DIR ?= ../yosys-sta
NXDC_FILES = constr/top.nxdc
NPC_CONFIG_H := $(abspath include/config.h)
SOC_VERILOG := $(SOC_HOME)/build/ysyxSoCFull.v

IMG ?=
LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
ARGS ?=

ifeq ($(MODE),npc)
BUILD_DIR = ./build-npc
TOP_MODULE = Top
SIM_MODE_CFLAGS = -DSIM_MODE_NPC=1
SIM_DEPS =
SIM_CSRCS =
SIM_LINK_INPUTS =
SIM_VERILOG_INPUTS = -f $(BUILD_DIR)/filelist.f
POST_PROCESS_VERILOG = :
SYN_TOP = Top
SYN_RTL_FILES = $(sort $(wildcard $(BUILD_DIR)/*.sv))
else ifeq ($(MODE),ysyxsoc)
BUILD_DIR = ./build
TOP_MODULE = ysyxSoCFull
SIM_MODE_CFLAGS = -DSIM_MODE_YSYXSOC=1
PERIP_VERILOG_SRCS := $(shell find $(SOC_HOME)/perip -name '*.v' | sort)
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
SIM_CSRCS = $(SRC_AUTO_BIND)
SIM_VERILOG_INPUTS = $(BUILD_DIR)/ysyx_26050145.sv $(PERIP_VERILOG_SRCS) $(SOC_VERILOG)
POST_PROCESS_VERILOG = tmp="$(BUILD_DIR)/ysyx_26050145.sv.tmp"; rm -f "$$tmp"; while IFS= read -r f; do f=$$(printf '%s\n' "$$f" | sed 's|^\./||'); [ -z "$$f" ] || { cat "$(BUILD_DIR)/$$f" >> "$$tmp"; printf '\n' >> "$$tmp"; }; done < "$(BUILD_DIR)/filelist.f"; mv "$$tmp" "$(BUILD_DIR)/ysyx_26050145.sv"
SYN_TOP = ysyx_26050145
SYN_RTL_FILES = $(BUILD_DIR)/ysyx_26050145.sv

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
SIM_DEPS = $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE) $(SOC_VERILOG)
SIM_LINK_INPUTS = $(NVBOARD_ARCHIVE)
else
$(error unknown MODE '$(MODE)', expected npc or ysyxsoc)
endif

VERILOG_STAMP = $(BUILD_DIR)/.verilog.stamp

CHISEL_SRCS := $(shell find src -name '*.scala' | sort)
VERILOG_RESOURCES := $(shell find resources -name '*.sv' | sort)
VERILOG_DEPS := $(CHISEL_SRCS) $(VERILOG_RESOURCES) Makefile

VERILATOR_FLAGS += -Wall -Wno-fatal --cc -I$(BUILD_DIR)
ifeq ($(MODE),ysyxsoc)
VERILATOR_FLAGS += -I$(SOC_HOME)/perip/uart16550/rtl
VERILATOR_FLAGS += -I$(SOC_HOME)/perip/spi/rtl
endif
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += --top-module $(TOP_MODULE) --trace --autoflush

CSRCS = $(wildcard csrc/*.cpp) $(SIM_CSRCS)
INC_PATH += ../include
INC_PATH += ../tools/capstone/repo/include
LDFLAGS += -lreadline
LDFLAGS += -ldl

INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS)
CFLAGS += $(SIM_MODE_CFLAGS)
CFLAGS += -DTOP_CLASS=V$(TOP_MODULE)

ifeq ($(MODE),ysyxsoc)
# constraint file
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
endif

test:
	mill -i test

$(SOC_VERILOG): $(NPC_CONFIG_H)
	$(MAKE) -B -C $(SOC_HOME) verilog

$(VERILOG_STAMP): $(VERILOG_DEPS) $(if $(filter ysyxsoc,$(MODE)),$(SOC_VERILOG))
	$(call git_commit, "generate verilog")
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	NPC_ELAB_MODE=$(MODE) mill -i runMain Elaborate --target-dir $(BUILD_DIR)
	$(POST_PROCESS_VERILOG)
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
	-rm -rf $(BUILD_DIR) obj_dir

$(LIBCAPSTONE):
	$(MAKE) -C tools/capstone

sim: $(VERILOG_STAMP) $(LIBCAPSTONE) $(SIM_DEPS)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) \
			$(SIM_VERILOG_INPUTS) \
			$(SIM_LINK_INPUTS) \
			--exe $(CSRCS) \
			-CFLAGS "$(CFLAGS)" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && ./obj_dir/V$(TOP_MODULE) $(ARGS) $(IMG)

gdb: $(VERILOG_STAMP) $(LIBCAPSTONE) $(SIM_DEPS)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) \
			$(SIM_VERILOG_INPUTS) \
			$(SIM_LINK_INPUTS) \
			--exe $(CSRCS) \
			-CFLAGS "$(CFLAGS) -g" \
			-LDFLAGS "$(LDFLAGS)" \
			--build -j 0 && gdb --args ./obj_dir/V$(TOP_MODULE) $(ARGS) $(IMG)

syn: $(VERILOG_STAMP)
	$(MAKE) -C $(YOSYS_STA_DIR) sta \
		DESIGN=$(SYN_TOP) \
		CLK_PORT_NAME=clock \
		RTL_FILES="$(abspath $(SYN_RTL_FILES))"

.PHONY: test verilog syn help reformat checkformat clean sim gdb

-include ../Makefile
