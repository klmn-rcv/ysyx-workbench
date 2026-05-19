ENTRY(_start)
/* 为了适配RT-Thread中的extra.ld，只能把segment定义注释掉，否则加载会出问题。 */
/* PHDRS { fsbl PT_LOAD; ssbl PT_LOAD; text PT_LOAD; data PT_LOAD; } */

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  psram (rwx): ORIGIN = _psram_base, LENGTH = _psram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
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
  .text ORIGIN(psram) : {
    . = ALIGN(4);
    _text_vma_start = .;
    *(.text*)
  } > psram AT> flash /*: text*/
  _text_lma_start = LOADADDR(.text);
  _text_vma_end = .;

  .rodata : {
    . = ALIGN(4);
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
  } > psram AT> flash /*: text*/
  _rodata_lma_start = LOADADDR(.rodata);
  _rodata_vma_end = .;

  .data : {
    . = ALIGN(4);
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
  } > psram AT> flash /*: data*/
  _data_lma_start = LOADADDR(.data);
  _data_vma_end = .;

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > psram /*: data*/
  _bss_vma_end = .;

  /* PSRAM holds data/bss/heap, but stack is in SRAM. */
  _heap_start = ALIGN(8);
  _heap_end = ORIGIN(psram) + LENGTH(psram);
  /* _stack_top = ORIGIN(sram);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base; */
}
