#include <Arduino.h>

const int PUMP_PIN = 18;

void setup_pump()
{
    pinMode(PUMP_PIN, OUTPUT);
    delay(2000);
}

void loop_pump()
{
    digitalWrite(PUMP_PIN, LOW);
    delay(5000);
    digitalWrite(PUMP_PIN, HIGH);
    delay(5000);
}