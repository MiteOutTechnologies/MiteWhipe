#include "Arduino.h"
#include "Wire.h"

#define SDA 2
#define SCL 3

//HX711
#include "HX711.h"
int scaleFactor = 1.0;
int zero = 0;
int sum = 0;
HX711 scale;

//SD Card
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#define SCK1 14
#define MISO1 12
#define MOSI1 13
#define CS1 15
String logMsg;
String dataPacket;

//BME
#include "Adafruit_Sensor.h"
#include "Adafruit_BME680.h"
Adafruit_BME680 bme;
int temp = 0;
int humd = 0;

void setup() {
  //Board Setup
  Serial.begin(9600);
  Wire.begin(SDA, SCL);


  //Wire
  Wire.begin(SDA, SCL);

  //HX711
  scale.begin(SDA, SCL);
  scale.set_gain(128);

  //SD Card
  SPI.begin(SCK1, MISO1, MOSI1, CS1);

  //BME
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);

}

int getZero() {
  sum = 0;
  for (int i = 0; i < 10; i++) {
    sum = sum + scale.read();
    delay(100);
  }
  zero = sum / 10;
  return zero;
}

float getWeight() {
  return (scale.read() - zero) / scaleFactor;
}

int getTemp() {
if (bme.performReading()) {
  temp = bme.temperature;
  return temp;
  }
  return -404; // Return a default or error value if reading fails
}

int getHumd() {
if (bme.performReading()) {
  humd = bme.humidity;
  return humd;
  }
  return -404;
}

void logData() {
  while (!SD.begin(CS1)) {}
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



  void loop() {
    dataPacket = String(zero) + "/" + (getWeight()) + "/" + (getTemp()) + "/" + (getHumd());
    logData();
    delay(100);
}
