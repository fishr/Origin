#include "tick.h"

unsigned long __sys_tick_count=0;

void mdelay(uint16_t delay_time)
{
  unsigned long counts = getSysTick()+delay_time;
  while(getSysTick()<counts);
}

void incSysTick(void){
  __sys_tick_count++;
}

unsigned long getSysTick(void){
  return __sys_tick_count;
}

unsigned long storeSysTick(unsigned long *count){
  count[0]=getSysTick();
  return 0;
}