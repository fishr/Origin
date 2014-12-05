#include "stdint.h"
#include "user.h"

#ifndef ORIGINTYPES_H
#define ORIGINTYPES_H

typedef struct origin_t origin_t;

struct origin_t {
  uint8_t id;  //id, 0 is reserved for null user
  uint8_t pingnum;  //ping id
  uint8_t pingactive;  //bool
  uint8_t dididoit;  //bool
  uint16_t pingclearedby;  //bitmask
  unsigned long lasttimestamp;
  uint8_t gpslock;  //bool
  float lati;
  float longi;
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
  uint8_t valid;
  char msg[40];
};

extern struct origin_t origin_state;

#endif