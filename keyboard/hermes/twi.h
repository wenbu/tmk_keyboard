#ifndef TWI_H
#define TWI_H

#ifndef TWI_FREQ
#define TWI_FREQ 100000
#endif

void twi_init(void);
uint8_t twi_start(void);
void twi_stop(void);
uint8_t twi_send(uint8_t data);
uint8_t twi_read(uint8_t* data);

#endif