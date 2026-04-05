BUILD_DIR = ./build

IMG ?=

test:
	mill -i test

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i runMain Elaborate --target-dir $(BUILD_DIR)

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

CSRCS := $(wildcard csrc/*.cpp)

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall -Wno-fatal --cc -f build/filelist.f -Ibuild \
			--top-module Top --trace --exe $(CSRCS) \
			-CFLAGS "-I../include" \
			-LDFLAGS "-lreadline" \
			--build -j 0 && ./obj_dir/VTop $(IMG)

.PHONY: test verilog help reformat checkformat clean sim

-include ../Makefile
