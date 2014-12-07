/* Includes ------------------------------------------------------------------*/
#include "gui.h"

#define MAXNODES 100
#define PINGDIV 5
#define PINGRAD 13

static Node nodes[MAXNODES];

static GUIButton topButton;
static GUIButton bottomButton;
static uint8_t topButtonDirty = 0;
static uint8_t bottomButtonDirty = 0;

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
  if(ID>MAXNODES)
    return NULL;
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
  return &nodes[nodeLength-1];
}

//gets the index from the storage array of the given node id
//returns -1 in the event of a failure
int16_t GUI_GetNode(uint16_t ID)
{
  uint16_t nodeToUpdate;
  for(uint16_t i=0; i<nodeLength; i++)
  {
    if (nodes[i].id == ID)
    {
      return i;
    }
  }
  return -1;
}

/**
  * @brief Updates node 
  * @param  
  * @retval None
  */
void GUI_UpdateNode(uint16_t ID, double angleRad, uint16_t distance, uint8_t recPing, uint8_t sendPing)
{
  int16_t nodeToUpdate = GUI_GetNode(ID);
  
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

void GUI_UpdateNodes(void){
  for(int i=1; i<NEIGHBORS_MAX; i++){
    if(origin_state.neighbors[i].active){
      int16_t index=GUI_GetNode(i);
      if(index<0){
        GUI_InitNode(i, 'R', 'F', (0xF<<i));
      }
      uint8_t recPing=0;
      uint8_t sentPing=0;
      if(origin_state.pingactive){
        if((origin_state.whodunnit==ORIGIN_ID)&&!(origin_state.pingclearedby&(1<<i))){
          recPing=1;
        }else if(!(origin_state.whodunnit==ORIGIN_ID)){
          sentPing=1;
        }
      }
      if(origin_state.gpslock){
       GUI_UpdateNode(i, getDir(&origin_state.neighbors[i])+(3.1415*origin_state.heading/180.0),
                     getDist(&origin_state.neighbors[i]), recPing, sentPing);
      }else{
       GUI_UpdateNode(i, getDir_fix(&origin_state.neighbors[i])+(3.1415*origin_state.heading/180.0),
                      getDist_fix(&origin_state.neighbors[i]), recPing,sentPing);
      }
    }
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
    LCD_SetFont(&Avenir);
    LCD_Currentfonts = &Avenir;
    if (bottomButton.text == 1){ //"OK"
      uint16_t width = 50;
      uint16_t startY = (LCD_PIXEL_HEIGHT-width)/2;
      uint16_t endY = (LCD_PIXEL_HEIGHT+width)/2;
      LCD_FillTriangle(0, 34, 0, startY-15, startY, startY);
      bottomButtonDirty = 1;
      LCD_FillTriangle(0, 34, 0, endY+15, endY, endY);
      LCD_DrawFullRect(0, startY, 35, width);
      LCD_SetTextColor(bottomButton.color);
      LCD_DrawChar(147,28,&LCD_Currentfonts->table[79 * LCD_Currentfonts->Height]);
      LCD_DrawChar(163,28,&LCD_Currentfonts->table[75 * LCD_Currentfonts->Height]);
    } else if (bottomButton.text == 2){ //"CANCEL"
      uint16_t width = 80;
      uint16_t startY = (LCD_PIXEL_HEIGHT-width)/2;
      uint16_t endY = (LCD_PIXEL_HEIGHT+width)/2;
      LCD_FillTriangle(0, 34, 0, startY-15, startY, startY);
      bottomButtonDirty = 1;
      LCD_FillTriangle(0, 34, 0, endY+15, endY, endY);
      LCD_DrawFullRect(0, startY, 35, width);
      LCD_SetTextColor(bottomButton.color);
      LCD_DrawChar(120,28,&LCD_Currentfonts->table[67 * LCD_Currentfonts->Height]);
      LCD_DrawChar(134,28,&LCD_Currentfonts->table[65 * LCD_Currentfonts->Height]);
      LCD_DrawChar(150,28,&LCD_Currentfonts->table[78 * LCD_Currentfonts->Height]);
      LCD_DrawChar(164,28,&LCD_Currentfonts->table[67 * LCD_Currentfonts->Height]);
      LCD_DrawChar(178,28,&LCD_Currentfonts->table[69 * LCD_Currentfonts->Height]);
      LCD_DrawChar(190,28,&LCD_Currentfonts->table[76 * LCD_Currentfonts->Height]);    }
  }
  if (topButton.text > 0){
    LCD_SetTextColor(0xdefb);
    
    uint16_t width = 80;
    uint16_t startY = (LCD_PIXEL_HEIGHT-width)/2;
    uint16_t endY = (LCD_PIXEL_HEIGHT+width)/2;
    LCD_FillTriangle(240, 206, 240, startY-15, startY, startY);
    topButtonDirty = 1;
    LCD_FillTriangle(240, 206, 240, endY+15, endY, endY);
    LCD_DrawFullRect(205, startY, 35, width);
  }
}

void GUI_ClearButton(void) {
  LCD_SetTextColor(0x0000);
  if ((bottomButton.text == 0) && (bottomButtonDirty == 1)){
    LCD_DrawFullRect(0, 120, 35, 80);
    bottomButtonDirty = 0;
  }
  if ((topButton.text == 0) && (topButtonDirty == 1)){
    LCD_DrawFullRect(205, 120, 35, 80);
    topButtonDirty = 0;
  }
}

/** 
  * @brief  Displays the time in the lower left hand corner of the screen
  * @param  None
  * @retval None
  */
void GUI_DrawTime(void) {
  LCD_SetTextColor(0x0000);
  LCD_DrawFullRect(5, 0, 12, 35);
  
  // mins is the number of minutes since midnight. Time will be in 24h time.
  uint16_t mins = origin_state.minutes+origin_state.hours*60;
  
  LCD_SetTextColor(0xFFFF);
  LCD_SetFont(&Font8x12);
  LCD_Currentfonts = &Font8x12;
  
  LCD_DrawChar(9,17,&LCD_Currentfonts->table[(mins/60/10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(15,17,&LCD_Currentfonts->table[(mins/60%10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(20,17,&LCD_Currentfonts->table[26 * LCD_Currentfonts->Height]);
  LCD_DrawChar(25,17,&LCD_Currentfonts->table[((mins%60)/10 + 16) * LCD_Currentfonts->Height]);
  LCD_DrawChar(31,17,&LCD_Currentfonts->table[((mins%60)%10 + 16) * LCD_Currentfonts->Height]);
}

void GUI_Redraw(void)
{
  while ((LTDC->CPSR & 0xFFFF) != 0){}
  LTDC_Cmd(DISABLE);
   
  for(uint16_t i = 0; i<nodeLength; i++)
  {
    GUI_ClearNode(nodes[i]);
  }
  GUI_ClearBattery();
  GUI_ClearArrow();
  GUI_ClearButton();
  GUI_DrawArrow();
  GUI_DrawBackground();
  for(uint16_t i = 0; i<nodeLength; i++)
  {
    GUI_DrawNode(&nodes[i]);
  }
  GUI_DrawBattery();
  GUI_DrawButton();
  LTDC_Cmd(ENABLE);

}