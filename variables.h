#define CONTROL_UP 21
#define CONTROL_DOWN 25
#define CONTROL_LEFT 22
#define CONTROL_RIGHT 24
#define CONTROL_OK 23

#define speaker_out 13

#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62

#define POTI_VELOCITY A4



uint8_t amountOfStepBytes = 0;
uint8_t octave = 3;
long timedelta = 0;
bool pressed = LOW;
uint8_t OCTAVE = 3;

bool isPlaying = LOW;


//C0 ==> C6

const uint16_t FREQ[84] = {
  33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62,
  66, 70, 74, 78, 82, 88, 92, 98, 104, 110, 116,
  124, 131, 139, 147, 155, 163, 175, 183, 195,
  207, 219, 231, 247, 263, 279, 295, 311, 327,
  351, 367, 391, 415, 439, 463, 495, 527, 559,
  591, 623, 655, 703, 735, 783, 831, 879, 927,
  991, 1055, 1119, 1183, 1247, 1311, 1407,
  1471, 1567, 1663, 1759, 1855, 1983, 2111,
  2239, 2367, 2495, 2623, 2815, 2943, 3135,
  3327, 3519, 3711, 3967
};


/*

  Berechnung der Frequenzen:

  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    octave = i * 12;
    FREQ[octave] = NOTE_C1 * pow(2, i);
    FREQ[octave + 1] = NOTE_CS1 * pow(2, i);
    FREQ[octave + 2] = NOTE_D1 * pow(2, i);
    FREQ[octave + 3] = NOTE_DS1 * pow(2, i);
    FREQ[octave + 4] = NOTE_E1 * pow(2, i);
    FREQ[octave + 5] = NOTE_F1 * pow(2, i);
    FREQ[octave + 6] = NOTE_FS1 * pow(2, i);
    FREQ[octave + 7] = NOTE_G1 * pow(2, i);
    FREQ[octave + 8] = NOTE_GS1 * pow(2, i);
    FREQ[octave + 9] = NOTE_A1 * pow(2, i);
    FREQ[octave + 10] = NOTE_AS1 * pow(2, i);
    FREQ[octave + 11] = NOTE_B1 * pow(2, i);
  }
  for(int i=0;i<84;i++){
    Serial.print(FREQ[i]);
    Serial.print(",");
    }


*/
