#include "user.h"
#include "origintypes.h"
#include "uart.h"
#include "stdio.h"
#include "float.h"
#include "latlong.h"

#ifndef XBEE_H
#define XBEE_H

//extern struct RX_Buff xbee_buff;

void sendMessage(void);
void UART5_IRQHandler(void);
void processXbee(void);
void parseXbee(char *xbee_string);

#endif