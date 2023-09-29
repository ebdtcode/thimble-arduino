#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int sensorPin = A0; // Grove - Temperature Sensor connected to analog pin A0

void setup() {
  lcd.begin(16, 2);  
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float resistance = (float)(1023-sensorValue)*10000/sensorValue;
  float temperature = 1/(log(resistance/10000)/3975+1/298.15)-273.15; // Calculate temperature (in Celsius degrees)

  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" *C ");
  
  delay(2000);
}
