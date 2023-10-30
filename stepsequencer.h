#include "Arduino.h"

#ifndef STEPSEQUENCER_H
#define STEPSEQUENCER_H

 class StepSampler {
  private:
    uint16_t STEPS[64] = { 0 };
    long step_time = 200;
    long refresh_time = 5;
    long current_refresh_t = millis();
    uint8_t c_step = 0;

    long speed_time = 600;
    long speed_a_over = millis();




    void control(uint8_t c) {
      if (c == CONTROL_RIGHT && c_step < 7)
        c_step++;
      else if (c == CONTROL_LEFT && c_step > 0)
        c_step--;
      else if (c == CONTROL_OK && isPlaying)
        STEPS[c_step] = 0;
      else if (c == CONTROL_UP && OCTAVE < 5)
        OCTAVE++;
      else if (c == CONTROL_DOWN && OCTAVE > 1)
        OCTAVE--;


      //Eine Note Spielen (einspeichern in den Step)
      else if (c >= 1 && c <= 20) {
        STEPS[c_step] =  c + 12 * OCTAVE - 3;
        if (!isPlaying)
          tone(speaker_out, FREQ[STEPS[c_step]], 500);
      }
    }




    void refresh() {
      ledrow.clearBar();
      for (int i = 0; i < 8; i++) {
        if (bool(STEPS[i]) != 0)
          ledrow.setColor(i, 'b');
      }
      ledrow.setColor(c_step, 'r');
      ledrow.sendSerialData();

      uint16_t VELOCITY = analogRead(POTI_VELOCITY);
      if (VELOCITY >= 20 && VELOCITY <= 1000) {
        isPlaying = HIGH;
        speed_time = VELOCITY;
      }
      else if (VELOCITY > 1000)
        isPlaying = LOW;
    }

    void playSteps() {
      c_step++;
      if (c_step == 8)
        c_step = 0;
      if (STEPS[c_step] != 0)
        tone(speaker_out, FREQ[STEPS[c_step]], speed_time);
      speed_a_over = millis();
    }
  public:

    StepSampler() {
      pinMode(POTI_VELOCITY, INPUT);
    }

    void settingSteps() {
      while (1) {
        if ((millis() - speed_a_over > speed_time) && isPlaying)
          playSteps();


        if (millis() - current_refresh_t > refresh_time)
          refresh();
        uint8_t c = input.scanKeys();
        control(c);
        if (c == CONTROL_OK && !isPlaying)
          break;
      }
      ledrow.clearBar();
      ledrow.sendSerialData();
    }

  };

  StepSampler stepsampler;

#endif


