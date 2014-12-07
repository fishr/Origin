#include "latlong.h"
                      
double getDir(neighbor_t *neigh){
  return getDir_dbl(origin_state.lati, origin_state.longi, neigh->lati, neigh->longi);
}

double getDist(neighbor_t *neigh){
  return getDist_dbl(origin_state.lati, origin_state.longi, neigh->lati, neigh->longi);
}

double getDir_fix(neighbor_t *neigh){
  return getDir_dbl(KRESGE_LAT, KRESGE_LONG, neigh->lati, neigh->longi);
}

double getDist_fix(neighbor_t *neigh){
  return getDist_dbl(KRESGE_LAT, KRESGE_LONG, neigh->lati, neigh->longi);
}
                     
//returns radians i think
double getDir_dbl(double lat1, double long1, double lat2, double long2)
{
    double dy = lat1 - lat2;
    double dx = cos(3.1415/180.*lat1)*(long1 - long2);
    return atan2(dy,dx);
}

double getDist_dbl(double lat1, double lon1, double lat2, double lon2)
{
    lon1 = lon1*3.1415 / 180.0;
    lat1 = lat1*3.1415 / 180.0;
    lon2 = lon2*3.1415 / 180.0;
    lat2 = lat2*3.1415 / 180.0;

    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;

    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
    double c = sin(sqrt(a)) * 2;

    double m = 6367000 * c;
    return m;
}

char *strsep(char **s, const char *ct)
{
  char *sbegin = *s;
  char *end;
  
  if (sbegin == NULL)
    return NULL;
  
  end = strpbrk(sbegin, ct);
  if (end)
    *end++ = '\0';
  *s = end;
  return sbegin;
}