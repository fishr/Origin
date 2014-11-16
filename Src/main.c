/**
  ******************************************************************************
  * File Name          : main.c
  * Date               : 14/11/2014 14:18:08
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
#include "stm32f429i_discovery_lcd.h"
#include "rgb565_240x320.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

#define LED_RCC_Periph_PORT RCC_AHB1Periph_GPIOA
uint32_t hello=0;

char cmdData[]="helloworld0";
//uint16_t cmdData[]={9,2,2,7,2,1,0,1,8};
uint8_t mpuCmd = 0x71;
char inImu[32];
char inData[64];
int tempcount = 0;
//uint16_t inData[32];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void LCD_Config(void);
void SystemClock_Config(void);
extern LTDC_HandleTypeDef hltdc;

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

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC3_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  
  MX_SPI1_Init();
  MX_SPI5_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USB_OTG_HS_PCD_Init();

  /* USER CODE BEGIN 2 */
  
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); //not LCD reset
for (int i = 0; i<200; i++)
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); //not LCD reset

HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);  //osc enable
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET); //xbee reset
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); //buck enable
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); //set LCD Read High


  GPIO_InitTypeDef init;
    init.Pin = GPIO_PIN_3;
    init.Mode = GPIO_MODE_OUTPUT_PP;
    init.Pull = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOC, &init);
    init.Pin=GPIO_PIN_2;
    HAL_GPIO_Init(GPIOA, &init);
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

//    LCD_Config();  
//    
//      /* Enable The LCD */
//    __HAL_LTDC_ENABLE(&hltdc);
    
    
    //END LCD============================================
    
  /* USER CODE END 2 */

  /* USER CODE BEGIN 3 */
  /* Infinite loop */
  while (1)
  {
    if (tempcount % 10000 == 0){
      uint8_t value1 = (uint8_t) LCD_WDB;
      LCD_WriteCommand(&value1);
      uint8_t value2 = (uint8_t) 0x01;
      LCD_WriteData(&value2);
    }
    else if (tempcount % 5000 == 0){
      uint8_t value1 = (uint8_t) LCD_WDB;
      LCD_WriteCommand(&value1);
      uint8_t value2 = (uint8_t) 0xF0;
      LCD_WriteData(&value2);
    }
    
    tempcount++;
//    
//    if(inData[0]!=0)
//    {
//      int i = 0;
//      while((inData[i]!=0x0D)&&(i<61))
//      {
//        i++;
//      }
//      inData[i]=0x0D;
//      inData[i+1]=0x0A;
//      HAL_UART_Transmit(&huart5, inData, i+2, 500);
//    }
//      
//    ticks = HAL_GetTick();
//    inData[0]=0;
//    HAL_UART_Receive(&huart4, inData, 64, 500);
//    //__HAL_I2C_CLEAR_FLAG(&hi2c3, I2C_FLAG_BUSY);
//    //while(__HAL_I2C_GET_FLAG(&hi2c3, I2C_FLAG_BUSY) == SET){}
//    
//    //HAL_StatusTypeDef halp = HAL_I2C_Master_Transmit(&hi2c3, 0x68, &mpuCmd, 1, 500);
//    //HAL_StatusTypeDef halpme = HAL_I2C_Master_Receive(&hi2c3,  0x68, inImu, 2, 500);
//    
//    
//    while(HAL_GetTick()<ticks+100){
//      hello = 0;
//    }
//    
//    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
//    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
//    
//    if (tempcount>0){
//      LCD_WriteCommand(LCD_WCD);
//      LCD_WriteData(0x00);
//      tempcount = 0;
//    }
//    else {
//      LCD_WriteCommand(LCD_WCD);
//      LCD_WriteData(0xFF);
//      tempcount++;
//    }


    //if(inImu[0]!=0)
      //hello=1;
  }
  /* USER CODE END 3 */

}
/**
  * @brief LCD configuration.
  * @note  This function Configure tha LTDC peripheral :
  *        1) Configure the Pixel Clock for the LCD
  *        2) Configure the LTDC Timing and Polarity
  *        3) Configure the LTDC Layer 1 :
  *           - The frame buffer is located at FLASH memory
  *           - The Layer size configuration : 240x160
  *        4) Configure the LTDC Layer 2.
  *           - The frame buffer is located at FLASH memory
  *           - The Layer size configuration : 240x160
  * @retval
  *  None
  */
