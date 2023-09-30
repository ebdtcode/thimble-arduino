#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123

// Define the pin for the buzzer
#define buzzerPin 2

// notes in the melody:
int melody[] = {
NOTE_C2,-4,NOTE_C2,-4,NOTE_D2,-4,NOTE_C2,-4,NOTE_F2,-4,NOTE_E2,-8,
NOTE_C2,-4,NOTE_C2,-4,NOTE_D2,-4,NOTE_C2,-4,NOTE_G2,-4,NOTE_F2,-8,
NOTE_C2,-4,NOTE_C2,-4,NOTE_C2,-4,NOTE_A2,-4,NOTE_F2,-4,NOTE_E2,-4,NOTE_D2,-8,
NOTE_AS1,-4,NOTE_AS1,-4,NOTE_A1,-4,NOTE_F1,-4,NOTE_G1,-4,NOTE_F1,-8};

void setup() {
pinMode(buzzerPin, OUTPUT);
}

void loop() {
for (int i=0; i<sizeof(melody)/sizeof(int); i+=2) {
tone(buzzerPin,melody[i],1000/melody[i+1]);
delay(1000/melody[i+1]+50);
noTone(buzzerPin);
}
delay(2000); // pause between playings
}
