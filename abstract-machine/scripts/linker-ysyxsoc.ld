ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  psram (rwx): ORIGIN = _psram_base, LENGTH = _psram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
}

SECTIONS {
  . = ORIGIN(flash) + _entry_offset;

  /* Bootloader stays in flash and runs directly after reset. */
  .entry : {
    . = ALIGN(4);
    *(entry)
  } > flash : text
  
  /* Program text/rodata run from SRAM, but are stored in flash image. */
  .text ORIGIN(sram) : {
    . = ALIGN(4);
    _text_vma_start = .;
    *(.text*)
  } > sram AT> flash : text
  _text_lma_start = LOADADDR(.text);
  _text_vma_end = .;

  .rodata : {
    . = ALIGN(4);
    _rodata_vma_start = .;
    *(.rodata*)
  } > sram AT> flash : text
  _rodata_lma_start = LOADADDR(.rodata);
  _rodata_vma_end = .;

  _stack_top = ALIGN(4);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base;

  .data ORIGIN(psram) : {
    . = ALIGN(4);
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
  } > psram AT> flash : data
  _data_lma_start = LOADADDR(.data);
  _data_vma_end = .;

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > psram : data
  _bss_vma_end = .;

  /* PSRAM holds data/bss/heap, but stack is in SRAM. */
  _heap_start = ALIGN(8);
  _heap_end = ORIGIN(psram) + LENGTH(psram);
  /* _stack_top = ORIGIN(sram); */
  /* _stack_base = ORIGIN(sram) + LENGTH(sram); */
  /* _stack_pointer = _stack_base; */
}
