#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stdlib.h"
#include "string.h"
#include "tick.h"
#include "user.h"

#ifndef UART_H
#define UART_H
   
extern int hello_rx_flag;

typedef struct RX_Buff{
  uint8_t newData;
  uint8_t lock;
  uint16_t length;
  uint16_t pointer;
  char buffer[UART_BUFF_LEN];
  char msg[UART_BUFF_LEN];
  uint16_t msg_len;
};

typedef struct TX_Buff{
  int8_t rxID;
  uint8_t newData;
  uint8_t valid;
  uint16_t length;
  uint16_t pointer;
  char buffer[UART_BUFF_LEN];
};

//extern struct TX_Buff tx_buff;
extern struct TX_Buff *friends[10];

void UART4_Start(void);
void UART5_Start(void);

void UART_Transmit(USART_TypeDef*, uint8_t*, uint16_t, uint32_t);

void UART5_IRQHandler(void);

void buff_copy(struct TX_Buff* dest, struct TX_Buff* input);



#endif