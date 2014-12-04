/* Includes ------------------------------------------------------------------*/
#include "gui.h"

#define MAXNODES 100
#define PINGDIV 5
#define PINGRAD 13

static Node nodes[MAXNODES];

static GUIButton topButton;
static GUIButton bottomButton;

static uint16_t nodeLength = 0;
static uint8_t batteryPercent = 50;

static double arrowAngle = 0;
static double lastArrowAngle = 0;

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
  nodes[nodeLength].rping = 0;
  nodes[nodeLength].sping = 0;
  nodeLength++;
  return &nodes[nodeLength];
}


uint16_t GUI_GetNode(uint16_t ID)
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
  return nodeToUpdate;
}

/**
  * @brief Updates node 
  * @param  
  * @retval None
  */
void GUI_UpdateNode(uint16_t ID, double angleRad, uint16_t distance, uint8_t recPing, uint8_t sendPing)
{
  uint16_t nodeToUpdate = GUI_GetNode(ID);
  
  nodes[nodeToUpdate].x = (int16_t) (centerX+distance*sin(angleRad));
  nodes[nodeToUpdate].y = (int16_t) (centerY+distance*cos(angleRad));
  if (recPing > 0 && nodes[nodeToUpdate].rping==0){
    nodes[nodeToUpdate].rping = recPing;
  } else {
    nodes[nodeToUpdate].rping = nodes[nodeToUpdate].rping*recPing;
  }
  if (sendPing > 0 && nodes[nodeToUpdate].sping==0){
    nodes[nodeToUpdate].sping = sendPing;
  } else {
    nodes[nodeToUpdate].sping = nodes[nodeToUpdate].sping*sendPing;
  }

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
  
  if (n->rping > 0)
  {
    for(uint16_t i = 1; i<=(n->rping/PINGDIV); i++)
    {
      LCD_DrawCircle(n->x, n->y, (uint16_t)(20+PINGRAD*i));
    }
    n->rping++;
    if ((n->rping/PINGDIV)>2)
    {
      n->rping = 1;
    }
  }
  
  LCD_SetTextColor(0xFFFF);
  if (n->sping > 0)
  {
    for(uint16_t i = 1; i<=(n->sping/PINGDIV); i++)
    {
      LCD_DrawCircle(n->x, n->y, (uint16_t)(20+PINGRAD*i));
    }
    n->sping++;
    if ((n->sping/PINGDIV)>2)
    {
      n->sping = 1;
    }
  }


  LCD_SetFont(&Avenir);
  LCD_Currentfonts = &Avenir;
  LCD_DrawChar(n->y-13,n->x+12,&LCD_Currentfonts->table[n->fname * LCD_Currentfonts->Height]);
  LCD_DrawChar(n->y+2,n->x+12,&LCD_Currentfonts->table[n->lname * LCD_Currentfonts->Height]);

}

