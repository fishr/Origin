#include "xbee.h"

struct RX_Buff xbee_buff;

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
    xbee_buff.msg_len=gps_buff.length;
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
          //parseXbee(tempmsg);
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

void sendMessage(void){
  //message should consist of id, time, lat, long, pingid
  uint8_t pingid = 0;
  uint8_t pingclearedid = 0;
  if(pingactive){
    pingid=origin_state.pingnum;
  }else{
    pingclearedid=origin_state.pingnum;
  }
  char temp[40];
  uint8_t chars = sprintf(temp, "%c,%02d%02d%02d,%+02.f,%+03.f,%03d,%03d", origin_state.id, 
          origin_state.hours, origin_state.minutes, origin_state.seconds, 
          origin_state.lati, origin_state.longi, pingid, pingclearedid);
  
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
  
  


