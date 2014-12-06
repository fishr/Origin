#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "origintypes.h"

#ifndef LATLONG_H
#define LATLONG_H

double   getDir_dbl(double lat1, double long1, double lat2, double long2);
double   getDist_dbl(double lat1, double lon1, double lat2, double lon2);
double   getDir_fix(neighbor_t *neigh);
double   getDist_fix(neighbor_t *neigh);
double   getDir(neighbor_t *neigh);
double   getDist(neighbor_t *neigh);

char *strsep(char **s, const char *ct);

#endif