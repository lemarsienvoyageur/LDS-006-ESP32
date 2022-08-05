/*
Entry "s" on serial monitor for start lidar and write the data.
Entry "p" on serial monitor for stop lidar and stop writing data.
*/
#include <LDS006ESP32.h>

LDS006 lidar(16, 17, True);
void setup() {

Serial.begin(115200);
}

void loop() {

lidar.reading();
lidar.writing();
      static byte rr;
      while (Serial.available() > 0){ 
      rr = Serial.read();
      if (rr == 's'){
      lidar.start();
    }

    if (rr == 'p'){
    lidar.pause();
    }
      }
}
