#include "math.h"
#include "origintypes.h"
  
  double   getDir_dbl(double lat1, double long1, double lat2, double long2);
  double   getDist_dbl(double lat1, double lon1, double lat2, double lon2);
  double   getDir_fix(neighbor_t *neigh);
  double   getDist_fix(neighbor_t *neigh);
  double   getDir(neighbor_t *neigh);
  double   getDist(neighbor_t *neigh);