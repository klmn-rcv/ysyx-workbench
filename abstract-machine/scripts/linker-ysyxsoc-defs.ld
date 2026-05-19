PHDRS { fsbl PT_LOAD; ssbl PT_LOAD; text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom (rx)  : ORIGIN = _mrom_base, LENGTH = _mrom_size
  sram (rwx) : ORIGIN = _sram_base, LENGTH = _sram_size
  psram (rwx): ORIGIN = _psram_base, LENGTH = _psram_size
  flash (rx) : ORIGIN = _flash_base, LENGTH = _flash_size
}
