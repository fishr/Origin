#include "gps.h"

void parseGPS(char *nmea_string, double *lat, double *longi){
  char nmea_copy[UART_BUFF_LEN];
  strcpy(nmea_copy, nmea_string+2);
  
  char* token;
  const char delim[1] = {','};
  int i =0;
  *lat=0.0;
  *longi=0.0;
  token = (char*)strtok (nmea_copy, delim);
  
  //first field is communication type
  if(strcmp(token, "GPRMC"))
    return;
  
  //4 and 6 are lat long respectively, they are both 
  //followed by a cardinal direction
  while (token != (char*) 0){
    i++;

    token = (char*)strtok ((char *) 0, delim);
    if(i==3){
      *lat=(double) atof(token);
    }else if(i==5){
      *longi = (double) atof(token);
    }
  }
  
  
}
  