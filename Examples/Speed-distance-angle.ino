#include <LDS006ESP32.h>

LDS006 lidar(16, 17, false);
void setup() {

Serial.begin(115200);
}

void loop() {

lidar.reading();
lidar.writing();
      static byte rr;
      static boolean ldr;
      while (Serial.available() > 0){ 
      rr = Serial.read();
      if (rr == 's'){
      lidar.start();
      ldr = true;
    }

    if (rr == 'p'){
    lidar.pause();
    ldr = false;
    }
      }
      unsigned distance = lidar.distance();
      unsigned vitesse = lidar.speed();
      unsigned ang = lidar.angle();
      if (ldr == true){
      Serial.println(vitesse);
      Serial.println(distance);
      Serial.println(ang);
      Serial.println();
      }
      delay(500);
}
