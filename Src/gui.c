/* Includes ------------------------------------------------------------------*/
#include "gui.h"

#define MAXNODES 100

static Node nodes[MAXNODES];

static uint16_t nodeLength = 0;
static uint8_t batteryPercent = 50;

static sFONT *LCD_Currentfonts;
uint16_t centerX = 120;
uint16_t centerY = 160;

void GUI_DrawBackground(void)
{
  LCD_SetTextColor(0xFFFF);
  LCD_DrawFullCircle(centerX, centerY, 2);
  LCD_DrawCircle(centerX, centerY, 20);
  LCD_DrawCircle(centerX, centerY, 60);
  LCD_DrawCircle(centerX, centerY, 100);
}

void GUI_ClearBackground(void)
{
  LCD_Clear(0x0000);
}

Node * GUI_InitNode(uint16_t ID, uint16_t fname, uint16_t lname, uint16_t color)
{
  nodes[nodeLength].x = centerX;
  nodes[nodeLength].y = centerY; 
  nodes[nodeLength].lastx = centerX;
  nodes[nodeLength].lasty = centerY;
  nodes[nodeLength].id = ID;
  nodes[nodeLength].fname = fname;
  nodes[nodeLength].lname = lname;
  nodes[nodeLength].color = color;
  nodeLength++;
  return &nodes[nodeLength];
}

/**
  * @brief  Draws black over the battery icon
  * @param  None
  * @retval None
  */
void GUI_UpdateNode(uint16_t ID, double angleRad, uint16_t distance)
{
  uint16_t i = 0; 
  uint16_t nodeToUpdate;
  for(i; i<nodeLength; i++)
  {
    if (nodes[i].id == ID)
    {
      nodeToUpdate = i;
      break;
    }
  }
  nodes[nodeToUpdate].x = (int16_t) (centerX+distance*sin(angleRad));
  nodes[nodeToUpdate].y = (int16_t) (centerY+distance*cos(angleRad));
}

void GUI_DrawNode(Node *n)
{
  n->lastx = n->x;
  n->lasty = n->y;
  
  LCD_SetTextColor(0xFFFF);
  LCD_DrawCircle(n->x, n->y, 21);
  LCD_DrawCircle(n->x, n->y, 20);
  LCD_DrawCircle(n->x, n->y, 19);
  LCD_SetTextColor(n->color);
  LCD_DrawFullCircle(n->x, n->y, 20);

  LCD_SetFont(&Avenir);
  LCD_SetTextColor(0xFFFF);
  LCD_Currentfonts = &Avenir;
  LCD_DrawChar(n->y-13,n->x+12,&LCD_Currentfonts->table[n->fname * LCD_Currentfonts->Height]);
  LCD_DrawChar(n->y+2,n->x+12,&LCD_Currentfonts->table[n->lname * LCD_Currentfonts->Height]);
}

void GUI_ClearNode(Node n)
{
  LCD_SetTextColor(0x0000);
  LCD_DrawFullCircle(n.lastx, n.lasty, 22);
}

/**
  * @brief  Updates the battery level
  * @param  None
  * @retval None
  */
void GUI_UpdateBattery(uint8_t battPercent) 
{  
  batteryPercent = battPercent;
}

/**
  * @brief  Draws a battery icon indicating battery level using primatives
  * @param  None
  * @retval None
  */
void GUI_DrawBattery(void) 
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
  if (batteryPercent > 100)
  {
    LCD_DrawFullRect(8, 289, 6, 23);
  }
  else if (batteryPercent > 0)
  {
    LCD_DrawFullRect(8, 289, 6, 23 * batteryPercent / 100);
  }

}

/**
  * @brief  Draws black over the battery icon
  * @param  None
  * @retval None
  */
void GUI_ClearBattery(void) 
{  
  LCD_SetTextColor(0x0000);
  LCD_DrawFullRect(6, 287, 9, 27);
}

void GUI_Redraw(void)
{
  LTDC_Cmd(DISABLE);
  uint16_t i = 0; 
  for(i; i<nodeLength; i++)
  {
    GUI_ClearNode(nodes[i]);
  }
  GUI_ClearBattery();
  GUI_DrawBackground();
  i = 0;
  for(i; i<nodeLength; i++)
  {
    GUI_DrawNode(&nodes[i]);
  }
  GUI_DrawBattery();
  LTDC_Cmd(ENABLE);
}