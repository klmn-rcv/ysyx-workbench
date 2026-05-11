#include "trap.h"

#define SPI_MASTER_BASE 0x10001000
#define SPI_MASTER_SIZE 0x1000

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

#define CTRL_CHAR_LEN 0 // 6~0
#define CTRL_GO_BSY   8
#define CTRL_Rx_NEG   9
#define CTRL_Tx_NEG   10
#define CTRL_LSB      11
#define CTRL_IE       12
#define CTRL_ASS      13

// 传输数据：10111010，倒过来是01011101
unsigned char byte_data = 0b10111010;

void init_spi_master(void) {
    *(volatile unsigned int *)(SPI_MASTER_BASE + Tx0) = (unsigned int)byte_data << 8; // MSB first
    *(volatile unsigned int *)(SPI_MASTER_BASE + DIVIDER) = 1;
    *(volatile unsigned int *)(SPI_MASTER_BASE + SS) = 1 << 7;  // 选中bitrev
    *(volatile unsigned int *)(SPI_MASTER_BASE + CTRL) = (16 << CTRL_CHAR_LEN) | (1 << CTRL_GO_BSY) | (0 << CTRL_Rx_NEG) | (1 << CTRL_Tx_NEG) | (0 << CTRL_LSB) | (0 << CTRL_IE) | (1 << CTRL_ASS);
}

int main() {
    init_spi_master();
    while(*(volatile unsigned int *)(SPI_MASTER_BASE + CTRL) & (1 << CTRL_GO_BSY))
        ;
    unsigned char rx_data = *(volatile unsigned int *)(SPI_MASTER_BASE + Rx0) & 0xFF;
    check(rx_data == 0b01011101);
    return 0;
}