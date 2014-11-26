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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GUI_H
#define __GUI_H

#ifdef __cplusplus
 extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "stm32f4xx.h"
#include "stm32f429i_discovery_lcd.h"
#include "fonts.h"
   
typedef struct 
{
  int16_t x;
  int16_t y;
  
  uint16_t id;
  
  uint16_t fname;
  uint16_t lname;
  
  uint16_t color;
    
} Node;   

//#define LCD_DEFAULT_FONT         Font16x24

//#define ASSEMBLE_RGB(R, G, B)    ((((R)& 0xF8) << 8) | (((G) & 0xFC) << 3) | (((B) & 0xF8) >> 3))  
void     GUI_DrawBackground(void);

Node     GUI_InitNode(uint16_t ID, uint16_t fname,  uint16_t lname, uint16_t color);
void     GUI_DrawNode(Node *n);
void     GUI_DrawNodePolar(Node *n, double angleRad, uint16_t distance);
void     GUI_DrawNodexy(Node *n, int16_t X, int16_t Y);

void     GUI_DrawBattery(void);

Node     GUI_GetNodeByID(uint16_t);

//void     LCD_SetLayer(uint32_t Layerx);
//void     LCD_SetColors(uint16_t _TextColor, uint16_t _BackColor); 
//void     LCD_GetColors(uint16_t *_TextColor, uint16_t *_BackColor);
//void     LCD_SetTextColor(uint16_t Color);
//void     LCD_SetBackColor(uint16_t Color);
//void     LCD_SetTransparency(uint8_t transparency);
//void     LCD_ClearLine(uint16_t Line);
//void     LCD_Clear(uint16_t Color);
//uint32_t LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
//void     LCD_SetColorKeying(uint32_t RGBValue);
//void     LCD_ReSetColorKeying(void);
//void     LCD_DrawChar(uint16_t Xpos, uint16_t Ypos, const uint16_t *c);
//void     LCD_DisplayChar(uint16_t Line, uint16_t Column, uint8_t Ascii);
//void     LCD_SetFont(sFONT *fonts);
//sFONT *  LCD_GetFont(void);
//void     LCD_DisplayStringLine(uint16_t Line, uint8_t *ptr);
//void     LCD_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width);
//void     LCD_WindowModeDisable(void);
//void     LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction);
//void     LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width);
//void     LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
//void     LCD_DrawEllipse(int Xpos, int Ypos, int Radius, int Radius2);
//void     LCD_DrawFullEllipse(int Xpos, int Ypos, int Radius, int Radius2);
//void     LCD_DrawMonoPict(const uint32_t *Pict);
//void     LCD_WriteBMP(uint32_t BmpAddress);
//void     LCD_DrawUniLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
//void     LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
//void     LCD_DrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
//void     LCD_PolyLine(pPoint Points, uint16_t PointCount);
//void     LCD_PolyLineRelative(pPoint Points, uint16_t PointCount);
//void     LCD_ClosedPolyLine(pPoint Points, uint16_t PointCount);
//void     LCD_ClosedPolyLineRelative(pPoint Points, uint16_t PointCount);
//void     LCD_FillPolyLine(pPoint Points, uint16_t PointCount);
//void     LCD_Triangle(pPoint Points, uint16_t PointCount);
//void     LCD_FillTriangle(uint16_t x1, uint16_t x2, uint16_t x3, uint16_t y1, uint16_t y2, uint16_t y3);
//void     LCD_WriteCommand(uint8_t LCD_Reg);
//void     LCD_WriteData(uint8_t value);
//void     LCD_PowerOn(void);
//void     LCD_DisplayOn(void);
//void     LCD_DisplayOff(void);
//void     LCD_CtrlLinesConfig(void);
//void     LCD_CtrlLinesWrite(GPIO_TypeDef* GPIOx, uint16_t CtrlPins, BitAction BitVal);
//void     LCD_SPIConfig(void);

#ifdef __cplusplus
}
#endif

#endif /* __GUI_H */
