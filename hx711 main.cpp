#include "Arduino.h"

#define SDA 2
#define SCL 3

//HX711
#include "HX711.h"
int scaleFactor = 1.0;
float getWeight();
int getZero();
int zero = 0;
int sum = 0;
HX711 scale;

//SD Card
#include "FS.h"
#include "SD.h"
#include "SPI.h"
int sck = 14;
int miso = 12;
int mosi = 13;
int cs = 15;
String logMsg;
String dataPacket;

void setup() {
  Serial.begin(9600);

  //HX711
  scale.begin(SDA, SCL);
  scale.set_gain(128);
  Serial.println(getZero());

  //SD Card
  SPI.begin(sck, miso, mosi, cs); // Initialize SPI with fixed pins

}

void loop() {
  Serial.println(getWeight());
  delay(10);
  dataPacket = zero + "/" + getWeight() + "/";
}

int getZero() {
  sum = 0;
  for (int i = 0; i < 10; i++) {
    sum = sum + scale.read();
    delay(100);
  }
  zero = sum / 10;
}

float getWeight() {
  return (scale.read() - zero) / scaleFactor;
}

void logData(); {
  while (!SD.begin(cs)) {}
  File f = SD.open("/MiteOut_Data.txt", FILE_WRITE);
  if (f){
    f.println(dataPacket);
    f.close();
      logMsg = "File written: /MiteOut_Data.txt\n";
      Serial.println(logMsg);
    }
    else{
      logMsg = "Failed to write file\n";
      Serial.println(logMsg);
    }
  }
