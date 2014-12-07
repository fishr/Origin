#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"

#ifndef ADC_H
#define ADC_H

void ADC_Start(void);

uint16_t getBatteryStatus(void);

#endif
