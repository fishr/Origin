#include "Button.h"

/* Step 1: Update the integrator based on the input signal.  Note that the
integrator follows the input, decreasing or increasing towards the limits as
determined by the input state (0 or 1). */
 
struct Button button1;
struct Button button2;

void InitButton(struct Button *butt, GPIO_TypeDef* port, uint16_t pin){
  butt->port=port;
  butt->pin=pin;
}

void UpdateButton(struct Button *butt){
  if(butt->edge==1){
    butt->edge=2;
  }
  
  if (HAL_GPIO_ReadPin(butt->port, butt->pin) == GPIO_PIN_RESET)
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
    butt->output = 0;
    butt->edge = 0;
  }
  else if ((butt->integrator) >= MAXIMUM){
      if(butt->edge==0){
        butt->edge=1;
      }
      butt->output = 1;
      butt->integrator = MAXIMUM;  /* defensive code if integrator got corrupted */
    }
}

uint16_t getButtonState(struct Button *butt){
  return butt->output;
}

uint16_t buttonRisingEdge(struct Button *butt){
  return ((butt->edge)==1);
}
  