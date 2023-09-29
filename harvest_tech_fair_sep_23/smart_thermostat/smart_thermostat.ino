#include <Wire.h>
#include "rgb_lcd.h"

#define TEMP_SENSOR A1
#define BUZZER 4
#define ROTARY_ANGLE_SENSOR A0

rgb_lcd lcd;

void setup() {
  lcd.begin(16, 2);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(TEMP_SENSOR); // Read the value from the sensor
  float resistance = (float)(1023-sensorValue)*10000/sensorValue; // Calculate the resistance of the thermistor
  float currentTempF = (9.0/5.0) * (1/(log(resistance/10000)/3975+1/298.15)-273.15) + 32; // Calculate temperature (in Fahrenheit degrees)
  float voltage = analogRead(TEMP_SENSOR);
  float desiredTempF = (analogRead(ROTARY_ANGLE_SENSOR) / 10.24) * 9.0 / 5.0 + 32.0; // Convert the reading to a temperature in °F

  lcd.setCursor(0, 0);
  lcd.print("Current Temp: ");
  lcd.print(currentTempF);

  lcd.setCursor(0, 1);
  lcd.print("Desired Temp: ");
  lcd.print(desiredTempF);

  if (currentTempF > desiredTempF) {
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
    delay(1000);
  }
}
