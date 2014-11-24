#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stdlib.h"
#include "string.h"

#ifndef UART_H
#define UART_H

#define UART_BUFF_LEN 128
#define ORIGIN_ID '1'
   
extern int hello_rx_flag;

typedef struct RX_Buff{
  uint8_t newData;
  uint8_t valid;
  uint16_t length;
  uint16_t pointer;
  char buffer[UART_BUFF_LEN];
};

typedef struct TX_Buff{
  int8_t rxID;
  uint8_t newData;
  uint8_t valid;
  uint16_t length;
  uint16_t pointer;
  char buffer[UART_BUFF_LEN];
};

extern struct RX_Buff rx_buff;
//extern struct TX_Buff tx_buff;
extern struct TX_Buff *friends[10];

void UART4_Start(void);
void UART5_Start(void);

void UART4_IRQHandler(void);
void UART5_IRQHandler(void);

void buff_copy(struct TX_Buff* dest, struct TX_Buff* input);



#endif