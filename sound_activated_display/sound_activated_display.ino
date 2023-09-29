#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int pinSound = A2; // Grove - Sound Sensor connected to analog pin A0
const int pinRotary = A1; // Grove - Rotary Angle Sensor connected to analog pin A1

void setup() {
  lcd.begin(16, 2);  
}

void loop() {
  int soundValue = analogRead(pinSound); // Read the value from the sound sensor
  int rotaryValue = analogRead(pinRotary); // Read the value from the rotary angle sensor
  
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Noise Level: ");
  lcd.print(soundValue);
  
  lcd.setCursor(0,1);
  lcd.print("Sensitivity: ");
  lcd.print(rotaryValue);
  
  delay(200);
}
