BUILD_DIR = ./build

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


.PHONY: test verilog help reformat checkformat clean sim

-include ../Makefile
