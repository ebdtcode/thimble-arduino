//If you use different socket numbers update them below
#define ledSocket 5
#define lightSensorSocket A2
int lowTrigger = 250;   //<- Change to YOUR measured value
int highTrigger = 300;  //<- Change to YOUR measured value
int lightAmount;
int state;
void setup() {
  pinMode(ledSocket, OUTPUT);
}
void loop() {
  lightAmount = analogRead(lightSensorSocket);
  // Print the room light level in the console
  Serial.println(lightAmount);
  if (lightAmount < lowTrigger) {
    state = 1;
  }
  if (lightAmount > highTrigger) {
    state = 0;
  }
  if (state) {
    digitalWrite(ledSocket, HIGH);
  } else {
    digitalWrite(ledSocket, LOW);
  }
}