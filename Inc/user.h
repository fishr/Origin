

#ifndef USER_H
#define USER_H

#define UART_BUFF_LEN 128

#define USER_VICTOR 1
#define USER_ELIZABETH 2
#define USER_NATASHA 3
#define USER_CHARLES 4

//change these values

#define ORIGIN_ID  USER_ELIZABETH //MUST BE 1-7, and unique to each band

#define RESET_TIME 5000  //hard reset delay for button press
#define NEIGHBORS_MAX 6

#if (ORIGIN_ID == USER_VICTOR)||(ORIGIN_ID == USER_CHARLES)
#define KRESGE_LAT 42.358104
#elif (ORIGIN_ID == USER_ELIZABETH)
#define KRESGE_LAT 42.358827
#else
#define KRESGE_LAT 42.3575
#endif

#if (ORIGIN_ID == USER_NATASHA)||(ORIGIN_ID == USER_VICTOR)
#define KRESGE_LONG -71.095135
#elif (ORIGIN_ID == USER_ELIZABETH)
#define KRESGE_LONG -71.094645
#else
#define KRESGE_LONG -71.09448
#endif

//comment out these values

#define ORIGIN  //if this is an origin as opposed to a discovery board
//#define BOARD_V1  //if this is a V1 circuit board
#define BOARD_V3

#if (ORIGIN_ID == USER_VICTOR) || (ORIGIN_ID == USER_NATASHA)|| (ORIGIN_ID == USER_ELIZABETH)
#define INSIDE //if the unit will be inside kresge
#endif

#endif