#include "tick.h"

unsigned long __sys_tick_count=0;

void incSysTick(void){
  __sys_tick_count++;
}

unsigned long getSysTick(void){
  return __sys_tick_count;
}