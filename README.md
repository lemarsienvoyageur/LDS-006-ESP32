# LDS006ESP32
library esp32 for LDS-006

using the lidar lds-006 with an ESP32

Based on the work of Aluminium-z https://github.com/Aluminum-z/Laser-Radar-LDS-006-Drive-Test

In this code, a distance, a position angle and a notion of rotation speed are shown.

The "angle" variable is entered from 0 to 360° in steps of 4 (0 4 8 12 ... 356 360)

The "distance" variable is entered in centimeters from 2 to 6000.

The "speed" variable is recovered in order to verify the reliability of the distance data.

These three variables are written to the serial monitor as they comming in the buffer if the boolean in LDS006(int RXpin, int TXpin, boolean Serial) is true

The lidar work in Serial 115200 8N2 3.3V.

Example

#include <LDS006ESP32>

#define TXD2 17

#define RXD2 16

LDS006 lidar(RXD2,TXD2,TRUE)

void setup(){

Serial.begin(115200);

}

void loop(){

lidar.reading();
lidar.writing();

}
