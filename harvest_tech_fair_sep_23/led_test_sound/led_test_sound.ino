const int ledPin = 5; // LED connected to digital pin 13
const int soundSensorPin = A0; // Sound sensor connected to analog pin A0
const int lightSensorPin = A2; // Sound sensor connected to analog pin A0
bool ledState = LOW; // State of the LED, initially set to LOW

void setup() {
  pinMode(ledPin, OUTPUT); // sets the digital pin as output
  pinMode(soundSensorPin, INPUT); // sets the analog pin as input
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  int sensorValue = analogRead(soundSensorPin); // read the value from the sound sensor
  int lightSensorValue = analogRead(lightSensorPin); // read the value from the light sensor
  Serial.println(sensorValue); // print the sensor value to the serial monitor

  if (sensorValue > 600) {
    ledState = !ledState; // toggle state of the LED
    digitalWrite(ledPin, ledState); // update the LED state
    delay(500); // add a delay to debounce the sound sensor reading
  }
}
