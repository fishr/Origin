#include "xbee.h"

struct RX_Buff xbee_buff;

static const char delim[]= "*,";

/*void UART5_IRQHandler(void)  //XBEE
{ 
//USART_ITConfig(UART5, USART_IT_RXNE, DISABLE);
//if(USART_GetITStatus(UART5, USART_FLAG_RXNE)==SET){
//USART_ClearITPendingBit(UART5, USART_FLAG_RXNE);
char input = USART_ReceiveData(UART5);
if(tx_buff.rxID<0){
tx_buff.rxID=input;
idFlag = 1;
tx_buff.valid=0;
tx_buff.newData=0;
  }else if(input=='$'){
tx_buff.buffer[0]=tx_buff.rxID;
tx_buff.pointer=1;
tx_buff.buffer[tx_buff.pointer] = input;
tx_buff.pointer++;
idFlag=0;
  }else if(input==0x0A){
if((idFlag)||(tx_buff.valid)){
idFlag=0;
tx_buff.rxID=-1;
tx_buff.pointer=1; 
    }else{
tx_buff.valid=1;
tx_buff.newData=1;
tx_buff.buffer[tx_buff.pointer] = input;
tx_buff.length = tx_buff.pointer+1;    
tx_buff.pointer=1;   
idFlag=0;
switch(tx_buff.rxID){
      case '0':
buff_copy(&tx_buff0, &tx_buff);
friends[0]=&tx_buff0;
break;
      case '1':
buff_copy(&tx_buff1, &tx_buff);
friends[1]=&tx_buff1;
break;
      case '2':
buff_copy(&tx_buff2, &tx_buff);
friends[2]=&tx_buff2;
break;
      case '3':
buff_copy(&tx_buff3, &tx_buff);
friends[3]=&tx_buff3;
break;
      case '4':
buff_copy(&tx_buff4, &tx_buff);
friends[4]=&tx_buff4;
break;
      case '5':
buff_copy(&tx_buff5, &tx_buff);
friends[5]=&tx_buff5;
break;
      case '6':
buff_copy(&tx_buff6, &tx_buff);
friends[6]=&tx_buff6;
break;
      case '7':
buff_copy(&tx_buff7, &tx_buff);
friends[7]=&tx_buff7;
break;
      case '8':
buff_copy(&tx_buff8, &tx_buff);
friends[8]=&tx_buff8;
break;
      case '9':
buff_copy(&tx_buff9, &tx_buff);
friends[9]=&tx_buff9;
break;
      }
tx_buff.rxID=-1;
    }
  }else{
if(idFlag){
idFlag=0;
tx_buff.rxID=-1;
tx_buff.pointer=1; 
    }else{
tx_buff.buffer[tx_buff.pointer] = input; 
(tx_buff.pointer)++;
    }
  }
//}
//USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
}
*/

void UART5_IRQHandler(void)  //GPS
{ 
  //USART_ITConfig(UART5, USART_IT_RXNE, DISABLE);
  
  if(USART_GetITStatus(UART5, USART_IT_ORE_RX)){
    USART_ClearITPendingBit(UART5, USART_IT_ORE_RX);
  }
  //if(USART_GetITStatus(UART5, USART_FLAG_RXNE)){
  //USART_ClearITPendingBit(UART5, USART_FLAG_RXNE);
  char input = USART_ReceiveData(UART5);
  
  if(input=='$'){
    xbee_buff.newData=0;
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
  }else{
    xbee_buff.buffer[xbee_buff.pointer] = input; 
    (xbee_buff.pointer)++;
  }
  //USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
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
  while(i<9){ //currently 8 fields
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
      unsigned long newtime = atol(token);
      if(origin_state.neighbors[id].lasttime>newtime)
        return;
      origin_state.neighbors[id].lasttime=newtime;
      break;
      }
    case 3:
      {
      float templat=atof(token);
      //could put a check to see if lat is +/- .01 from kresge
      if(fabs(templat)<FLT_EPSILON)
        break;
      origin_state.lati=templat;
      break;
      }
    case 4:
      {
      float templong=atof(token);
      //could put a check to see if long is +/- .01 from kresge
      if(fabs(templong)<FLT_EPSILON)
        break;
      origin_state.longi=templong;
      if(fabs(origin_state.longi)>FLT_EPSILON)
        origin_state.neighbors[id].active=1;
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
  uint8_t pingid = 0;
  uint8_t ididit = 0;
  uint8_t pingclearedid = 0;
  if(origin_state.pingactive){
    pingid=origin_state.pingnum;
    ididit=origin_state.whodunnit;
  }else{
    pingclearedid=origin_state.pingnum;
  }
  char temp[50];
  int16_t hi_int_lat = (int16_t)trunc(origin_state.lati);
  uint32_t low_int_lat = (uint32_t)trunc((origin_state.lati-hi_int_lat)*1000000);
  int16_t hi_int_long = (int16_t)trunc(origin_state.longi);
  uint32_t low_int_long = (uint32_t)trunc((origin_state.longi-hi_int_long)*1000000);
  int8_t chars = sprintf(temp, "%c,%02d%02d%02d,%+03d.%06d,%+04d.%06d,%01d,%02d,%02d", origin_state.id, 
                         origin_state.hours, origin_state.minutes, origin_state.seconds, 
                         hi_int_lat, low_int_lat, hi_int_long, low_int_long,
                         ididit, pingid, pingclearedid);
  
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
  sprintf(origin_state.msg, "$%s*%02X", temp, chksum);
  //and send it!
  UART_Transmit(UART5, origin_state.msg, strlen(origin_state.msg), 500);
}




