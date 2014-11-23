#include "uart.h"

int hello_rx_flag = 0;
struct RX_Buff rx_buff;
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

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;

/* UART4 init function */
void UART4_Start(void)
{

  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart4);
}

void UART4_IRQHandler(void)
{ 
    HAL_NVIC_DisableIRQ(UART4_IRQn);
  if(__HAL_UART_GET_FLAG(&huart4, UART_FLAG_RXNE)){
      __HAL_UART_CLEAR_FLAG(&huart4, UART_FLAG_RXNE);
      char input = __HAL_UART_FLUSH_DRREGISTER(&huart4);
      if(input=='$'){
        rx_buff.buffer[0]=ORIGIN_ID;
        rx_buff.valid=0;
        rx_buff.newData=0;
        rx_buff.pointer=1;
        rx_buff.buffer[rx_buff.pointer] = input;
        rx_buff.pointer++;
      }else if(input==0x0A){
        rx_buff.valid=1;
        rx_buff.newData=1;
        rx_buff.buffer[rx_buff.pointer] = input;
        rx_buff.length = rx_buff.pointer+1;    
        rx_buff.pointer=1;    
      }else{
        rx_buff.buffer[rx_buff.pointer] = input; 
        (rx_buff.pointer)++;
      }
  }
  HAL_NVIC_EnableIRQ(UART4_IRQn);  
}

void UART5_IRQHandler(void)
{ 
    HAL_NVIC_DisableIRQ(UART5_IRQn);
  if(__HAL_UART_GET_FLAG(&huart5, UART_FLAG_RXNE)){
      __HAL_UART_CLEAR_FLAG(&huart5, UART_FLAG_RXNE);
      char input = __HAL_UART_FLUSH_DRREGISTER(&huart5);
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
  }
  HAL_NVIC_EnableIRQ(UART5_IRQn);  
}

/* UART5 init function */
void MX_UART5_Init(void)
{
  tx_buff.rxID=-1;
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 9600;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart5);

}

void buff_copy(struct TX_Buff* dest, struct TX_Buff* input){
  //dest->buffer=input->buffer;
  strcpy(dest->buffer, input->buffer, input->length);
  dest->length=input->length;
  dest->newData=input->newData;
  dest->pointer=input->pointer;
  dest->rxID=input->rxID;
  dest->valid=input->valid;
}

void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(huart->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspInit 0 */

  /* USER CODE END UART4_MspInit 0 */
    /* Peripheral clock enable */
    __UART4_CLK_ENABLE();
  
    /**UART4 GPIO Configuration    
    PA0/WKUP     ------> UART4_TX
    PA1     ------> UART4_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN UART4_MspInit 1 */

  HAL_NVIC_SetPriorityGrouping(4);
  HAL_NVIC_SetPriority(UART4_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(UART4_IRQn);
  /* USER CODE END UART4_MspInit 1 */
  }
  else if(huart->Instance==UART5)
  {
  /* USER CODE BEGIN UART5_MspInit 0 */

  /* USER CODE END UART5_MspInit 0 */
    /* Peripheral clock enable */
    __UART5_CLK_ENABLE();
  
    /**UART5 GPIO Configuration    
    PC12     ------> UART5_TX
    PD2     ------> UART5_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN UART5_MspInit 1 */  
  HAL_NVIC_SetPriorityGrouping(4);
  HAL_NVIC_SetPriority(UART5_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(UART5_IRQn);
  /* USER CODE END UART5_MspInit 1 */
  }
}