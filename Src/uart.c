#include "uart.h"

int hello_rx_flag = 0;
struct TX_Buff tx_buff;
struct TX_Buff tx_buff0;
struct TX_Buff tx_buff1;
struct TX_Buff tx_buff2;
struct TX_Buff tx_buff3;
struct TX_Buff tx_buff4;
struct TX_Buff tx_buff5;
struct TX_Buff tx_buff6;
struct TX_Buff tx_buff7;
struct TX_Buff tx_buff8;
struct TX_Buff tx_buff9;
uint8_t idFlag = 0;

struct TX_Buff *friends[10];

/* USER CODE END 0 */

/* UART4 init function */
void UART4_Start()
{
  
  USART_InitTypeDef huart4;
  /* USER CODE BEGIN UART4_MspInit 0 */
  GPIO_InitTypeDef GPIO_InitStruct;
  /* USER CODE END UART4_MspInit 0 */
  /* Peripheral clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
  
  /**UART4 GPIO Configuration    
  PA0/WKUP     ------> UART4_TX
  PA1     ------> UART4_RX 
  */
  
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);
  
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  huart4.USART_BaudRate = 9600;
  huart4.USART_WordLength = USART_WordLength_8b;
  huart4.USART_StopBits = USART_StopBits_1;
  huart4.USART_Parity = USART_Parity_No;
  huart4.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
  huart4.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  //huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  USART_Init(UART4, &huart4);
  
  
  /* USER CODE BEGIN UART4_MspInit 1 */
  NVIC_InitTypeDef nvic_init;
  nvic_init.NVIC_IRQChannel=UART4_IRQn;
  nvic_init.NVIC_IRQChannelPreemptionPriority=3;
  nvic_init.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&nvic_init);
  USART_ClearFlag(UART4, USART_IT_RXNE);
  USART_ClearFlag(UART4, USART_IT_TC);
  USART_ClearFlag(UART4, USART_IT_LBD);
  USART_ClearFlag(UART4, USART_IT_CTS);
  
  USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
  /* USER CODE END UART4_MspInit 1 */
  
  USART_Cmd(UART4, ENABLE);
}

/* UART5 init function */
void UART5_Start()
{
  USART_InitTypeDef huart5;
  /* USER CODE BEGIN UART5_MspInit 0 */
  GPIO_InitTypeDef GPIO_InitStruct;
  /* USER CODE END UART5_MspInit 0 */
  /* Peripheral clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE); 
  
  /**UART5 GPIO Configuration    
  PC12     ------> UART5_TX
  PD2     ------> UART5_RX 
  */
  
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_UART5);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource2, GPIO_AF_UART5);
  
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
  GPIO_Init(GPIOC, &GPIO_InitStruct);
  
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
  GPIO_Init(GPIOD, &GPIO_InitStruct);
  
  huart5.USART_BaudRate = 9600;
  huart5.USART_WordLength = USART_WordLength_8b;
  huart5.USART_StopBits = USART_StopBits_1;
  huart5.USART_Parity = USART_Parity_No;
  huart5.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
  huart5.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  //huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  USART_Init(UART5, &huart5);
  
  /* USER CODE BEGIN UART5_MspInit 1 */
  NVIC_InitTypeDef nvic_init;
  nvic_init.NVIC_IRQChannel=UART5_IRQn;
  nvic_init.NVIC_IRQChannelPreemptionPriority=2;
  nvic_init.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&nvic_init);
  
  USART_ClearFlag(UART5, USART_IT_RXNE);
  USART_ClearFlag(UART5, USART_IT_TC);
  USART_ClearFlag(UART5, USART_IT_LBD);
  USART_ClearFlag(UART5, USART_IT_CTS);
  
  USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
  /*USER CODE END UART5_MspInit 1 */
  
  USART_Cmd(UART5, ENABLE);
  
  tx_buff.rxID=-1;
}


void UART5_IRQHandler(void)  //XBEE
{ 
  //USART_ITConfig(UART5, USART_IT_RXNE, DISABLE);
  //if(USART_GetITStatus(UART5, USART_FLAG_RXNE)==SET){
  //USART_ClearITPendingBit(UART5, USART_FLAG_RXNE);
  char input = USART_ReceiveData(UART5);
  if(tx_buff.rxID<0){
    tx_buff.rxID=input;
    idFlag = 1;
    tx_buff.valid=0;
    tx_buff.newData=0;
  }else if(input=='$'){
    tx_buff.buffer[0]=tx_buff.rxID;
    tx_buff.pointer=1;
    tx_buff.buffer[tx_buff.pointer] = input;
    tx_buff.pointer++;
    idFlag=0;
  }else if(input==0x0A){
    if((idFlag)||(tx_buff.valid)){
      idFlag=0;
      tx_buff.rxID=-1;
      tx_buff.pointer=1; 
    }else{
      tx_buff.valid=1;
      tx_buff.newData=1;
      tx_buff.buffer[tx_buff.pointer] = input;
      tx_buff.length = tx_buff.pointer+1;    
      tx_buff.pointer=1;   
      idFlag=0;
      switch(tx_buff.rxID){
      case '0':
        buff_copy(&tx_buff0, &tx_buff);
        friends[0]=&tx_buff0;
        break;
      case '1':
        buff_copy(&tx_buff1, &tx_buff);
        friends[1]=&tx_buff1;
        break;
      case '2':
        buff_copy(&tx_buff2, &tx_buff);
        friends[2]=&tx_buff2;
        break;
      case '3':
        buff_copy(&tx_buff3, &tx_buff);
        friends[3]=&tx_buff3;
        break;
      case '4':
        buff_copy(&tx_buff4, &tx_buff);
        friends[4]=&tx_buff4;
        break;
      case '5':
        buff_copy(&tx_buff5, &tx_buff);
        friends[5]=&tx_buff5;
        break;
      case '6':
        buff_copy(&tx_buff6, &tx_buff);
        friends[6]=&tx_buff6;
        break;
      case '7':
        buff_copy(&tx_buff7, &tx_buff);
        friends[7]=&tx_buff7;
        break;
      case '8':
        buff_copy(&tx_buff8, &tx_buff);
        friends[8]=&tx_buff8;
        break;
      case '9':
        buff_copy(&tx_buff9, &tx_buff);
        friends[9]=&tx_buff9;
        break;
      }
      tx_buff.rxID=-1;
    }
  }else{
    if(idFlag){
      idFlag=0;
      tx_buff.rxID=-1;
      tx_buff.pointer=1; 
    }else{
      tx_buff.buffer[tx_buff.pointer] = input; 
      (tx_buff.pointer)++;
    }
  }
  //}
  //USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
}

void UART_Transmit(USART_TypeDef* UARTX, uint8_t* buff, uint16_t buff_len, uint32_t timeout){
  unsigned long timeout_time = getSysTick()+timeout;
  uint16_t count = 0;
  while(count<buff_len){
    while (!USART_GetFlagStatus(UARTX, USART_FLAG_TXE)){
      if (getSysTick()>timeout_time)
        return;
    }
    USART_SendData(UARTX, *buff);
    count++;
    buff++;
  }
}

void buff_copy(struct TX_Buff* dest, struct TX_Buff* input){
  //dest->buffer=input->buffer;
  strcpy(dest->buffer, input->buffer);
  dest->length=input->length;
  dest->newData=input->newData;
  dest->pointer=input->pointer;
  dest->rxID=input->rxID;
  dest->valid=input->valid;
}