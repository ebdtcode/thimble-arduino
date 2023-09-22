#include <Servo.h>
#define servoSocket 6
#define lightSensorSocket A0
Servo robotArm;
int pos;
int val;
int trigger = 100; //<- Change to YOUR measured value
int waveSpeed = 5;
int leftWave = 90;
int rightWave = 0;
void setup() {
robotArm.attach(servoSocket);
}
void loop() {
val = analogRead(lightSensorSocket);
if (val < trigger) {
for (pos = rightWave; pos <= leftWave; pos += 1) {
robotArm.write(pos);
delay(waveSpeed);
}
for (pos = leftWave; pos >= rightWave; pos -= 1) {
robotArm.write(pos);
delay(waveSpeed);
}
for (pos = rightWave; pos <= leftWave; pos += 1) {
robotArm.write(pos);
delay(waveSpeed);
}
}
}
