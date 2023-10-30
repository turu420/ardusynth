/*
   @Akin_Kula
   CT-Project ArduSynth
   Library für Schiebe Register
   der RGB_LED Reihe





*/


#include "Arduino.h"

#ifndef SR74HC595_h
#define SR74HC595_h



class SR74HC595 {
  private:
    int ser;
    int rclk;
    int srclk;
    int srclr;
    int t = 0.0000005;
    void srclkPulse() {
      delay(t);
      digitalWrite(srclk, HIGH);
      delay(t);
      digitalWrite(srclk, LOW);
      delay(t);
    }
    void rclkPulse() {
      delay(t);
      digitalWrite(rclk, HIGH);
      delay(t);
      digitalWrite(rclk, LOW);
      delay(t);
    }
  public:
    SR74HC595(int SER, int RCLK, int SRCLK, int SRCLR) {
      ser = SER;
      rclk = RCLK;
      srclk = SRCLK;
      srclr = SRCLR;
      pinMode(ser, OUTPUT);
      pinMode(rclk, OUTPUT);
      pinMode(srclk, OUTPUT);
      pinMode(srclr, OUTPUT);
      digitalWrite(srclr, HIGH);
    }


    void sendInt(int data) {
      for (int i = 7; i >= 0; i--) {
        if (data >= pow(2, i)) {
          digitalWrite(ser, HIGH);
          data -= pow(2, i);
        }
        else
          digitalWrite(ser, LOW);
        srclkPulse();
      }
      rclkPulse();
    }
    
    void sendWord(int data) {
      for (int i = 15; i >= 0; i--) {
        if (data >= pow(2, i)) {
          digitalWrite(ser, HIGH);
          data -= pow(2, i);
        }
        else
          digitalWrite(ser, LOW);
        srclkPulse();
      }
      rclkPulse();
    }

    void sendBytes(unsigned long long data, int n) {
      for (int i = ((n * 8) - 1); i >= 0; i--) {
        if (data >= pow(2, i)) {
          digitalWrite(ser, HIGH);
          data -= pow(2, i);
        }
        else
          digitalWrite(ser, LOW);
        srclkPulse();
      }
      rclkPulse();
    }
    
    void sendBoolList(bool *list, uint8_t len) {
      for (int i = len; i >= 0; i--) {
        digitalWrite(ser, list[i]);
        srclkPulse();
      }
      rclkPulse();
    }

    void clearRegister() {
      digitalWrite(srclr, LOW);
      delay(t);
      digitalWrite(srclr, HIGH);
      delay(t);
    }

};

//hier bitte die register pins ändern
SR74HC595 shiftRegister(A0, A1, A2, A3);
#endif
