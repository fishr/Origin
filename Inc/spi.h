#include "stm32f4xx_gpio.h"
#include "stm32f4xx_spi.h"

#ifndef SPI_H
#define SPI_H

void Flash_Start(void);

void Fl_Read(uint8_t *buff, uint32_t count, uint32_t startAddr);
uint8_t Fl_ReadID(void);

#endif