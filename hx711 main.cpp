/*
 * https://circuits4you.com
 * ESP32 LED Blink Example
 * Board ESP23 DEVKIT V1
 * 
 * ON Board LED GPIO 2
 */
#include <arduino.h>
#include "HX711.h"

#define DT 21
#define SCK 22

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);
}

void loop() {
  scale.set_gain(128); // Set to Channel A
  long readingA = scale.read();

  //scale.set_gain(32); // Switch to Channel B
  //long readingB = scale.read();

  //Serial.print("Mushroom 1: ");
  Serial.println(readingA);
  //Serial.print(",");
  //Serial.print("    Mushroom 2: ");
  //float scaledB = readingB * (128.0 / 32.0);  // Normalize to same gain as A
  //Serial.println(scaledB);

  delay(10); // Adjust sample rate as needed
}
