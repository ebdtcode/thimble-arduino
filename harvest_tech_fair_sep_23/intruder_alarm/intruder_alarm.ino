//If you use different sockets change them below
#define buzzerSocket 4
#define lightSensorSocket A0
int lightValue;
int trigger = 250;
int alarms = 3;
int alarmCount = 0;
void setup() {
  pinMode(buzzerSocket, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  lightValue = analogRead(lightSensorSocket);
  //Serial.println(lightValue);
  if (lightValue > trigger) {
    while (alarms > alarmCount) {
      Serial.println(alarms);
      digitalWrite(buzzerSocket, HIGH);
      delay(200);
      digitalWrite(buzzerSocket, LOW);
      delay(500);
      alarmCount++;
    }
    alarmCount = 0;
    delay(3000);
  }
}