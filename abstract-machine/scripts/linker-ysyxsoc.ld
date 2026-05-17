ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  psram (rwx): ORIGIN = _psram_base, LENGTH = _psram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
}

SECTIONS {
  /* Flash stores the image; PSRAM holds writable runtime data (except stack). */
  . = ORIGIN(flash) + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } > flash AT> flash : text
  .rodata : {
    *(.rodata*)
  } > flash AT> flash : text

  .data ORIGIN(psram) : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
  } > psram AT> flash : data
  _data_lma_start = LOADADDR(.data);
  _data_vma_end = .;

  .bss (NOLOAD) : {
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > psram : data
  _bss_vma_end = .;

  /* PSRAM holds data/bss/heap; SRAM is reserved for the stack. */
  _heap_start = ALIGN(8);
  _heap_end = ORIGIN(psram) + LENGTH(psram);
  _stack_top = ORIGIN(sram);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base;
}
