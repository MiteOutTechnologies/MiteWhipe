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

void setup() {
  Serial.begin(9600);

  //HX711
  scale.begin(SDA, SCL);
  scale.set_gain(128);
  Serial.println(getZero());
}

void loop() {
  Serial.println(getWeight());
  delay(10); 
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
