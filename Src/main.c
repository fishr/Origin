/**
  ******************************************************************************
  * File Name          : main.c
  * Date               : 08/11/2014 22:55:39
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "adc.h"
#include "i2c.h"
#include "ltdc.h"
#include "spi.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"
#include "fmc.h"

/* USER CODE BEGIN Includes */
#include "stm32f4xx_it.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

#define LED_RCC_Periph_PORT RCC_AHB1Periph_GPIOA
uint32_t hello=0;

char cmdData[]="helloworld0";
//uint16_t cmdData[]={9,2,5,7,2,1,0,1,8};
uint8_t mpuCmd = 0x75;
char inImu[32];
char inData[UART_BUFF_LEN];
uint16_t len=0;
//uint16_t inData[32];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
  //cmdData[10]=0x0D;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();
  
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); //screen reset
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET); //screen chip enable

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC3_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  MX_LTDC_Init();
  MX_SPI1_Init();
  MX_SPI5_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USB_OTG_HS_PCD_Init();

  /* USER CODE BEGIN 2 */
  
  
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);  //osc enable
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET); //xbee reset
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); //buck enable


  GPIO_InitTypeDef init;
    init.Pin = GPIO_PIN_3;
    init.Mode = GPIO_MODE_OUTPUT_PP;
    init.Pull = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOC, &init);  //led1
    init.Pin=GPIO_PIN_2;
    HAL_GPIO_Init(GPIOA, &init);  //led2
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
   
    uint32_t ticks = HAL_GetTick();

    /*
    //===========RAM==========================
    uint32_t wraddress = 0x0010;
    HAL_SDRAM_Write_16b(&hsdram1, &wraddress, cmdData, sizeof(cmdData)/sizeof(cmdData[0]));
    HAL_SDRAM_Read_16b(&hsdram1, &wraddress, inData, 32);
    hello=4;
    //==================RAM==========================
   */
    
    
    //LCD ===============================================
    	
/*
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, (uint32_t) LCD_FRAME_BUFFER);
    BSP_LCD_SetLayerVisible(0, ENABLE);
     
    BSP_LCD_LayerDefaultInit(0, (uint32_t) LCD_FRAME_BUFFER);
    BSP_LCD_SetLayerVisible(0, ENABLE);
    BSP_LCD_LayerDefaultInit(1, (uint32_t) LCD_FRAME_BUFFER+76800);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetLayerVisible(1, DISABLE);
     
    BSP_LCD_SelectLayer(0);
    BSP_LCD_Clear(BRED);
    BSP_LCD_DisplayOn();
*/

    //END LCD============================================
    
  /* USER CODE END 2 */

    ticks = HAL_GetTick();
    while(HAL_GetTick()<ticks+1100){
      hello = 0;
    }
    
    HAL_UART_Receive_IT(&huart4, inData, 64);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET); //gps on/off
  /* USER CODE BEGIN 3 */
  /* Infinite loop */
  while (1)
  {
   /*
    if(inData[0]!=0)
    {
      int i = 0;
      while((inData[i]!=0x0D)&&(i<61))
      {
        i++;
      }
      inData[i]=0x0D;
      inData[i+1]=0x0A;
      HAL_UART_Transmit(&huart5, inData, i+2, 500);
    }*/
    
    if(rx_buff.newData){
      memcpy(inData, rx_buff.buffer, rx_buff.length);
      len = rx_buff.length;
      HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
      rx_buff.newData=0;
      HAL_UART_Transmit(&huart5, inData, len, 500);
    }

      
    ticks = HAL_GetTick();
    inData[0]=0;
    //__HAL_I2C_CLEAR_FLAG(&hi2c3, I2C_FLAG_BUSY);
    //while(__HAL_I2C_GET_FLAG(&hi2c3, I2C_FLAG_BUSY) == SET){}
    
    HAL_StatusTypeDef halp = HAL_I2C_Master_Transmit(&hi2c3, 0xD0, &mpuCmd, 1, 500);
    HAL_StatusTypeDef halpme = HAL_I2C_Master_Receive(&hi2c3,  0xD0, inImu, 1, 500);
    
    
    while(HAL_GetTick()<ticks+100){
      hello = 0;
    }
    
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);

    if(inImu[0]!=0)
      hello=1;
  }
  /* USER CODE END 3 */

}




void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  hello_rx_flag = 1;
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 6;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 200;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 4;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_16;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
