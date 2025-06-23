#include <Arduino.h>

const int SOIL_PIN = 4; // pin d4 where the analog out of the soil moisture sensor is connected

// min/max value to be updated as readings are taken while the sensor is dry/submerged
int lowest = 2000;
int highest = 0;

void cal_setup() {
  Serial.begin(9600);
  delay(1000); // Let the sensor and serial stabilize
  for (int i = 0; i < 5; i++) {
    analogRead(SOIL_PIN); // Discard initial garbage reads
    delay(100);
  }
}

void cal_loop() {
  
  int reading = analogRead(SOIL_PIN);
  Serial.println(analogRead(SOIL_PIN));
  if (reading > highest){highest = reading;};
  if (reading < lowest){lowest = reading;};

  if(Serial.available()){
    switch (Serial.read())
    {
    case 'x': 
      Serial.print("Highest: ");
      Serial.println(highest);
      Serial.print("Lowest: ");
      Serial.println(lowest);
    }
  }

  delay(100);
}

