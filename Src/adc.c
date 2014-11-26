#include "adc.h"

void ADC_Start(void)
{
    ADC_InitTypeDef hadc3;
    ADC_CommonInitTypeDef cadc3;
    
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);
    
    //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIO6, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOF, &GPIO_InitStruct);

    ADC_StructInit(&hadc3);
    ADC_CommonStructInit(&cadc3);
    
    hadc3.ADC_Resolution = ADC_Resolution_12b;
    hadc3.ADC_NbrOfConversion = 1;
    hadc3.ADC_DataAlign = ADC_DataAlign_Right;
    cadc3.ADC_Mode = ADC_Mode_Independent;
    cadc3.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_Init(ADC3, &hadc3);
    ADC_CommonInit(&cadc3);


    ADC_Cmd(ADC3, ENABLE);
    ADC_RegularChannelConfig(ADC3, ADC_Channel_4, 1, ADC_SampleTime_480Cycles);
    ADC_ContinuousModeCmd(ADC3, ENABLE);
    ADC_SoftwareStartConv(ADC3);
}


int16_t getBatteryStatus(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_8);
    int16_t batt = ADC_GetConversionValue(ADC3);
    batt = ((batt - 2048)*100)/559; // Maps battery voltage range (3.3,4.2) to (0,100)
    //GPIO_SetBits(GPIOF, GPIO_Pin_8);
    if(batt<0){
      batt=0;
    }else if(batt>100){
      batt=100;
    }
    return batt;
}
