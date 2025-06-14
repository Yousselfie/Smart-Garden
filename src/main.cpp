#include <Arduino.h>
#include <calibration_helper.h>

const int SOIL_PIN = 4; // pin d4 where the analog out of the soil moisture sensor is connected

// for calibration: acquired by getting the highest value when the sensor is dry and the lowest value when the sensor is submerged
const int dry= 3271;
const int wet = 1161;


void setup() {
  Serial.begin(9600);
  delay(1000); // Let the sensor and serial stabilize
  for (int i = 0; i < 10; i++) {
    analogRead(SOIL_PIN); // Discard initial garbage reads
    delay(100);
  }
  
}

void loop() {
  
  int reading = analogRead(SOIL_PIN);
  
  // Sensor has a range 1139-3318
  // To translate this to a percentage scale 0-100%, where completely wet is 100%, we use the map function:
  int percentageMoisture = map(reading, wet, dry, 100, 0);

  // constrain the percentage to be between 0 and 100
  percentageMoisture = constrain(percentageMoisture, 0, 100);

  Serial.print(percentageMoisture);
  Serial.println("%");


  delay(100);
  
}

