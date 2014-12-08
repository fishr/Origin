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
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

char inData[UART_BUFF_LEN];
uint16_t len=0;

uint8_t elizabethStartFlag=0;

double degrees=0;
unsigned char  new_temp = 0;
unsigned char new_compass = 0;
unsigned long timestamp;

uint8_t ijustreset=1;

char gps_init_msg[75]="$PSRF104,42.359544,-71.0935699,0,96000,79200,1822,12,3*36";

long headingData[3];
int8_t headingAcc=0;
inv_time_t headingTime;

LTDC_ColorKeying_InitTypeDef   LTDC_colorkeying_InitStruct;

origin_t origin_state = {
  .id = ORIGIN_ID,
  .pingnum=0,
  .pingactive=0,
  .whodunnit=0,
  .pingclearedby=0,
  .gpslock=0,
  .lati=KRESGE_LAT,
  .longi=KRESGE_LONG,
};


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void assert_failed(uint8_t*, uint32_t);

#ifndef USE_Delay
static void delay(__IO uint32_t nCount);
#endif /* USE_Delay*/

/* Private functions ---------------------------------------------------------*/

/**
* @brief   Main program
* @param  None
* @retval None
*/
int main(void)
{
  SysTick_Config(SystemCoreClock / 1000);
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

//  GPIO_InitTypeDef  GPIO_InitStructure;
//
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_Init(GPIOE, &GPIO_InitStructure);
//  
//  GPIO_ResetBits(GPIOE, GPIO_Pin_2);  //start with gps off to make sure it activates when wanted
  
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
  //GPIO_SetBits(GPIOE, GPIO_Pin_2); //gps on/off
  GPIO_SetBits(GPIOC, GPIO_Pin_11); //xbee reset
  GPIO_SetBits(GPIOA, GPIO_Pin_10);  //LCD unreset
  UART4_Start();
  UART5_Start();
  MPU_Start();
  
  //========================BUTTONS====================
  InitButton(&button1, GPIOE, GPIO_Pin_4);
#ifdef BOARD_V1
  InitButton(&button2, GPIOE, GPIO_Pin_5);
#else
  InitButton(&button2, GPIOA, GPIO_Pin_9);
#endif
  
  //=======================END BUTTONS==================
  
  
  /* LCD Configuration */
  LCD_Config();
  /* Enable The LCD */
  LTDC_Cmd(ENABLE);
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
  GUI_ClearBackground();
  int count = 0;
  delay(20000);
  
#ifndef ORIGIN    
  GUI_InitNode(1, 72,  83, 0xe8ec);
  GUI_InitNode(2, 86,  72, 0xfd20);
  GUI_InitNode(3, 'R',  'F', 0x001f);
#endif
  
  int screencount = 0;
  
#ifdef INSIDE
  origin_state.lati=KRESGE_LAT;
  origin_state.longi=KRESGE_LONG;
  origin_state.gpslock=1;
#endif
  
  unsigned long tickey2 = getSysTick()+2000;  //2 second counter
  unsigned long tickey3 = getSysTick()+4000;  //4 second delay to check gps state
  
  /* Infinite loop */
  while (1)
  {
    UpdateButton(&button1);
    UpdateButton(&button2);
    
    if( buttonRisingEdge(&button2)){//right
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3);//yellow
      //UART_Transmit(&huart4, gps_init_msg, cmdData1Len, 500);
      origin_state.pingnum+=1;
      origin_state.pingactive=1;
      origin_state.whodunnit = origin_state.id;
      origin_state.pingclearedby = 0;
      GUI_UpdateBottomButton(0, GUI_GetNodeColor(origin_state.id));

    }
    
    if(buttonRisingEdge(&button1)){//left
      //UART_Transmit(&huart4, gps_get_time_msg, cmdData2Len, 500);
      GPIO_ToggleBits(GPIOA, GPIO_Pin_2); //green
      
      if(origin_state.pingactive&&(origin_state.whodunnit != origin_state.id)){
        origin_state.pingactive=0;
        GUI_UpdateBottomButton(0, GUI_GetNodeColor(origin_state.id));
      }
      elizabethStartFlag=1;
    }
    
//    if(origin_state.gpson<3 &&(getSysTick()>tickey3)){
//      GPIO_ResetBits(GPIOE, GPIO_Pin_2);
//      delay(20000);
//      GPIO_SetBits(GPIOE, GPIO_Pin_2);
//      //delay(20000);      
//      //char setme[80];
//      //sprintf(setme, "%s%c%c", gps_init_msg, 0x0D, 0x0A);
//      //UART_Transmit(UART4, setme, sizeof(setme)/sizeof(setme[0]), 5000);
//      origin_state.gpson=0;
//      tickey3+=4000;
//    }
    
    if(getReset()){
      NVIC_SystemReset();
    }
    
#ifdef ORIGIN
//    long actHeading=0;
//    inv_get_sensor_type_heading(&actHeading, &headingAcc, &headingTime);
//    degrees=((double)actHeading)/((double)65536.0);
//    origin_state.heading=degrees;
    
     long actHeading[3] = {0,0,0};
inv_get_sensor_type_euler(actHeading, &headingAcc, &headingTime);
origin_state.heading=((double)actHeading[2])/((double)65536.0);

    long tempyraiture;
    mpu_get_temperature(&tempyraiture, NULL);

//    short garbage[3];
//    mpu_get_compass_reg(garbage, NULL);
//    double compass_angle = atan2(-garbage[0], -garbage[1])*180/3.1415;
//    //origin_state.heading = .9*degrees + .1*compass_angle;
//    origin_state.heading = compass_angle;
#endif
    
    if(getSysTick()>tickey2){
      tickey2 +=1000;
      sendMessage();
#if ORIGIN_ID == USER_ELIZABETH
      if(elizabethStartFlag){
      origin_state.lati -=(2.4100000000023178e-05)/5;
      if(origin_state.lati<42.358104){
        origin_state.lati=42.358104;
      }
      origin_state.longi-=(1.633333333330711e-05)/5;
      if(origin_state.longi<-71.095135){
        origin_state.longi=-71.095135;
      }
      }
#endif
    }
    
      processGPS();
      processXbee();
    
    if(getSysTick()>tickey){
      tickey +=53;
      
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3); 
      
#ifndef ORIGIN
      GUI_UpdateNode(1, degrees*3.1415/180.0+3.14*1.25, screencount, (screencount>10), 0);
      GUI_UpdateNode(2, degrees*3.1415/180.0+3.14, screencount, (screencount>30), 0);
      GUI_UpdateNode(3, degrees*3.1415/180.0+0, screencount, (screencount>50), 0);
#else
      GUI_UpdateNodes();
#endif
      
      
      GUI_UpdateArrow(-origin_state.heading*3.1415/180.0);
      GUI_UpdateBattery(getBatteryStatus(), GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)==Bit_RESET);
      GUI_DrawTime();
      GUI_DrawButton();
      GUI_Redraw();
      
      screencount += 1;
#ifndef ORIGIN
      degrees += 3.6;
      if (screencount%100 == 0){
        screencount  = 0;
        degrees = 0;
      }
#else
      if (screencount%100 == 0){
        screencount  = 0;
      }
#endif
    }

    
    //Sensors_I2C_ReadRegister((unsigned char)0x68, (unsigned char)MPU_WHOAMI, 1, inImu);    
    
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

