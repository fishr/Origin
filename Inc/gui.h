/**
******************************************************************************
* @file    stm32f429i_discovery_lcd.h
* @author  MCD Application Team
* @version V1.0.1
* @date    28-October-2013
* @brief   This file contains all the functions prototypes for the 
*          stm32f429i_discovery_lcd.c driver.
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
#include <math.h>
#include "stm32f429i_discovery_lcd.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GUI_H
#define __GUI_H

#ifdef __cplusplus
extern "C" {
#endif 

  typedef struct 
  {
    int16_t x;
    int16_t y;
    
    int16_t lastx;
    int16_t lasty;
    
    uint16_t id;
    
    uint16_t fname;
    uint16_t lname;
    
    uint16_t color;
  } Node;
  
  
  void     GUI_DrawBackground(void);
  void     GUI_ClearBackground(void);
  
  Node *   GUI_InitNode(uint16_t ID, uint16_t fname,  uint16_t lname, uint16_t color);
  void     GUI_DeinitNode(Node *n);
  void     GUI_UpdateNode(uint16_t ID, double angleRad, uint16_t distance);
  void     GUI_DrawNode(Node *n);
  void     GUI_ClearNode(Node n);

  void     GUI_UpdateBattery(uint8_t batteryPercent);
  void     GUI_DrawBattery(void);
  void     GUI_ClearBattery(void);

  void     GUI_Redraw(void);
  
  
#ifdef __cplusplus
}
#endif

#endif /* __GUI_H */
