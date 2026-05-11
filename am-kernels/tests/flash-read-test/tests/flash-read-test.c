#include "trap.h"

#define SPI_MASTER_BASE 0x10001000u
#define FLASH_BASE      0x30000000u

#define Rx0     0x00    // R
#define Rx1     0x04    // R
#define Rx2     0x08    // R
#define Rx3     0x0c    // R
#define Tx0     0x00    // R/W
#define Tx1     0x04    // R/W
#define Tx2     0x08    // R/W
#define Tx3     0x0c    // R/W
#define CTRL    0x10    // R/W
#define DIVIDER 0x14    // R/W
#define SS      0x18    // R/W

#define CTRL_CHAR_LEN 0 // 6:0
#define CTRL_GO_BSY   8
#define CTRL_Rx_NEG   9
#define CTRL_Tx_NEG   10
#define CTRL_LSB      11
#define CTRL_IE       12
#define CTRL_ASS      13

static inline uint32_t mmio_read(uint32_t addr) {
  return *(volatile uint32_t *)addr;
}

static inline void mmio_write(uint32_t addr, uint32_t data) {
  *(volatile uint32_t *)addr = data;
}

static inline uint32_t bswap32(uint32_t data) {
  return (data >> 24) | ((data >> 8) & 0x0000ff00u) |
         ((data << 8) & 0x00ff0000u) | (data << 24);
}

static inline void init_spi_master(void) {
  mmio_write(SPI_MASTER_BASE + DIVIDER, 1);
  mmio_write(SPI_MASTER_BASE + SS, 1u << 0);
}

uint32_t flash_read(uint32_t addr) {
  uint32_t ctrl = (64u << CTRL_CHAR_LEN) |
                  (0u  << CTRL_Rx_NEG)   |
                  (1u  << CTRL_Tx_NEG)   |
                  (0u  << CTRL_LSB)      |
                  (0u  << CTRL_IE)       |
                  (1u  << CTRL_ASS)      |
                  (1u  << CTRL_GO_BSY);

  mmio_write(SPI_MASTER_BASE + Tx0, 0);
  mmio_write(SPI_MASTER_BASE + Tx1, (0x03u << 24) | (addr & 0x00ffffffu));
  mmio_write(SPI_MASTER_BASE + CTRL, ctrl);

  while (mmio_read(SPI_MASTER_BASE + CTRL) & (1u << CTRL_GO_BSY))
    ;

  return bswap32(mmio_read(SPI_MASTER_BASE + Rx0));
}

int main(void) {
  init_spi_master();

  check(flash_read(0x0)  == mmio_read(FLASH_BASE + 0x0));
  check(flash_read(0x4)  == mmio_read(FLASH_BASE + 0x4));
  check(flash_read(0x8)  == mmio_read(FLASH_BASE + 0x8));
  check(flash_read(0xc)  == mmio_read(FLASH_BASE + 0xc));

  return 0;
}
