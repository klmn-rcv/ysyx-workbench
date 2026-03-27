BUILD_DIR = ./build

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

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	verilator -Wall -Wno-fatal --cc -f build/filelist.f -Ibuild --top-module Top --trace --exe csrc/sim_main.cpp --build -j 0 && ./obj_dir/VTop

.PHONY: test verilog help reformat checkformat clean sim

-include ../Makefile
