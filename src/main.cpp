#include <Arduino.h>

#define resPin A0

byte ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte pinCount;

void setup()
{
  Serial.begin(9600);
  pinCount = sizeof(ledPins);
  for (int i = 0; i < pinCount; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }
}

void loop()
{
  int value = analogRead(resPin);
  Serial.println(value);

  int ledIndex = map(value, 0, 1023, 0, pinCount);
  for (int i = 0; i < pinCount; i++)
  {
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledIndex; i < pinCount; i++)
  {
    digitalWrite(ledPins[i], HIGH);
  }
}
