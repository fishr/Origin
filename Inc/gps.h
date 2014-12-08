#include "user.h"
#include "uart.h"
#include "stdio.h"
#include "origintypes.h"
#include "latlong.h"

#ifndef GPS_H
#define GPS_H


//extern struct RX_Buff gps_buff;
//extern char gps_init_msg[75];
//extern char gps_get_time_msg[];

void UART4_IRQHandler(void);
void parseGPS(char *nmea_string);
void processGPS(void);
#endif