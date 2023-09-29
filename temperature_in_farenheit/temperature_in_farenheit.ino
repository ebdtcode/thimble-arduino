#include <Wire.h> // Include the Wire library to communicate with I2C devices
#include "rgb_lcd.h" // Include the library for the RGB LCD

rgb_lcd lcd; // Create an lcd object from the rgb_lcd class

const int temperatorSensor = A1; // Grove - Temperature Sensor connected to analog pin A0

void setup() { // This function runs once when the Arduino starts
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() { // This function runs continuously after setup() finishes
  int sensorValue = analogRead(temperatorSensor); // Read the value from the sensor
  float resistance = (float)(1023-sensorValue)*10000/sensorValue; // Calculate the resistance of the thermistor
  float temperature = (9.0/5.0) * (1/(log(resistance/10000)/3975+1/298.15)-273.15) + 32; // Calculate temperature (in Fahrenheit degrees)

  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0,0); // Set cursor to top-left corner
  lcd.print("Temp: "); // Print "Temp: "
  lcd.print(temperature); // Print the temperature value from sensor
  lcd.print(" *F "); // Print " *F "
  
  delay(2000); // Wait for 2 seconds before repeating the loop
}
