#include "stdint.h"

#ifndef TICK_H
#define TICK_H


extern unsigned long __sys_tick_count;

void mdelay(uint16_t delay_time);

void incSysTick(void);

unsigned long getSysTick(void);

unsigned long storeSysTick(unsigned long *count);

#endif