static void LCD_Config(void)
{
  /* Configure the LCD Control pins ------------------------------------------*/
  LCD_CtrlLinesConfig();
  LCD_ChipSelect(DISABLE);
  LCD_ChipSelect(ENABLE);
  /* Configure the LCD_SPI interface -----------------------------------------*/

  /* Power on the LCD --------------------------------------------------------*/
  LCD_PowerOn();

//  /* Configure the FMC Parallel interface : SDRAM is used as Frame Buffer for 
//     LCD */
//  SDRAM_Init();
  
  /* Enable Pixel Clock ------------------------------------------------------*/
  
  /* Configure PLLSAI prescalers for LCD */
  /* PLLSAI_VCO Input = HSE_VALUE/PLL_M = 1 Mhz */
  /* PLLSAI_VCO Output = PLLSAI_VCO Input * PLLSAI_N = 192 Mhz */
  /* PLLLCDCLK = PLLSAI_VCO Output/PLLSAI_R = 192/3 = 64 Mhz */
  /* LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 64/8 = 8 Mhz */
  __HAL_RCC_PLLSAI_CONFIG(192, 7, 3);
  __HAL_RCC_PLLSAI_PLLSAICLKDIVR_CONFIG(RCC_PLLSAIDIVR_8);
  /* Enable PLLSAI Clock */
  __HAL_RCC_PLLSAI_ENABLE();
  /* Wait for PLLSAI activation */
  while(__HAL_RCC_PLLSAI_GET_FLAG() == RESET)
  {
  }
  
  /* LTDC Initialization -----------------------------------------------------*/
  MX_LTDC_Init();
  /* LTDC initialization end -------------------------------------------------*/
  
  /* Layer1 Configuration ----------------------------------------------------*/  
  
/* Layer1 Configuration ------------------------------------------------------*/  
    LTDC_LayerCfgTypeDef  LTDC_Layer_InitStruct;
  /* Windowing configuration */ 
  /* In this case all the active display area is used to display a picture then :
     Horizontal start = horizontal synchronization + Horizontal back porch = 30 
     Horizontal stop = Horizontal start + window width -1 = 30 + 240 -1
     Vertical start   = vertical synchronization + vertical back porch     = 4
     Vertical stop   = Vertical start + window height -1  = 4 + 320 -1      */ 
  LTDC_Layer_InitStruct.WindowX0 = 30;
  LTDC_Layer_InitStruct.WindowX1 = (240 + 30 - 1); 
  LTDC_Layer_InitStruct.WindowY0 = 4;
  LTDC_Layer_InitStruct.WindowY1 = (320 + 4 - 1);
  
  /* Pixel Format configuration*/           
  LTDC_Layer_InitStruct.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  
  /* Alpha constant (255 totally opaque) */
  LTDC_Layer_InitStruct.Alpha = 255; 
  LTDC_Layer_InitStruct.Alpha0 = 0;
  
  /* Configure blending factors */       
  LTDC_Layer_InitStruct.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;    
  LTDC_Layer_InitStruct.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;  
  
  /* Default Color configuration (configure A,R,G,B component values) */       
  LTDC_ColorTypeDef   Backgroundcolor;
    
  Backgroundcolor.Blue = 0;        
  Backgroundcolor.Green = 0;       
  Backgroundcolor.Red = 0;         
  LTDC_Layer_InitStruct.Backcolor = Backgroundcolor;   
   
  /* Input Address configuration */    
  LTDC_Layer_InitStruct.FBStartAdress = (uint32_t)&RGB565_240x320;
 
  /* the length of one line of pixels */
  LTDC_Layer_InitStruct.ImageWidth = 240;

  /* configure the number of lines */
  LTDC_Layer_InitStruct.ImageHeight = 320;
   
  HAL_LTDC_ConfigLayer(&hltdc, &LTDC_Layer_InitStruct, 0);
  /* Layer1 Configuration end ------------------------------------------------*/

  HAL_LTDC_EnableDither(&hltdc);
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
