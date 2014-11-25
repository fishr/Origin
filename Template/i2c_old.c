#include "i2c.h"

void I2C_Start(){
  I2C_InitTypeDef hi2c3;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C3, ENABLE);
  
  /**I2C3 GPIO Configuration    
  PC9     ------> I2C3_SDA
  PA8     ------> I2C3_SCL 
  */
  
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_I2C3);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_I2C3);
  
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
  GPIO_Init(GPIOC, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = GPIO_Pin_8;
  GPIO_Init(GPIOA, &GPIO_InitStruct);  
  
  I2C3->CR1|= I2C_CR1_SWRST;
  I2C3->CR1 &= ~I2C_CR1_SWRST;
  
  
  hi2c3.I2C_ClockSpeed = 400000;
  hi2c3.I2C_Mode = I2C_Mode_I2C;
  hi2c3.I2C_DutyCycle = I2C_DutyCycle_16_9;
  hi2c3.I2C_Ack = I2C_Ack_Enable;
  hi2c3.I2C_OwnAddress1 = 0;
  hi2c3.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  
//  hi2c3.DualAddressMode = I2C_DUALADDRESS_DISABLED;
//  hi2c3.OwnAddress2 = 0;
//  hi2c3.GeneralCallMode = I2C_GENERALCALL_DISABLED;
//  hi2c3.NoStretchMode = I2C_NOSTRETCH_DISABLED;
  I2C_Init(I2C3, &hi2c3);
  
  I2C_Cmd(I2C3, ENABLE);
  
  I2C_ClearFlag(I2C3, I2C_FLAG_BUSY);
}