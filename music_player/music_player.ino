#include <Wire.h> // Include the Wire library to communicate with I2C devices
#include "rgb_lcd.h" // Include the library for the RGB LCD
#include "pitches.h" // This is a library that contains the pitches of the musical notes

rgb_lcd lcd; // Create an lcd object from the rgb_lcd class

const int buzzer = 4; // Buzzer connected to digital pin 9

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4}; // An array to hold the melody

// Note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() { // This function runs once when the Arduino starts
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() { // This function runs continuously after setup() finishes
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0,0); // Set cursor to top-left corner
  lcd.print("Now Playing: "); // Print "Now Playing: "
  
  for (int i = 0; i < 8; i++) { // Loop over the notes in the melody array
    int noteDuration = 1000 / noteDurations[i]; // Calculate how long each note lasts
    tone(buzzer, melody[i], noteDuration); // Play each note on the buzzer
    
    int pauseBetweenNotes = noteDuration * 1.30; // Calculate pause between notes
    delay(pauseBetweenNotes); // Pause between notes
    
    noTone(buzzer); // Stop the tone playing
  }
  
  delay(3000); // Wait for 5 seconds before repeating the loop
}
