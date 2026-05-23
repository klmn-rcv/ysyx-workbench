.section .fsbl, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  # copy .ssbl from its LMA in flash to its VMA in SRAM
  la t0, _ssbl_lma_start
  la t1, _ssbl_vma_start
  la t2, _ssbl_vma_end
load_ssbl:
  beq t1, t2, load_ssbl_end
  lw a0, 0(t0)
  sw a0, 0(t1)
  addi t0, t0, 4
  addi t1, t1, 4
  j load_ssbl
load_ssbl_end:
  # 不能直接用j _ssbl_start，因为j指令只能跳转到-2^21~2^21-1范围内的相对地址，而_ssbl_start不在这个范围内
  la t1, _ssbl_start
  jr t1

.size _start, . - _start


.section .ssbl, "ax"
# Long copy/clear loops live in .ssbl, so SSBL executes them from SRAM.
copy_region:
  beq t1, t2, copy_region_end
copy_region_loop:
  lw a0, 0(t0)
  sw a0, 0(t1)
  addi t0, t0, 4
  addi t1, t1, 4
  bne t1, t2, copy_region_loop
copy_region_end:
  ret

zero_region:
  beq t1, t2, zero_region_end
zero_region_loop:
  sw zero, 0(t1)
  addi t1, t1, 4
  bne t1, t2, zero_region_loop
zero_region_end:
  ret

.globl _ssbl_start
.type _ssbl_start, @function

_ssbl_start:
  # copy .text from its LMA in flash to its VMA in SDRAM
  la t0, _text_lma_start
  la t1, _text_vma_start
  la t2, _text_vma_end
  call copy_region

  # copy .rodata from its LMA in flash to its VMA in SDRAM
  la t0, _rodata_lma_start
  la t1, _rodata_vma_start
  la t2, _rodata_vma_end
  call copy_region

  # copy .data from its LMA in flash to its VMA in SDRAM
  la t0, _data_lma_start
  la t1, _data_vma_start
  la t2, _data_vma_end
  call copy_region

  # copy optional .data.extra (in RT-Thread) section from flash to SDRAM
  la t0, _extra_data_lma_start
  la t1, _extra_data_vma_start
  la t2, _extra_data_vma_end
  call copy_region

  # zero .bss in SDRAM before entering C code
  la t1, _bss_vma_start
  la t2, _bss_vma_end
  call zero_region

  # zero optional .bss.extra (in RT-Thread) section in SDRAM
  la t1, _extra_bss_vma_start
  la t2, _extra_bss_vma_end
  call zero_region

  call _trm_init

.size _ssbl_start, . - _ssbl_start
