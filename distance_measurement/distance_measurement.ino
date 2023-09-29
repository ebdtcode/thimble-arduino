#include <Wire.h> // Include the Wire library to communicate with I2C devices
#include "rgb_lcd.h" // Include the library for the RGB LCD

rgb_lcd lcd; // Create an lcd object from the rgb_lcd class

const int pinRanger = 7; // Grove - Ultrasonic Ranger connected to digital pin 7

void setup() { // This function runs once when the Arduino starts
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  pinMode(pinRanger, INPUT); // Set the ranger pin as an input
}

void loop() { // This function runs continuously after setup() finishes
  long duration, distance;
  pinMode(pinRanger, OUTPUT); // Set the ranger pin as an output
  digitalWrite(pinRanger, LOW); // Ensure ranger pin is low
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(pinRanger, HIGH); // Trigger the sensor by setting the ranger pin high for 5 microseconds
  delayMicroseconds(5); 
  digitalWrite(pinRanger, LOW);
  
  pinMode(pinRanger, INPUT); // Set the ranger pin as an input
  duration = pulseIn(pinRanger, HIGH); // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds) from the sending of the ping to the reception of its echo off of an object
  
  distance = duration /29 / 2 ; // Convert time into distance
  
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0,0); // Set cursor to top-left corner
  lcd.print("Distance: "); // Print "Distance: "
  lcd.print(distance); // Print the distance value from sensor
  lcd.print(" cm"); // Print " cm"
  
  delay(500); // Wait for half a second before repeating loop
}
