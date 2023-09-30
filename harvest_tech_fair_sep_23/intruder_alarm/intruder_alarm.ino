#include <Wire.h>
#include <rgb_lcd.h>

// Create an LCD object
rgb_lcd lcd;

// Define the pins for the light sensor and buzzer
#define soundBuzzer 4
#define lightSensor A2

int lightValue;
int trigger = 35;
int alarms = 3;
int alarmCount = 0;

void setup() {
  // Initialize the buzzer pin as output
  pinMode(soundBuzzer, OUTPUT);
  // pinMode(lightSensor, INPUT);
  
  // Initialize the LCD
  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(lightSensor);
  Serial.println(lightValue); // Print the light level to the console

  if (lightValue > trigger) {
    while (alarms > alarmCount) {
      // Serial.println(alarms);
      digitalWrite(soundBuzzer, HIGH);
      
      // Set the cursor to column 0, line 1 (the second line)
      lcd.setCursor(0, 1);
      // Print a message to the LCD.
      lcd.print("Intruder!");

      delay(100);
      digitalWrite(soundBuzzer, LOW);
      delay(100);
      alarmCount++;
    }
    alarmCount = 0;
    
    // Clear the message when there is no intruder
    lcd.clear();

    delay(3000);
  }
}
