/* Includes ------------------------------------------------------------------*/
#include "gui.h"

static sFONT *LCD_Currentfonts;


void GUI_DrawBackground(uint16_t centerX, uint16_t centerY)
{
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
  LCD_Clear(0x0000);
  LCD_SetTextColor(0xFFFF);
  
  LCD_DrawFullCircle(centerX, centerY, 2);
  LCD_DrawCircle(centerX, centerY, 20);
  LCD_DrawCircle(centerX, centerY, 60);
  LCD_DrawCircle(centerX, centerY, 100);
}

Node GUI_InitNode(int16_t X, int16_t Y, uint16_t ID, uint16_t fname, uint16_t lname, uint16_t color)
{
  Node n;
  n.x = X;
  n.y = Y;
  
  n.id = ID;
  
  n.fname = fname;
  n.lname = lname;
  
  n.color = color;
    
  return n;
}

void GUI_DrawNode(Node *n, int16_t X, int16_t Y)
{
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
  
  LCD_SetTextColor(0xFFFF);
  LCD_DrawFullCircle(X, Y, 21);
  LCD_SetTextColor(n->color);
  LCD_DrawFullCircle(X, Y, 20);

  LCD_SetFont(&Avenir);
  LCD_SetTextColor(0xFFFF);
  LCD_Currentfonts = &Avenir;
  //LCD_DrawChar(30,30,&LCD_Currentfonts->table[65 * LCD_Currentfonts->Height]);
  LCD_DrawChar(Y-13,X+12,&LCD_Currentfonts->table[n->fname * LCD_Currentfonts->Height]);
  LCD_DrawChar(Y+2,X+12,&LCD_Currentfonts->table[n->lname * LCD_Currentfonts->Height]);
}

/**
  * @brief  Draws a battery icon indicating battery level using primatives
  * @param  None
  * @retval None
  */
void GUI_DrawBattery(int16_t batteryPercent) 
{  
  LCD_SetTextColor(0xFFFF);
  // Horizontal Lines
  LCD_DrawLine(6, 288, 25, 1);
  LCD_DrawLine(15, 288, 25, 1);
  // Vertical Lines
  LCD_DrawLine(7, 287, 8, 0);
  LCD_DrawLine(7, 313, 8, 0);
  // Positive Terminal
  LCD_DrawLine(10, 314, 2, 0);
  // Juice Level
  LCD_DrawFullRect(8, 289, 6, 23 * batteryPercent / 100);
}