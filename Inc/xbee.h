#include "user.h"
#include "origintypes.h"
#include "uart.h"
#include "string.h"
#include "stdio.h"


#ifndef XBEE_H
#define XBEE_H

//extern struct RX_Buff xbee_buff;

void sendMessage(void);
void UART5_IRQHandler(void);
void processXbee(void);

#endif