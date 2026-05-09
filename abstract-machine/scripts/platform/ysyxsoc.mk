AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker-ysyxsoc.ld
LDFLAGS   += --defsym=_mrom_base=0x20000000 --defsym=_mrom_size=0x1000 \
             --defsym=_sram_base=0x0f000000 --defsym=_sram_size=0x2000 \
             --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

REF_DIR = $(NEMU_HOME)/build
DIFFTEST_REF_SO = $(REF_DIR)/riscv32-nemu-interpreter-so

NPCARGS += --log=$(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt
NPCARGS += --elf=$(IMAGE).elf
NPCARGS += --diff=$(DIFFTEST_REF_SO)

difftest-ref:
	$(MAKE) -C $(NEMU_HOME)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg difftest-ref
	$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin ARGS="$(NPCARGS) --batch"

debug: insert-arg difftest-ref
	$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin ARGS="$(NPCARGS)"

gdb: insert-arg difftest-ref
	$(MAKE) -C $(NPC_HOME) gdb IMG=$(IMAGE).bin ARGS="$(NPCARGS)"

.PHONY: insert-arg image run debug gdb difftest-ref
