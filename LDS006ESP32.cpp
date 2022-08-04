#include <Arduino.h>
#include "LDS006ESP32.h"

LDS006::LDS006(int pinr, int pint, boolean seri)
{
Serial2.begin(115200, SERIAL_8N1, pinr, pint);
_pinr = pinr;
_pint = pint;
_seri = seri;
}

byte numBytes;
byte receivedBytes[15];
byte numReceived;
boolean newData;


unsigned vit;
unsigned dist;
unsigned refl;
unsigned an;

void LDS006::reading(){
      static boolean recvInProgress = false;
    static byte ndx = 0;
    static byte cpt = 0;
    byte startMarker = 0xFA;
    byte endMarker = 0xFA;
    byte rb;

    while (Serial2.available() > 0 && newData == false) {
    rb = Serial2.read();

      if (recvInProgress == true) {
        if (cpt <= 15){
          //rb != endMarker){
          receivedBytes[ndx] = rb;
          ndx++;
          cpt++;
          if (ndx >= numBytes){
            ndx = numBytes -1;
          }
        }
        else {
          receivedBytes[ndx] = '\0';
          recvInProgress = false;
          numReceived = ndx;
          ndx = 0;
          cpt = 0;
          newData = true;
        }
      }
      else if (rb == startMarker){
        recvInProgress = true;
      }
    }
}

void LDS006::writing(){
  if (newData == true) {
        an = (receivedBytes[0]-160)*4;

        refl = receivedBytes[5]+(receivedBytes[6]*256);
        if (refl > 0 && 0<an<360){
          vit = (receivedBytes[1]+(receivedBytes[2]*256))/100;
          dist = receivedBytes[3]+(receivedBytes[4]*256);

	if (_seri == true){
          Serial.print("Speed: ");Serial.println(vit);
          Serial.print(" Angle: "); Serial.println(an);
          Serial.print(" Distance: ");Serial.println(dist);
      Serial.println();}
        }
        newData = false;
    }

}

void LDS006:: start(){
Serial2.write("startlds$");
if (_seri == true){
Serial.println("Start Lidar");}
}

void LDS006::pause(){
Serial2.write("stoplds$");
if (_seri == true){
Serial.println("Stop Lidar");}
}

unsigned LDS006::distance(void){
	unsigned distance = dist;
	return distance;
}

unsigned LDS006::angle(void){
	unsigned angle = an;
	return angle;
}

unsigned LDS006::speed(void){
	unsigned speed = vit;
	return speed;
}
