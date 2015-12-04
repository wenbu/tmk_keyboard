#ifndef ISSI_H
#define ISSI_H

void issi_init(void);

void issi_send_data(const uint8_t* data, uint8_t len, uint8_t page);

uint8_t issi_read_byte(uint8_t page, uint8_t address);

void issi_zero_pages(uint8_t startPage, uint8_t numPages, uint8_t startRegister, uint8_t endRegister);

#endif