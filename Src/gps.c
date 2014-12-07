#include "gps.h"


char gps_init_msg[61]="$PSRF104,42.359544,-71.0935699,0,96000,79200,1822,12,3*3600"; //init
char gps_get_time_msg[] = "$PSRF103,08,01,00,01*2D00"; //request timing update

const char gprmc[] = "GPRMC";
static const char delim[] = ",*";
static uint8_t firstRun=0;
struct RX_Buff gps_buff;

void UART4_IRQHandler(void)  //GPS
{ 
  //USART_ITConfig(UART4, USART_IT_RXNE, DISABLE);
  
  if(USART_GetITStatus(UART4, USART_IT_ORE_RX)){
    USART_ClearITPendingBit(UART4, USART_IT_ORE_RX);
  }
//  if(USART_GetITStatus(UART4, USART_IT_RXNE)){
//    USART_ClearITPendingBit(UART4, USART_IT_RXNE);
//  }
  char input = USART_ReceiveData(UART4);
  
  if(input=='$'){
    gps_buff.pointer=0;
    gps_buff.buffer[gps_buff.pointer] = input;
    gps_buff.pointer++;  
  }else if(input==0x0A){
    gps_buff.buffer[gps_buff.pointer] = input;
    gps_buff.length = gps_buff.pointer+1;    
    gps_buff.pointer=0;
    gps_buff.lock=1;
    memcpy(gps_buff.msg, gps_buff.buffer, gps_buff.length);
    gps_buff.msg_len=gps_buff.length;
    gps_buff.lock=0;
    gps_buff.newData=1;
  }else if(gps_buff.pointer!=0){
    gps_buff.buffer[gps_buff.pointer] = input; 
    (gps_buff.pointer)++;
  }
  //USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
}

void processGPS(void){
  if(gps_buff.newData&&(!gps_buff.lock)){
    uint16_t len=gps_buff.msg_len;
    char tempmsg[UART_BUFF_LEN];
    memcpy(tempmsg, gps_buff.msg, len);
    gps_buff.newData=0;
    uint8_t chksum = 0;
    int i=1;
    while(i<len){
      if(tempmsg[i]=='*'){
        i++;
        int8_t hn = hexchartohex(tempmsg[i++]);
        int16_t ln = hexchartohex(tempmsg[i]);
        if(hn<0 || ln<0){
          //break data invalid
          break;
        }
        ln |=hn<<4;
        if(ln==chksum){
          //yay
          parseGPS(tempmsg);
          break;
        }else{
          //break data invalid
          break;
        }
      }
      chksum^=(tempmsg[i])&0x7F;
      i++;
    }
    GPIO_ToggleBits(GPIOC, GPIO_Pin_3);
  }
}

void parseGPS(char *nmea_string){
//  if(firstRun){
//    unsigned long tickies=getSysTick()+1000;
//    while(tickies>getSysTick()){}
//  }
  nmea_string+=1;
  char* token;
  int i =0;
  token = (char*)strsep (&nmea_string, delim);
  
  //first field is communication type
if(strcmp(token, gprmc)){
    return;
}
  //nmea_string+=sizeof(token)/sizeof(token[0]);
  //4 and 6 are lat long respectively, they are both 
  //followed by a cardinal direction
  while (i<7){
    i++;
    token = (char*)strsep (&nmea_string, delim);
    if(i==2){
#ifndef INSIDE
      if(strcmp(token, "A")){
        origin_state.gpslock=0;
      }else{
        origin_state.gpslock=1;
      }
#endif
    }else if(token[0]==0){
    }else if(i==1){
      double time=strtod(token, NULL); //time is in hhmmss.sss
      origin_state.hours = (uint8_t) trunc(time/10000.0);
      origin_state.minutes = (uint8_t) trunc((time-10000*origin_state.hours)/100.0);
      origin_state.seconds = (uint8_t) trunc(time-10000*origin_state.hours-100*origin_state.minutes);
    }else if(i==3){
#ifndef INSIDE
      origin_state.lati=strtod(token, NULL);
#endif
    }else if(i==5){
#ifndef INSIDE
      origin_state.longi = -1.0*(strtod(token, NULL));
#endif
    }
  }
}

