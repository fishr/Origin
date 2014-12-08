#include "stdint.h"
#include "user.h"

#ifndef ORIGINTYPES_H
#define ORIGINTYPES_H

typedef struct neighbor_t neighbor_t;

struct neighbor_t {
  float lati;
  float longi;
  uint8_t active;
  unsigned long lasttime;
};

typedef struct origin_t origin_t;

struct origin_t {
  uint8_t id;  //id, 0 is reserved for null user
  double heading;  //heading in degrees
  uint8_t pingnum;  //ping id
  uint8_t pingactive;  //bool
  uint8_t whodunnit;  //id
  uint16_t pingclearedby;  //bitmask
  unsigned long lasttimestamp;
  uint8_t gpslock;  //bool  //location data is valid
  uint8_t gpson;
  float lati;
  float longi;
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
  uint8_t valid;
  char msg[50];
  neighbor_t neighbors[NEIGHBORS_MAX];
};

extern struct origin_t origin_state;

#endif