void GUI_ClearNode(Node n)
{
  LCD_SetTextColor(0x0000);
  LCD_DrawFullCircle(n.lastx, n.lasty, 22);
  for(uint16_t i = 1; i<4; i++)
  {
    LCD_DrawCircle(n.lastx, n.lasty, 20+PINGRAD*i);
  }
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
  else if (23 * batteryPercent / 100 > 0)
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


/**
  * @brief  Updates the North Arrow
  * @param  angleRad
  * @retval None
  */
void GUI_UpdateArrow(double angleRad) {
  arrowAngle = angleRad;
}

/**
  * @brief  Draws the North Arrow
  * @param  None
  * @retval None
  */
void GUI_DrawArrow(void) {
  lastArrowAngle = arrowAngle;
  LCD_SetTextColor(0xf800);
  uint16_t x1 = (uint16_t) (115.0 * sin(arrowAngle)+centerX);
  uint16_t y1 = (uint16_t) (115.0 * cos(arrowAngle)+centerY);
  uint16_t x2 = (uint16_t) (100.0 * sin(arrowAngle+0.1)+centerX);
  uint16_t y2 = (uint16_t) (100.0 * cos(arrowAngle+0.1)+centerY);
  uint16_t x3 = (uint16_t) (100.0 * sin(arrowAngle-0.1)+centerX);
  uint16_t y3 = (uint16_t) (100.0 * cos(arrowAngle-0.1)+centerY);
  LCD_FillTriangle(x1, x2, x3, y1, y2, y3);
}

/**
  * @brief  Clears the North Arrow
  * @param  None
  * @retval None
  */
void GUI_ClearArrow(void) {
  LCD_SetTextColor(0x0000);
  uint16_t x1 = (uint16_t) (115.0 * sin(lastArrowAngle)+centerX);
  uint16_t y1 = (uint16_t) (115.0 * cos(lastArrowAngle)+centerY);
  uint16_t x2 = (uint16_t) (100.0 * sin(lastArrowAngle+0.1)+centerX);
  uint16_t y2 = (uint16_t) (100.0 * cos(lastArrowAngle+0.1)+centerY);
  uint16_t x3 = (uint16_t) (100.0 * sin(lastArrowAngle-0.1)+centerX);
  uint16_t y3 = (uint16_t) (100.0 * cos(lastArrowAngle-0.1)+centerY);
  LCD_FillTriangle(x1, x2, x3, y1, y2, y3);
}

/**
  * @brief  Updates the top button
  * @param  textID
  * @param  color
  * @retval None
  */
void GUI_UpdateTopButton(uint8_t textID, uint16_t textColor) {
  topButton.text = textID;
  topButton.color = textColor;
}

/**
  * @brief  Updates the bottom button
  * @param  textID
  * @param  color
  * @retval None
  */
void GUI_UpdateBottomButton(uint8_t textID, uint16_t textColor) {
  bottomButton.text = textID;
  bottomButton.color = textColor;
}

void GUI_DrawButton(void) {
  if (bottomButton.text > 0){
    LCD_SetTextColor(0xdefb);
    LCD_FillTriangle(0, 34, 0, 105, 120, 120);
    LCD_FillTriangle(0, 34, 0, 215, 200, 200);
    LCD_DrawFullRect(0, 120, 35, 80);
    LCD_SetTextColor(bottomButton.color);
    LCD_SetFont(&Avenir);
    LCD_Currentfonts = &Avenir;
    if (bottomButton.text == 1){
      LCD_DrawChar(145,28,&LCD_Currentfonts->table[79 * LCD_Currentfonts->Height]);
      LCD_DrawChar(165,28,&LCD_Currentfonts->table[75 * LCD_Currentfonts->Height]);
    } else if (bottomButton.text == 2){
      LCD_DrawChar(120,28,&LCD_Currentfonts->table[67 * LCD_Currentfonts->Height]);
      LCD_DrawChar(134,28,&LCD_Currentfonts->table[65 * LCD_Currentfonts->Height]);
      LCD_DrawChar(150,28,&LCD_Currentfonts->table[78 * LCD_Currentfonts->Height]);
      LCD_DrawChar(164,28,&LCD_Currentfonts->table[67 * LCD_Currentfonts->Height]);
      LCD_DrawChar(178,28,&LCD_Currentfonts->table[69 * LCD_Currentfonts->Height]);
      LCD_DrawChar(190,28,&LCD_Currentfonts->table[76 * LCD_Currentfonts->Height]);    }
  }
  if (topButton.text > 0){
    LCD_SetTextColor(0xdefb);
    LCD_FillTriangle(240, 206, 240, 105, 120, 120);
    LCD_FillTriangle(240, 206, 240, 215, 200, 200);
    LCD_DrawFullRect(205, 120, 35, 80);
  }
}

void GUI_ClearButton(void) {
  LCD_SetTextColor(0x0000);
  if (bottomButton.text == 0){
    LCD_FillTriangle(0, 34, 0, 105, 120, 120);
    LCD_FillTriangle(0, 34, 0, 215, 200, 200);
    LCD_DrawFullRect(0, 120, 35, 80);
  }
  if (topButton.text == 0){
    LCD_FillTriangle(240, 206, 240, 105, 120, 120);
    LCD_FillTriangle(240, 206, 240, 215, 200, 200);
    LCD_DrawFullRect(205, 120, 35, 80);
  }
}

/** 
  * @brief  Displays the time in the lower left hand corner of the screen
  * @param  None
  * @retval None
  */
void GUI_DrawTime(void) {
  
  // mins is the number of minutes since midnight. Time will be in 24h time.
  uint8_t mins = 66;
  
  LCD_SetTextColor(0xFFFF);
  LCD_SetFont(&Font8x12);
  LCD_Currentfonts = &Font8x12;
  
  LCD_DrawChar( 5,17,&LCD_Currentfonts->table[(mins/60/10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(15,17,&LCD_Currentfonts->table[(mins/60%10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(20,17,&LCD_Currentfonts->table[26 * LCD_Currentfonts->Height]);
  LCD_DrawChar(25,17,&LCD_Currentfonts->table[(mins%60/10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(30,17,&LCD_Currentfonts->table[(mins%60%10 + 16) * LCD_Currentfonts->Height]);
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
  GUI_ClearArrow();
  GUI_ClearButton();
  GUI_DrawArrow();
  GUI_DrawBackground();
  i = 0;
  for(i; i<nodeLength; i++)
  {
    GUI_DrawNode(&nodes[i]);
  }
  GUI_DrawBattery();
  GUI_DrawButton();
  LTDC_Cmd(ENABLE);

}