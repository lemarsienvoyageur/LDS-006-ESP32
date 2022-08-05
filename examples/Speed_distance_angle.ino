/*
Simply write speed, angle and distance on serial monitor
*/

#include <LDS006ESP32.h>

#define TXD2 17
#define RXD2 16

LDS006 lidar(RXD2,TXD2,TRUE);

void setup(){

Serial.begin(115200);
delay(250);
lidar.start(); 
}

void loop(){

lidar.reading();
lidar.writing();
}
