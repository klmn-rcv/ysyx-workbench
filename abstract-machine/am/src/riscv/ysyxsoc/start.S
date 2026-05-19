.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  # copy .text from its LMA in flash to its VMA in SRAM
  la t0, _text_lma_start
  la t1, _text_vma_start
  la t2, _text_vma_end
load_text:
  beq t1, t2, load_text_end
  lbu a0, 0(t0)
  sb a0, 0(t1)
  addi t0, t0, 1
  addi t1, t1, 1
  j load_text
load_text_end:

  # copy .rodata from its LMA in flash to its VMA in SRAM
  la t0, _rodata_lma_start
  la t1, _rodata_vma_start
  la t2, _rodata_vma_end
load_rodata:
  beq t1, t2, load_rodata_end
  lbu a0, 0(t0)
  sb a0, 0(t1)
  addi t0, t0, 1
  addi t1, t1, 1
  j load_rodata
load_rodata_end:

  # copy .data from its LMA in flash to its VMA in PSRAM
  la t0, _data_lma_start
  la t1, _data_vma_start
  la t2, _data_vma_end
load_data:
  beq t1, t2, load_data_end
  lbu a0, 0(t0)
  sb a0, 0(t1)
  addi t0, t0, 1
  addi t1, t1, 1
  j load_data
load_data_end:

  # zero .bss in PSRAM before entering C code
  la t1, _bss_vma_start
  la t2, _bss_vma_end
clear_bss:
  beq t1, t2, clear_bss_end
  sb zero, 0(t1)
  addi t1, t1, 1
  j clear_bss
clear_bss_end:

  call _trm_init

.size _start, . - _start
