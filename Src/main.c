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

double degrees=0;

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
  
  GPIO_SetBits(GPIOG, GPIO_Pin_3);  //flash deselect
  GPIO_SetBits(GPIOC, GPIO_Pin_8);  //flash #hold off, we have dedicated pins
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
  IMU_Int_Start();
  
  //========================BUTTONS====================
  InitButton(&button1, GPIOE, GPIO_Pin_4);
  InitButton(&button2, GPIOE, GPIO_Pin_5);
  //=======================END BUTTONS==================
  
 
  //======================IMU SETUP===========================
    inv_error_t result;
    unsigned char accel_fsr,  new_temp = 0;
    unsigned short gyro_rate, gyro_fsr;
    unsigned long timestamp;
    struct int_param_s int_param;

#ifdef COMPASS_ENABLED
    unsigned char new_compass = 0;
    unsigned short compass_fsr;
#endif
	
   Set_I2C_Retry(5);
 
  result = mpu_init(&int_param);
  if (result) {
      MPL_LOGE("Could not initialize gyro.\n");
  }
  

    /* If you're not using an MPU9150 AND you're not using DMP features, this
     * function will place all slaves on the primary bus.
     *mpu_set_bypass(1);
    */

  result = inv_init_mpl();
  if (result) {
      MPL_LOGE("Could not initialize MPL.\n");
  }

    /* Compute 6-axis and 9-axis quaternions. */
    inv_enable_quaternion();
    inv_enable_9x_sensor_fusion();
    /* The MPL expects compass data at a constant rate (matching the rate
     * passed to inv_set_compass_sample_rate). If this is an issue for your
     * application, call this function, and the MPL will depend on the
     * timestamps passed to inv_build_compass instead.
     */
      inv_9x_fusion_use_timestamps(1);
     

    /* Update gyro biases when not in motion.
     * WARNING: These algorithms are mutually exclusive.
     */
    inv_enable_fast_nomot();
    /* inv_enable_motion_no_motion(); */
    /* inv_set_no_motion_time(1000); */

    /* Update gyro biases when temperature changes. */
    inv_enable_gyro_tc();

    /* This algorithm updates the accel biases when in motion. A more accurate
     * bias measurement can be made when running the self-test (see case 't' in
     * handle_input), but this algorithm can be enabled if the self-test can't
     * be executed in your application.
     */
     inv_enable_in_use_auto_calibration();
     

    /* Compass calibration algorithms. */
    inv_enable_vector_compass_cal();
    inv_enable_magnetic_disturbance();

    /* Allows use of the MPL APIs in read_from_mpl. */
    inv_enable_eMPL_outputs();

  result = inv_start_mpl();
  if (result == INV_ERROR_NOT_AUTHORIZED) {
      while (1) {
          MPL_LOGE("Not authorized.\n");
      }
  }
  if (result) {
      MPL_LOGE("Could not start the MPL.\n");
  }

    /* Get/set hardware configuration. Start gyro. */
    /* Wake up all sensors. */
    mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);

    /* Push both gyro and accel data into the FIFO. */
    mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    mpu_set_sample_rate(DEFAULT_MPU_HZ);
    /* The compass sampling rate can be less than the gyro/accel sampling rate.
     * Use this function for proper power management.
     */
    mpu_set_compass_sample_rate(1000 / COMPASS_READ_MS);
    
    /* Read back configuration in case it was set improperly. */
    mpu_get_sample_rate(&gyro_rate);
    mpu_get_gyro_fsr(&gyro_fsr);
    mpu_get_accel_fsr(&accel_fsr);
    mpu_get_compass_fsr(&compass_fsr);
    
    /* Sync driver configuration with MPL. */
    /* Sample rate expected in microseconds. */
    inv_set_gyro_sample_rate(1000000L / gyro_rate);
    inv_set_accel_sample_rate(1000000L / gyro_rate);
    
    /* The compass rate is independent of the gyro and accel rates. As long as
     * inv_set_compass_sample_rate is called with the correct value, the 9-axis
     * fusion algorithm's compass correction gain will work properly.
     */
    inv_set_compass_sample_rate(COMPASS_READ_MS * 1000L);

    /* Set chip-to-body orientation matrix.
     * Set hardware units to dps/g's/degrees scaling factor.
     */
    inv_set_gyro_orientation_and_scale(
            inv_orientation_matrix_to_scalar(gyro_pdata.orientation),
            (long)gyro_fsr<<15);
    inv_set_accel_orientation_and_scale(
            inv_orientation_matrix_to_scalar(gyro_pdata.orientation),
            (long)accel_fsr<<15);
    inv_set_compass_orientation_and_scale(
            inv_orientation_matrix_to_scalar(compass_pdata.orientation),
            (long)compass_fsr<<15);

    /* Initialize HAL state variables. */
    hal.sensors = ACCEL_ON | GYRO_ON | COMPASS_ON;
    hal.dmp_on = 0;
    hal.report = 0;
    hal.rx.cmd = 0;
    hal.next_pedo_ms = 0;
    hal.next_compass_ms = 0;
    hal.next_temp_ms = 0;

  /* Compass reads are handled by scheduler. */
  get_tick_count(&timestamp);

    /* To initialize the DMP:
     * 1. Call dmp_load_motion_driver_firmware(). This pushes the DMP image in
     *    inv_mpu_dmp_motion_driver.h into the MPU memory.
     * 2. Push the gyro and accel orientation matrix to the DMP.
     * 3. Register gesture callbacks. Don't worry, these callbacks won't be
     *    executed unless the corresponding feature is enabled.
     * 4. Call dmp_enable_feature(mask) to enable different features.
     * 5. Call dmp_set_fifo_rate(freq) to select a DMP output rate.
     * 6. Call any feature-specific control functions.
     *
     * To enable the DMP, just call mpu_set_dmp_state(1). This function can
     * be called repeatedly to enable and disable the DMP at runtime.
     *
     * The following is a short summary of the features supported in the DMP
     * image provided in inv_mpu_dmp_motion_driver.c:
     * DMP_FEATURE_LP_QUAT: Generate a gyro-only quaternion on the DMP at
     * 200Hz. Integrating the gyro data at higher rates reduces numerical
     * errors (compared to integration on the MCU at a lower sampling rate).
     * DMP_FEATURE_6X_LP_QUAT: Generate a gyro/accel quaternion on the DMP at
     * 200Hz. Cannot be used in combination with DMP_FEATURE_LP_QUAT.
     * DMP_FEATURE_TAP: Detect taps along the X, Y, and Z axes.
     * DMP_FEATURE_ANDROID_ORIENT: Google's screen rotation algorithm. Triggers
     * an event at the four orientations where the screen should rotate.
     * DMP_FEATURE_GYRO_CAL: Calibrates the gyro data after eight seconds of
     * no motion.
     * DMP_FEATURE_SEND_RAW_ACCEL: Add raw accelerometer data to the FIFO.
     * DMP_FEATURE_SEND_RAW_GYRO: Add raw gyro data to the FIFO.
     * DMP_FEATURE_SEND_CAL_GYRO: Add calibrated gyro data to the FIFO. Cannot
     * be used in combination with DMP_FEATURE_SEND_RAW_GYRO.
     */
    dmp_load_motion_driver_firmware();
    dmp_set_orientation(
        inv_orientation_matrix_to_scalar(gyro_pdata.orientation));
    dmp_register_tap_cb(tap_cb);
    dmp_register_android_orient_cb(android_orient_cb);
    
    /*
     * Known Bug -
     * DMP when enabled will sample sensor data at 200Hz and output to FIFO at the rate
     * specified in the dmp_set_fifo_rate API. The DMP will then sent an interrupt once
     * a sample has been put into the FIFO. Therefore if the dmp_set_fifo_rate is at 25Hz
     * there will be a 25Hz interrupt from the MPU device.
     *
     * There is a known issue in which if you do not enable DMP_FEATURE_TAP
     * then the interrupts will be at 200Hz even if fifo rate
     * is set at a different rate. To avoid this issue include the DMP_FEATURE_TAP
     *
     * DMP sensor fusion works only with gyro at +-2000dps and accel +-2G
     */
    hal.dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
        DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
        DMP_FEATURE_GYRO_CAL;
    dmp_enable_feature(hal.dmp_features);
    dmp_set_fifo_rate(DEFAULT_MPU_HZ);
    mpu_set_dmp_state(1);
    hal.dmp_on = 1;
    
    //===============================END IMU============================================
  
    
    
    
    
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
  
    long actHeading=0;
    inv_get_sensor_type_heading(&actHeading, &headingAcc, &headingTime);
    degrees=((double)actHeading)/((double)65536.0);
    
    if(getSysTick()>tickey){
      tickey +=200;
      
      GPIO_ToggleBits(GPIOC, GPIO_Pin_3); 
      //UART_Transmit(idUART5, hello, sizeof(hello)/sizeof(hello[0]), 200);
  

      GUI_UpdateNode(1, degrees*3.1415/180.0+3.14*1.25, count);
      GUI_UpdateNode(2, degrees*3.1415/180.0+3.14, count);
      GUI_UpdateNode(3, degrees*3.1415/180.0+0, count);
      GUI_UpdateBattery(getBatteryStatus());
      GUI_Redraw();
      count += 4;
      if (count%100 == 0){
        count = 0;
      }

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
    
    int g =inImu[0];
    
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
  
