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
//#define ORIGIN
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

double degrees=0;
unsigned char  new_temp = 0;
    unsigned char new_compass = 0;
    unsigned long timestamp;


long headingData[3];
uint8_t headingAcc=0;
inv_time_t headingTime;


LTDC_ColorKeying_InitTypeDef   LTDC_colorkeying_InitStruct;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void assert_failed(uint8_t*, uint32_t);

#ifndef USE_Delay
static void delay(__IO uint32_t nCount);
#endif /* USE_Delay*/

/* Private functions ---------------------------------------------------------*/

//static unsigned char *mpl_key = (unsigned char*)"eMPL 5.1";


/**
* @brief   Main program
* @param  None
* @retval None
*/
int main(void)
{
  SysTick_Config(SystemCoreClock / 1000);
  
  GPIO_Start();
  ADC_Start();
  Flash_Start();
  
  unsigned long tickey = getSysTick()+1000;
  GPIO_ResetBits(GPIOA, GPIO_Pin_10); //LCD Reset must be held 10us
  GPIO_SetBits(GPIOG, GPIO_Pin_3);  //flash deselect
  GPIO_SetBits(GPIOC, GPIO_Pin_8);  //flash #hold off, we have dedicated pins
  GPIO_SetBits(GPIOC, GPIO_Pin_1);  //osc enable
  GPIO_ResetBits(GPIOC, GPIO_Pin_11); //xbee reset
  GPIO_SetBits(GPIOE, GPIO_Pin_6); //buck enable
  while(getSysTick()<tickey);
  GPIO_SetBits(GPIOE, GPIO_Pin_2); //gps on/off
  GPIO_SetBits(GPIOC, GPIO_Pin_11); //xbee reset
  GPIO_SetBits(GPIOA, GPIO_Pin_10);  //LCD unreset
  UART4_Start();
  UART5_Start();
  MPU_Start();
  
  //========================BUTTONS====================
  InitButton(&button1, GPIOE, GPIO_Pin_4);
  InitButton(&button2, GPIOE, GPIO_Pin_5);
  //=======================END BUTTONS==================
    
    /* LCD Configuration */
    LCD_Config();
    /* Enable The LCD */
    LTDC_Cmd(ENABLE);
    LCD_SetLayer(LCD_FOREGROUND_LAYER);
    GUI_ClearBackground();
    
    delay(20000);
    
    GUI_InitNode(1, 72,  83, 0xe8ec);
    GUI_InitNode(2, 86,  72, 0xfd20);
    GUI_InitNode(3, 82,  70, 0x001f);
    
    
    int count = 0;
  

  /* Infinite loop */
  while (1)
  {
 //   int count = 0;
 //         while(1) {
 //     
 //   // GUI_DrawBackground();
////    GUI_ClearForeground();
 //   GUI_DrawNodePolar(&n1, 3.14*1.25, count);
 //   delay(200000);
 //   //GUI_DrawBattery(getBatteryStatus());
 //   GUI_ClearNodePolar(&n1, 3.14*1.25, count);
 //   count += 1;
 //   if (count%100 == 0){
 //     count = 0;
 //   }
 //   
 //     }
 //   
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
    
#ifdef ORIGIN
    long actHeading=0;
    inv_get_sensor_type_heading(&actHeading, &headingAcc, &headingTime);
    degrees=((double)actHeading)/((double)65536.0);
#endif
    
    if(getSysTick()>tickey){
      tickey +=51;
      
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3); 
      //UART_Transmit(idUART5, hello, sizeof(hello)/sizeof(hello[0]), 200);
  

      GUI_UpdateNode(1, degrees*3.1415/180.0+3.14*1.25, count, (count>10), 0);
      GUI_UpdateNode(2, degrees*3.1415/180.0+3.14, count, (count>30), 0);
      GUI_UpdateNode(3, degrees*3.1415/180.0+0, count, (count>50), 0);
      GUI_UpdateArrow(degrees*3.1415/180.0);
      GUI_UpdateBattery(getBatteryStatus());
      GUI_Redraw();
      
#ifndef ORIGIN
      count += 1;
      degrees += 3.6;
      if (count%100 == 0){
        count = 0;
        degrees = 0;
      }
#endif
      
      GUI_DrawTime();


//      //GPIO_ToggleBits(GPIOC, GPIO_Pin_3); 
//      //UART_Transmit(UART5, hello, sizeof(hello)/sizeof(hello[0]), 200);
//      
//      uint8_t headingCode = inv_get_sensor_type_compass(headingData, &headingAcc, &headingTime);
//      if(headingCode){
//      }
      
//      uint8_t flubber= Fl_ReadID();
//      flubber++;
//      
    
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
    
    //Sensors_I2C_ReadRegister((unsigned char)0x68, (unsigned char)mpuCmd, 1, inImu);

    
    int16_t ha= getBatteryStatus();
    
    
    //==================================IMU================================
     unsigned long sensor_timestamp;
    int new_data = 0;

    get_tick_count(&timestamp);

#ifdef COMPASS_ENABLED
        /* We're not using a data ready interrupt for the compass, so we'll
         * make our compass reads timer-based instead.
         */
        if ((timestamp > hal.next_compass_ms) && !hal.lp_accel_mode &&
            hal.new_gyro && (hal.sensors & COMPASS_ON)) {
            hal.next_compass_ms = timestamp + COMPASS_READ_MS;
            new_compass = 1;
        }
#endif
        /* Temperature data doesn't need to be read with every gyro sample.
         * Let's make them timer-based like the compass reads.
         */
        if (timestamp > hal.next_temp_ms) {
            hal.next_temp_ms = timestamp + TEMP_READ_MS;
            new_temp = 1;
        }

    if (hal.motion_int_mode) {
        /* Enable motion interrupt. */
        mpu_lp_motion_interrupt(500, 1, 5);
        /* Notify the MPL that contiguity was broken. */
        inv_accel_was_turned_off();
        inv_gyro_was_turned_off();
        inv_compass_was_turned_off();
        inv_quaternion_sensor_was_turned_off();
        /* Wait for the MPU interrupt. */
        while (!hal.new_gyro) {}
        /* Restore the previous sensor configuration. */
        mpu_lp_motion_interrupt(0, 0, 0);
        hal.motion_int_mode = 0;
    }

    if (!hal.sensors || !hal.new_gyro) {
        continue;
    }    

        if (hal.new_gyro && hal.lp_accel_mode) {
            short accel_short[3];
            long accel[3];
            mpu_get_accel_reg(accel_short, &sensor_timestamp);
            accel[0] = (long)accel_short[0];
            accel[1] = (long)accel_short[1];
            accel[2] = (long)accel_short[2];
            inv_build_accel(accel, 0, sensor_timestamp);
            new_data = 1;
            hal.new_gyro = 0;
        } else if (hal.new_gyro && hal.dmp_on) {
            short gyro[3], accel_short[3], sensors;
            unsigned char more;
            long accel[3], quat[4], temperature;
            /* This function gets new data from the FIFO when the DMP is in
             * use. The FIFO can contain any combination of gyro, accel,
             * quaternion, and gesture data. The sensors parameter tells the
             * caller which data fields were actually populated with new data.
             * For example, if sensors == (INV_XYZ_GYRO | INV_WXYZ_QUAT), then
             * the FIFO isn't being filled with accel data.
             * The driver parses the gesture data to determine if a gesture
             * event has occurred; on an event, the application will be notified
             * via a callback (assuming that a callback function was properly
             * registered). The more parameter is non-zero if there are
             * leftover packets in the FIFO.
             */
            dmp_read_fifo(gyro, accel_short, quat, &sensor_timestamp, &sensors, &more);
            if (!more)
                hal.new_gyro = 0;
            if (sensors & INV_XYZ_GYRO) {
                /* Push the new data to the MPL. */
                inv_build_gyro(gyro, sensor_timestamp);
                new_data = 1;
                if (new_temp) {
                    new_temp = 0;
                    /* Temperature only used for gyro temp comp. */
                    mpu_get_temperature(&temperature, &sensor_timestamp);
                    inv_build_temp(temperature, sensor_timestamp);
                }
            }
            if (sensors & INV_XYZ_ACCEL) {
                accel[0] = (long)accel_short[0];
                accel[1] = (long)accel_short[1];
                accel[2] = (long)accel_short[2];
                inv_build_accel(accel, 0, sensor_timestamp);
                new_data = 1;
            }
            if (sensors & INV_WXYZ_QUAT) {
                inv_build_quat(quat, 0, sensor_timestamp);
                new_data = 1;
            }
        } else if (hal.new_gyro) {
            short gyro[3], accel_short[3];
            unsigned char sensors, more;
            long accel[3], temperature;
            /* This function gets new data from the FIFO. The FIFO can contain
             * gyro, accel, both, or neither. The sensors parameter tells the
             * caller which data fields were actually populated with new data.
             * For example, if sensors == INV_XYZ_GYRO, then the FIFO isn't
             * being filled with accel data. The more parameter is non-zero if
             * there are leftover packets in the FIFO. The HAL can use this
             * information to increase the frequency at which this function is
             * called.
             */
            hal.new_gyro = 0;
            mpu_read_fifo(gyro, accel_short, &sensor_timestamp,
                &sensors, &more);
            if (more)
                hal.new_gyro = 1;
            if (sensors & INV_XYZ_GYRO) {
                /* Push the new data to the MPL. */
                inv_build_gyro(gyro, sensor_timestamp);
                new_data = 1;
                if (new_temp) {
                    new_temp = 0;
                    /* Temperature only used for gyro temp comp. */
                    mpu_get_temperature(&temperature, &sensor_timestamp);
                    inv_build_temp(temperature, sensor_timestamp);
                }
            }
            if (sensors & INV_XYZ_ACCEL) {
                accel[0] = (long)accel_short[0];
                accel[1] = (long)accel_short[1];
                accel[2] = (long)accel_short[2];
                inv_build_accel(accel, 0, sensor_timestamp);
                new_data = 1;
            }
        }
#ifdef COMPASS_ENABLED
        if (new_compass) {
            short compass_short[3];
            long compass[3];
            new_compass = 0;
            /* For any MPU device with an AKM on the auxiliary I2C bus, the raw
             * magnetometer registers are copied to special gyro registers.
             */
            if (!mpu_get_compass_reg(compass_short, &sensor_timestamp)) {
                compass[0] = (long)compass_short[0];
                compass[1] = (long)compass_short[1];
                compass[2] = (long)compass_short[2];
                /* NOTE: If using a third-party compass calibration library,
                 * pass in the compass data in uT * 2^16 and set the second
                 * parameter to INV_CALIBRATED | acc, where acc is the
                 * accuracy from 0 to 3.
                 */
                inv_build_compass(compass, 0, sensor_timestamp);
            }
            new_data = 1;
        }
#endif
        if (new_data) {
            inv_execute_on_data();
            /* This function reads bias-compensated sensor data and sensor
             * fusion outputs from the MPL. The outputs are formatted as seen
             * in eMPL_outputs.c. This function only needs to be called at the
             * rate requested by the host.
             */
            read_from_mpl();
        }
        
 //========================================IMU==================================
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
  

#ifndef USE_Delay
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
static void delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
  for(index = nCount; index != 0; index--)
  {
  }
}
#endif /* USE_Delay*/
  /**
  * @}
  */
  
  
  /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
  
