

#ifndef USER_H
#define USER_H

//change these values

#define UART_BUFF_LEN 128
#define ORIGIN_ID 2  //MUST BE 1-7, and unique to each band
#define RESET_TIME 5000  //hard reset delay for button press
#define NEIGHBORS_MAX 6
//#define KRESGE_LAT 42.358094
#define KRESGE_LAT 42.3585
#define KRESGE_LONG -71.094980

//comment out these values

#define ORIGIN  //if this is an origin as opposed to a discovery board
//#define BOARD_V1  //if this is a V1 circuit board
#define BOARD_V3
#define INSIDE //if the unit will be inside kresge

#endif