#include "stdlib.h"
#include "string.h"
#include "user.h"


#ifndef GPS_H
#define GPS_H

void parseGPS(char *nmea_string, double *lat, double *longi);

#endif