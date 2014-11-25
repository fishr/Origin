/**
******************************************************************************
* @file    Template/main.c 
* @author  MCD Application Team
* @version V1.0.0
* @date    20-September-2013
* @brief   Main program body
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
*
* Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
* You may not use this file except in compliance with the License.
* You may obtain a copy of the License at:
*
*        http://www.st.com/software_license_agreement_liberty_v2
*
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Template
* @{
*/ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
//#define USE_FULL_ASSERT
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char hello[]="helloworld";

char cmdData1[]="$PSRF104,42.359544,-71.0935699,0,96000,478200,1819,12,3*0B00"; //init
char cmdData2[] = "$PSRF103,08,01,00,01*2D00"; //send timing update
char cmdData3[]="$PSRF105,1*3E00"; //gps debug mode
uint8_t mpuCmd = 0x75;
char inImu[32];
char inData[UART_BUFF_LEN];
uint16_t len=0;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void assert_failed(uint8_t*, uint32_t);
/* Private functions ---------------------------------------------------------*/

/**
* @brief   Main program
* @param  None
* @retval None
*/
int main(void)
{
  SysTick_Config(SystemCoreClock / 1000);
  
  GPIO_Start();
  
  unsigned long tickey = getSysTick()+1000;
  
  GPIO_SetBits(GPIOC, GPIO_Pin_1);  //osc enable
  GPIO_ResetBits(GPIOC, GPIO_Pin_11); //xbee reset
  GPIO_SetBits(GPIOE, GPIO_Pin_6); //buck enable
  while(getSysTick()<tickey);
  GPIO_SetBits(GPIOE, GPIO_Pin_2); //gps on/off
  GPIO_SetBits(GPIOC, GPIO_Pin_11); //xbee reset
  while(getSysTick()<tickey);
  UART4_Start();
  UART5_Start();
  I2cMaster_Init();
  //========================BUTTONS====================
  InitButton(&button1, GPIOE, GPIO_Pin_4);
  InitButton(&button2, GPIOE, GPIO_Pin_5);
  //=======================END BUTTONS==================
  
  
  /* Infinite loop */
  while (1)
  {
    
    UpdateButton(&button1);
    UpdateButton(&button2);
    
    if( buttonRisingEdge(&button1)){//right
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3);//yellow
      //UART_Transmit(&huart4, cmdData1, cmdData1Len, 500);
    }
    
    if(buttonRisingEdge(&button2)){//left
      
      //UART_Transmit(&huart4, cmdData2, cmdData2Len, 500);
      GPIO_ToggleBits(GPIOA, GPIO_Pin_2); //green
      
    }
    
    if(getSysTick()>tickey){
      tickey +=1000;
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3); 
      //UART_Transmit(UART5, hello, sizeof(hello)/sizeof(hello[0]), 200);
    }
    
    if(rx_buff.newData){
      memcpy(inData, rx_buff.buffer, rx_buff.length);
      len = rx_buff.length;
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3);
      rx_buff.newData=0;
      UART_Transmit(UART5, inData, len, 200);
    }
    for(int i =0; i<10; i++){
      if(friends[i]!=0){
        if(friends[i]->newData!=0){
          uint8_t tempIdMsg[3];
          tempIdMsg[0]=friends[i]->rxID;
          tempIdMsg[1]=0x0D;
          tempIdMsg[2]=0x0A;
          friends[i]->newData=0;
          UART_Transmit(UART5, tempIdMsg, 3, 500);
          double lat;
          double longi;
          parseGPS(friends[i]->buffer, &lat, &longi);
        }
      }
    }
    
    Sensors_I2C_ReadRegister((unsigned char)0x68, (unsigned char)mpuCmd, 1, inImu);
    
    
//    I2C_GenerateSTART(I2C3, ENABLE);
//    I2C_Send7bitAddress(I2C3, 0xD0, I2C_Direction_Transmitter);
//    I2C_SendData(I2C3, mpuCmd[0]);
//    I2C_GenerateSTOP(I2C3, ENABLE);
//    
    //HAL_StatusTypeDef halp = HAL_I2C_Master_Transmit(&hi2c3, 0xD0, &mpuCmd, 1, 500);
//
//    I2C_GenerateSTART(I2C3, ENABLE);
//    I2C_Send7bitAddress(I2C3, 0xD0, I2C_Direction_Receiver);
//    
//    I2C_GenerateSTOP(I2C3, ENABLE);
//    
    //HAL_StatusTypeDef halpme = HAL_I2C_Master_Receive(&hi2c3,  0xD0, inImu, 1, 500);
    int g =inImu[0];
  }
}
  
#ifdef  USE_FULL_ASSERT
  
  /**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
  void assert_failed(uint8_t* file, uint32_t line)
  { 
    /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    
    /* Infinite loop */
    while (1)
    {
      int g=0;
    }
  }
#endif
  
  /**
  * @}
  */
  
  
  /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
  