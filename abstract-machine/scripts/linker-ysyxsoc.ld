ENTRY(_start)
/* 为了适配RT-Thread中的extra.ld，只能把这里的segment定义注释掉，否则加载会出问题。 */
/* PHDRS { fsbl PT_LOAD; ssbl PT_LOAD; text PT_LOAD; data PT_LOAD; } */

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
  psram (rwx): ORIGIN = _psram_base, LENGTH = _psram_size
  sdram (rwx): ORIGIN = _sdram_base, LENGTH = _sdram_size
}

SECTIONS {
  . = ORIGIN(flash) + _entry_offset;

  /* First Stage Bootloader stays in flash and runs directly after reset. */
  .fsbl : {
    . = ALIGN(4);
    *(.fsbl)
  } > flash /*: fsbl*/

  /* Second Stage Bootloader runs from SRAM, but are stored in flash image. */
  .ssbl ORIGIN(sram) : {
    . = ALIGN(4);
    _ssbl_vma_start = .;
    *(.ssbl)
  } > sram AT> flash /*: ssbl*/
  _ssbl_lma_start = LOADADDR(.ssbl);
  _ssbl_vma_end = .;

  /* Stack uses the reserved space in SRAM. */
  _stack_top = ALIGN(4);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base;

  /* Program text/rodata run from SRAM, but are stored in flash image. */
  .text ORIGIN(sdram) : {
    . = ALIGN(4);
    _text_vma_start = .;
    *(.text*)
  } > sdram AT> flash /*: text*/
  _text_lma_start = LOADADDR(.text);
  _text_vma_end = .;

  .rodata : {
    . = ALIGN(4);
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
  } > sdram AT> flash /*: text*/
  _rodata_lma_start = LOADADDR(.rodata);
  _rodata_vma_end = .;

  .data : {
    . = ALIGN(4);
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
  } > sdram AT> flash /*: data*/
  _data_lma_start = LOADADDR(.data);
  _data_vma_end = .;

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram /*: data*/
  _bss_vma_end = .;

  _heap_start = ALIGN(8);
  _heap_end = ORIGIN(sdram) + LENGTH(sdram);
  /* _stack_top = ORIGIN(sram);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base; */

  /* 这些专门用于RT-Thread的extra.ld里定义的额外.data.extra和.bss.extra段 */
  PROVIDE(_extra_data_lma_start = 0);
  PROVIDE(_extra_data_vma_start = 0);
  PROVIDE(_extra_data_vma_end = 0);
  PROVIDE(_extra_bss_vma_start = 0);
  PROVIDE(_extra_bss_vma_end = 0);
}
