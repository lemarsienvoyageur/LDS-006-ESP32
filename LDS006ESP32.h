/*
    LDS006 - Library to pilot and operates an lds-006 lidar on ESP32.
    Creat by B.DHONDT (le marsien voyageur), August 04, 2022.
    licence à determiner
*/

#ifndef LDS006ESP32_h
#define LDS006ESP32_h

#include <Arduino.h>

class LDS006
{
  public:
  LDS006(int pinr, int pint, boolean ser);
  void reading();
  void writing();
  void start();
  void pause();
  unsigned distance(void);
  unsigned angle(void);
  unsigned speed(void);
  unsigned vit = 0;
  unsigned dist = 0;
  unsigned an = 0;
  unsigned refl = 0;
  private:
  int _pinr;
  int _pint;
  boolean _seri;
  const byte numBytes = 15;
  byte receivedBytes[15] = {};
  byte numReceived = 0;
  boolean newData = false;
  unsigned pos = 0;
};

#endif
