#ifndef TICK_H
#define TICK_H


extern unsigned long __sys_tick_count;

void incSysTick(void);

unsigned long getSysTick(void);

#endif