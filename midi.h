#include "Arduino.h"

#ifndef MIDI_H
#define MIDI_H

class MIDI {

  public:


    void playTone(uint8_t button) {
      //button offset von 3
      uint16_t freq = FREQ[button + 12 * OCTAVE - 3];
      tone(speaker_out, freq);
    }



    void changeOctave(int vector) {
      OCTAVE += vector;
      if (OCTAVE < 1 || OCTAVE > 5)
        OCTAVE += vector * (-1);
    }

    void controllerScan() {
      uint8_t c = input.scanKeys();
      if (c != 0) {
        if (c == CONTROL_UP)
          changeOctave(1);
        else if (c == CONTROL_DOWN)
          changeOctave(-1);
        else if (c == CONTROL_OK)
          stepsampler.settingSteps();
        else if (c >= 1 && c <= 20)
          playTone(c);

      }
      long freqPoti = 2048-   analogRead(POTI_VELOCITY) * 2;
      if(freqPoti > 40){
        isPlaying = HIGH;
        tone(speaker_out, freqPoti);
      }
      else
        isPlaying = LOW;
        

    }

};


MIDI midi;

#endif
