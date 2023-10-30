/*
   @Akin_Kula
   CT-Project ArduSynth
   Der Teil ist um die 5x5 (25) Button
   Matrix einzuscannen


*/


#include "Arduino.h"
#ifndef KEYINPUT_h
#define KEYINPUT_h




class KeyInput {
  private:
    byte inputs[5];
    byte grounds[5];
    long pressed_time;
    long press_delay_time = 50;
    int pressed_button = -1;
  public:

    KeyInput(byte i_0, byte i_1, byte i_2, byte i_3, byte i_4, byte  g_0, byte g_1, byte g_2, byte g_3, byte g_4) {
      inputs[0] = i_0;
      inputs[1] = i_1;
      inputs[2] = i_2;
      inputs[3] = i_3;
      inputs[4] = i_4;
      grounds[0] = g_0;
      grounds[1] = g_1;
      grounds[2] = g_2;
      grounds[3] = g_3;
      grounds[4] = g_4;
      for (int i = 0; i < 5; i++) {
        pinMode(inputs[i], INPUT_PULLUP);
      }
      for (int i = 0; i < 5; i++) {
        pinMode(grounds[i], OUTPUT);
      }
      //ALL TO HIGH
      for (int i = 0; i < 5; i++) {
        digitalWrite(grounds[i], HIGH);
      }
      pressed_time = millis();
    }

    int scanKeys() {
      if (millis() - pressed_time >= press_delay_time) {
        pressed_button = -1;
        if (!isPlaying)
          noTone(speaker_out);
      }

      for (int e = 0; e < 5; e++) {
        for (int i = 0; i < 5; i++) {
          digitalWrite(grounds[i], HIGH);
        }

        digitalWrite(grounds[e], LOW);

        for (int r = 0; r < 5; r++) {
          if (digitalRead(inputs[r]) == LOW) {
            pressed_time = millis();
            if (pressed_button != r + e * 5) {
              pressed_button = r + e * 5;
              return pressed_button + 1;
            }
            else
              return -1;
          }
        }

      }
      return -1;
    }


};
//keyboard pins
KeyInput input(12, 11, 10, 9, 8, 7, 6, 5, 4, 3);
#endif
