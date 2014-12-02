#include "spi.h"

void Fl_start_read(void);
void Fl_start_read_id(void);
void Fl_send_addr(uint32_t addr);
void Fl_select(void);
void Fl_deselect(void);
void Fl_send_blank_byte(void);

void Flash_Start(void)
{
  
  /*spi pins*/
  //A5 sck
  //A7 mosi
  //B4 miso
  
  
  SPI_InitTypeDef    SPI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;

  /* Enable SPI_SCK_GPIO_CLK, SPI_MISO_GPIO_CLK and SPI_MOSI_GPIO_CLK clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Enable SPI and SYSCFG clock  */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
  
  /* Connect SPI SCK */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);

  /* Connect SPI MISO */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI1);

  /* Connect SPI MOSI */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
  
  /* Configure SPI SCK pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure SPI MISO pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure SPI MOSI pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* SPI configuration -------------------------------------------------------*/
  
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);

  /* Enable Flash SPI  */
  SPI_Cmd(SPI1, ENABLE);

 }

void Fl_Read(uint8_t *buff, uint32_t count, uint32_t startAddr){
  Fl_select();
  Fl_start_read();
  Fl_send_addr(startAddr);
  for(uint32_t i=0; i<count; i++){
    buff[i]=SPI_I2S_ReceiveData(SPI1);
  }
  Fl_deselect();
}

uint8_t Fl_ReadID(void){
  Fl_select();
  Fl_start_read_id();
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET){}
  uint8_t buff=SPI_I2S_ReceiveData(SPI1);
  Fl_send_blank_byte();
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET){}
  buff=SPI_I2S_ReceiveData(SPI1);
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_BSY) == SET){}
  unsigned int i=0;
  while(i<50){
    i++;
  }
  Fl_deselect();
  return buff;
}

void Fl_send_blank_byte(void){
    while(RESET==SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_TXE)){}
  SPI_I2S_SendData(SPI1, 0xFF);
    while(SET==SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_TXE)){}
}

void Fl_select(void){
  GPIO_ResetBits(GPIOG, GPIO_Pin_3);
  unsigned int i=0;
  while(i<5){
    i++;
  }
}

void Fl_deselect(void){
  GPIO_SetBits(GPIOG, GPIO_Pin_3);
}

void Fl_start_read(void){
    while(RESET==SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_TXE)){}
    SPI_I2S_SendData(SPI1, 0x03); //read op
}

void Fl_start_read_id(void){
  while(RESET==SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_TXE)){}
  SPI_I2S_SendData(SPI1, 0x9E);  //read id op
    while(SET==SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_TXE)){}
}

void Fl_send_addr(uint32_t addr){
  SPI_I2S_SendData(SPI1, (uint8_t)((addr>>16)&0x0F));
  SPI_I2S_SendData(SPI1, (uint8_t)((addr>>8)&0x0F));
  SPI_I2S_SendData(SPI1, (uint8_t)((addr)&0x0F));
}