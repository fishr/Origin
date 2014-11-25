/* Includes ------------------------------------------------------------------*/
#include "gui.h"

static sFONT *LCD_Currentfonts;


void GUI_DrawBackground(uint16_t centerX, uint16_t centerY)
{
  LCD_SetLayer(LCD_BACKGROUND_LAYER);
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
    
  n.recievedping = false;
  n.sentping = false;
  
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
