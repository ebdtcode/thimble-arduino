// Change here if you're using a different socket
#define DTC_LED 5 // <= digital socket number (D5)
// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin LED_SOCKET as an output.
pinMode(DTC_LED, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
digitalWrite(DTC_LED, HIGH); // turn the LED on (HIGH is the voltage level)
delay(300); // wait for a second
digitalWrite(DTC_LED, LOW); // turn the LED off by making the voltage LOW
delay(300); // wait for a second
}