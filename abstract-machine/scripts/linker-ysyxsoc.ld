ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _mrom_start, _sram_start, _sram_end and _entry_offset are defined in LDFLAGS. */
  . = _mrom_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } : text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  } : text

  . = ALIGN(4);
  _data_load_start = .;
  .data _sram_start : AT(_data_load_start) {
    _data_start = .;
    *(.data*)
    *(.sdata*)
  } : data
  _data_end = .;
  edata = .;
  _data = _data_start;

  .bss (NOLOAD) : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } : data
  _bss_end = .;

  /* SRAM: lower half for data/bss/heap, upper half for stack. */
  _stack_top = _sram_start + (_sram_end - _sram_start) / 2;
  _heap_start = ALIGN(8);
  _heap_end = _stack_top;
  _stack_base = _sram_end;
  _stack_pointer = _stack_base;

  end = .;
  _end = .;
}
