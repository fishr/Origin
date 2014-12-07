#include "xbee.h"

struct RX_Buff xbee_buff;

static const char delim[]= "*,";

void UART5_IRQHandler(void)  //xbee
{ 
  //USART_ITConfig(UART5, USART_IT_RXNE, DISABLE);
  
  if(USART_GetITStatus(UART5, USART_IT_ORE_RX)){
    USART_ClearITPendingBit(UART5, USART_IT_ORE_RX);
  }
  //if(USART_GetITStatus(UART5, USART_FLAG_RXNE)){
  //USART_ClearITPendingBit(UART5, USART_FLAG_RXNE);
  char input = USART_ReceiveData(UART5);
  
  if(input=='$'){
    xbee_buff.pointer=0;
    xbee_buff.buffer[xbee_buff.pointer] = input;
    xbee_buff.pointer++;  
  }else if(input==0x0A){
    xbee_buff.buffer[xbee_buff.pointer] = input;
    xbee_buff.length = xbee_buff.pointer+1;    
    xbee_buff.pointer=0;
    xbee_buff.lock=1;
    memcpy(xbee_buff.msg, xbee_buff.buffer, xbee_buff.length);
    xbee_buff.msg_len=xbee_buff.length;
    xbee_buff.lock=0;
    xbee_buff.newData=1;
  }else if(xbee_buff.pointer!=0){
    xbee_buff.buffer[xbee_buff.pointer] = input; 
    (xbee_buff.pointer)++;
  }
  //USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
}

void processXbee(void){
  if(xbee_buff.newData&&(!xbee_buff.lock)){
    uint16_t len=xbee_buff.msg_len;
    char tempmsg[UART_BUFF_LEN];
    memcpy(tempmsg, xbee_buff.msg, len);
    xbee_buff.newData=0;
    uint8_t chksum = 0;
    int i=1;
    while(i<len){
      if(tempmsg[i]=='*'){
        i++;
        int8_t hn = hexchartohex(tempmsg[i++]);
        int8_t ln = hexchartohex(tempmsg[i]);
        if(hn<0 || ln<0){
          //break data invalid
          break;
        }
        ln |=hn<<4;
        if(ln==chksum){
          //yay
          parseXbee(tempmsg);
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

void parseXbee(char *xbee_string){
  xbee_string+=1;
  char* token;
  int i =0;
  uint8_t id;
  float templong;
  float templat;
  uint8_t pingid;
  uint8_t pingclearer;
  unsigned long newtime;
  while(i<8){ //currently 7 fields
    i++;
    
    token = (char*)strsep (&xbee_string, delim);
    switch(i){
    case 1:
      {
      id=atoi(token);
      if(id>=NEIGHBORS_MAX)
        return;
      break;
      }
    case 2:
      {
      newtime = atol(token);
      if(origin_state.neighbors[id].lasttime>newtime)
        return;
      origin_state.neighbors[id].lasttime=newtime;
      break;
      }
    case 3:
      {
      templat=atof(token);
      //could put a check to see if lat is +/- .01 from kresge
      if(fabs(templat)<FLT_EPSILON)
        return;
      origin_state.neighbors[id].lati=templat;
      break;
      }
    case 4:
      {
      templong=atof(token);
      //could put a check to see if long is +/- .01 from kresge
      if(fabs(templong)<FLT_EPSILON)
        return;
      origin_state.neighbors[id].longi=templong;
      if(fabs(origin_state.neighbors[id].lati)>FLT_EPSILON)
        origin_state.neighbors[id].active=1;
      break;
      }
    case 5: 
      {
        pingid = atol(token);
        if(pingid<origin_state.pingnum){
          return;
        }
        break;
      }
    case 6:
      {
        if(pingid>origin_state.pingnum){
          origin_state.pingnum=pingid;
          origin_state.pingclearedby=0;
          origin_state.pingactive=1;
          origin_state.whodunnit = atol(token);
        }
        break;
      }
    case 7:
      {
        pingclearer=atol(token);
        if(pingclearer==origin_state.pingnum){
          origin_state.pingclearedby |= 1<<id;
        }
        break;
      }
    default:
      //this will be catching the rest of the message for now (eg ping stuff)
      break;
    }
  }
}

void sendMessage(void){
  //message should consist of id, time, lat, long, pingid
  uint8_t pingclearedid = 0;
  if(!origin_state.pingactive){
    pingclearedid=origin_state.pingnum;
  }
  char temp[50];
  int16_t hi_int_lat = (int16_t)trunc(origin_state.lati);
  uint32_t low_int_lat = (uint32_t)trunc((origin_state.lati-hi_int_lat)*1000000.0);
  int16_t hi_int_long = (int16_t)trunc(origin_state.longi);
  uint32_t low_int_long = (uint32_t)fabs(trunc((origin_state.longi-hi_int_long)*1000000.0));
  int8_t chars = sprintf(temp, "%d,%02d%02d%02d,%+03d.%06d,%+04d.%06d,%02d,%d,%02d", origin_state.id, 
                         origin_state.hours, origin_state.minutes, origin_state.seconds, 
                         hi_int_lat, low_int_lat, hi_int_long, low_int_long,
                         origin_state.pingnum, origin_state.whodunnit, pingclearedid);
  
  uint8_t i=0;
  uint8_t chksum =0;
  if(chars<0){
    //oops
    while(1){}
  }else{
    while(i<chars){
      chksum^=(temp[i])&0x7F;
      i++;
    }
  }
  sprintf(origin_state.msg, "$%s*%02X%c%c", temp, chksum, 0x0A, 0x0D);
  //and send it!
  UART_Transmit(UART5, origin_state.msg, strlen(origin_state.msg), 500);
}




