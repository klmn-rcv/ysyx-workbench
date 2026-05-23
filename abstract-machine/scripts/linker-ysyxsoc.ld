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
    *(.fsbl)
    . = ALIGN(4);
  } > flash /*: fsbl*/

  /* Second Stage Bootloader runs from SRAM, but are stored in flash image. */
  .ssbl ORIGIN(sram) : {
    _ssbl_vma_start = .;
    *(.ssbl)
    . = ALIGN(4);
    _ssbl_vma_end = .;
  } > sram AT> flash /*: ssbl*/
  _ssbl_lma_start = LOADADDR(.ssbl);

  /* Stack uses the reserved space in SRAM. */
  _stack_top = ALIGN(4);
  _stack_base = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_base;

  /* Program text/rodata run from SRAM, but are stored in flash image. */
  .text ORIGIN(sdram) : {
    _text_vma_start = .;
    *(.text*)
    . = ALIGN(4);
    _text_vma_end = .;
  } > sdram AT> flash /*: text*/
  _text_lma_start = LOADADDR(.text);

  . = ALIGN(4);
  .rodata : {
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_vma_end = .;
  } > sdram AT> flash /*: text*/
  _rodata_lma_start = LOADADDR(.rodata);

  . = ALIGN(4);
  .data : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _data_vma_end = .;
  } > sdram AT> flash /*: data*/
  _data_lma_start = LOADADDR(.data);

  . = ALIGN(4);
  .bss (NOLOAD) : {
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_vma_end = .;
  } > sdram /*: data*/

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

  ASSERT(((ORIGIN(flash) + _entry_offset) & 3) == 0, "entry address must be 4-byte aligned")
  ASSERT((_ssbl_lma_start & 3) == 0, ".ssbl LMA start must be 4-byte aligned")
  ASSERT((_ssbl_vma_start & 3) == 0, ".ssbl VMA start must be 4-byte aligned")
  ASSERT((_ssbl_vma_end & 3) == 0, ".ssbl VMA end must be 4-byte aligned")
  ASSERT((_text_lma_start & 3) == 0, ".text LMA must be 4-byte aligned")
  ASSERT((_text_vma_start & 3) == 0, ".text VMA start must be 4-byte aligned")
  ASSERT((_text_vma_end & 3) == 0, ".text VMA end must be 4-byte aligned")
  ASSERT((_rodata_lma_start & 3) == 0, ".rodata LMA must be 4-byte aligned")
  ASSERT((_rodata_vma_start & 3) == 0, ".rodata VMA start must be 4-byte aligned")
  ASSERT((_rodata_vma_end & 3) == 0, ".rodata VMA end must be 4-byte aligned")
  ASSERT((_data_lma_start & 3) == 0, ".data LMA must be 4-byte aligned")
  ASSERT((_data_vma_start & 3) == 0, ".data VMA start must be 4-byte aligned")
  ASSERT((_data_vma_end & 3) == 0, ".data VMA end must be 4-byte aligned")
  ASSERT((_bss_vma_start & 3) == 0, ".bss VMA start must be 4-byte aligned")
  ASSERT((_bss_vma_end & 3) == 0, ".bss VMA end must be 4-byte aligned")
  ASSERT((_extra_data_lma_start & 3) == 0, ".data.extra LMA must be 4-byte aligned")
  ASSERT((_extra_data_vma_start & 3) == 0, ".data.extra VMA start must be 4-byte aligned")
  ASSERT((_extra_data_vma_end & 3) == 0, ".data.extra VMA end must be 4-byte aligned")
  ASSERT((_extra_bss_vma_start & 3) == 0, ".bss.extra VMA start must be 4-byte aligned")
  ASSERT((_extra_bss_vma_end & 3) == 0, ".bss.extra VMA end must be 4-byte aligned")
}
