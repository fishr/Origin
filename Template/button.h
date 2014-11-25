/* The following parameters tune the algorithm to fit the particular
application.  The example numbers are for a case where a computer samples a
mechanical contact 10 times a second and a half-second integration time is
 
used to remove bounce.  Note: DEBOUNCE_TIME is in seconds and SAMPLE_FREQUENCY
is in Hertz */

#include "stm32f4xx_gpio.h"
 
#ifndef BUTTON_H
#define BUTTON_H

#define DEBOUNCE_TIME       0.001
#define SAMPLE_FREQUENCY    100000
#define MAXIMUM         (DEBOUNCE_TIME * SAMPLE_FREQUENCY)
 
/* These are the variables used */
typedef struct Button{
GPIO_TypeDef* port;
uint16_t pin;
uint16_t input;       /* 0 or 1 depending on the input signal */
uint16_t integrator;  /* Will range from 0 to the specified MAXIMUM */
uint16_t output;      /* Cleaned-up version of the input signal */
uint16_t edge;        /* edge trigger state:0 if untrigged, 1 if active, 2 if already triggered*/
};

extern struct Button button1;
extern struct Button button2;

void InitButton(struct Button *butt, GPIO_TypeDef* port, uint16_t pin);

void UpdateButton(struct Button *butt);

uint16_t getButtonState(struct Button *butt);

uint16_t buttonRisingEdge(struct Button *butt);


#endif