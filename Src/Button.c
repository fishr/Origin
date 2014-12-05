#include "button.h"

/* Step 1: Update the integrator based on the input signal.  Note that the
integrator follows the input, decreasing or increasing towards the limits as
determined by the input state (0 or 1). */

struct Button button1;
struct Button button2;

void InitButton(struct Button *butt, GPIO_TypeDef* port, uint16_t pin){
  butt->port=port;
  butt->pin=pin;
  
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Pin = pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(port, &GPIO_InitStructure);
}

void UpdateButton(struct Button *butt){
  
  if(butt->edge==BUTTON_RISING){
    butt->edge=BUTTON_PRESSED;
  }else if (butt->edge==BUTTON_FALLING){
    butt->edge=BUTTON_UNPRESSED;
  }
  
  if (GPIO_ReadInputDataBit(butt->port, butt->pin) == RESET)
  {
    if ((butt->integrator) > 0)
      (butt->integrator)--;
  }
  else if ((butt->integrator) < MAXIMUM)
    (butt->integrator)++;
  
  /* Step 2: Update the output state based on the integrator.  Note that the
  output will only change states if the integrator has reached a limit, either
  
  0 or MAXIMUM. */
  
  
  
  if (butt->integrator == 0){
    if(butt->output==1){
      butt->edge = BUTTON_FALLING;
    }
    butt->output = 0;
  }
  else if ((butt->integrator) >= MAXIMUM){
    if(butt->edge==BUTTON_UNPRESSED){
      butt->startTime=getSysTick();
      butt->edge=BUTTON_RISING;
    }
    butt->output = 1;
    butt->integrator = MAXIMUM;  /* defensive code if integrator got corrupted */
  }
}

uint16_t getButtonState(struct Button *butt){
  return butt->output;
}

unsigned long getPressDuration(struct Button *butt){
  if(butt->output==0)
    return 0;
  return (getSysTick()-butt->startTime);
}

uint16_t buttonRisingEdge(struct Button *butt){
  return ((butt->edge)==BUTTON_RISING);
}

uint16_t buttonFallingEdge(struct Button *butt){
  return ((butt->edge)==BUTTON_FALLING);
}

uint8_t getReset(void){
  if(getButtonState(&button1)+getButtonState(&button2)){
    if((getPressDuration(&button1)>RESET_TIME)&&(getPressDuration(&button2)>RESET_TIME)){
      return 1;
    }else{
      return 0;
    }
  }
  return 0;
}
