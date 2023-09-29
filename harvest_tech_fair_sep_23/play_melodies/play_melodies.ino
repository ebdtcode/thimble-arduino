#define BUZZER_SOCKET 4
// All the code to make a song is in this block
// This plays Ode To Joy
int length = 15; // the number of notes
char notes[] = "eefggfedccdeedd"; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1 };
int tempo = 300;
void setup() {
pinMode(BUZZER_SOCKET, OUTPUT);
for (int i = 0; i < length; i++) {
if (notes[i] == ' ') {
delay(beats[i] * tempo); // rest
} else {
playNote(notes[i], beats[i] * tempo);
}
// pause between notes
delay(tempo / 2);
}
}
void loop() {
}
void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
digitalWrite(BUZZER_SOCKET, HIGH);
delayMicroseconds(tone);
digitalWrite(BUZZER_SOCKET, LOW);
delayMicroseconds(tone);
}
}
void playNote(char note, int duration) {
char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
// play the tone corresponding to the note name
for (int i = 0; i < 8; i++) {
if (names[i] == note) {
playTone(tones[i], duration);
}
}
}
