#include "stdlib.h"
#include "string.h"
#include "user.h"
#include "uart.h"
#include "origintypes.h"


#ifndef GPS_H
#define GPS_H


//extern struct RX_Buff gps_buff;
extern const char gps_init_msg[];
extern const char gps_get_time_msg[];

void UART4_IRQHandler(void);
void parseGPS(char *nmea_string);
void processGPS(void);
char *strsep(char **s, const char *ct);
#endif