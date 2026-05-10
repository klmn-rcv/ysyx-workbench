ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
}

SECTIONS {
  /* MROM stores the image; SRAM holds writable runtime data. */
  . = ORIGIN(flash) + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } > flash AT> flash : text
  .rodata : {
    *(.rodata*)
  } > flash AT> flash : text

  .data ORIGIN(sram) : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
  } > sram AT> flash : data
  _data_lma_start = LOADADDR(.data);
  _data_vma_end = .;

  .bss (NOLOAD) : {
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram : data
  _bss_vma_end = .;

  /* SRAM: lower half for data/bss/heap, upper half for stack. */
  _heap_start = ALIGN(8);
  _heap_end = ORIGIN(sram) + LENGTH(sram) / 2;
  _stack_top = _heap_end;
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base;
}
