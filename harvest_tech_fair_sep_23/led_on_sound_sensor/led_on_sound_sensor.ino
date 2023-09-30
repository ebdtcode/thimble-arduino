const int ledPin = 5; // LED connected to digital pin 13
const int soundSensorPin = A0; // Sound sensor connected to analog pin A0
bool ledState = LOW; // State of the LED, initially set to LOW
void setup() {
  pinMode(ledPin, OUTPUT); // sets the digital pin as output
  pinMode(soundSensorPin, INPUT); // sets the analog pin as input
}

void loop() {
  int sensorValue = analogRead(soundSensorPin); // read the value from the sound sensor
Serial.println(sensorValue);
  if (sensorValue > 800) {
    ledState = !ledState; // toggle state of the LED
    digitalWrite(ledPin, ledState); // update the LED state
    // delay(500); // add a delay to debounce the sound sensor reading
  }
}
