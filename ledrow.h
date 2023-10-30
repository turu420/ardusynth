#include "Arduino.h"

#ifndef LEDROW_H
#define LEDROW_H


class LedRow {


  public:
    uint8_t LED[8];
    void sendSerialData() {

      bool data[] = {
        (bitRead(LED[0], 0) << 0), ( bitRead(LED[0], 1) << 1), ( bitRead(LED[0], 2) << 2), ( bitRead(LED[1], 0) << 3), ( bitRead(LED[1], 1) << 4), ( bitRead(LED[1], 2) << 5), ( bitRead(LED[2], 0) << 6), ( bitRead(LED[2], 1) << 7),
        (bitRead(LED[2], 2) << 0), ( bitRead(LED[3], 0) << 1), ( bitRead(LED[3], 1) << 2), ( bitRead(LED[3], 2) << 3), ( bitRead(LED[4], 0) << 4), ( bitRead(LED[4], 1) << 5), ( bitRead(LED[4], 2) << 6), ( bitRead(LED[5], 0) << 7),
        (bitRead(LED[5], 1) << 0), ( bitRead(LED[5], 2) << 1), ( bitRead(LED[6], 0) << 2), ( bitRead(LED[6], 1) << 3), ( bitRead(LED[6], 2) << 4), ( bitRead(LED[7], 0) << 5), ( bitRead(LED[7], 1) << 6), ( bitRead(LED[7], 2) << 7),
      };

      shiftRegister.sendBoolList(data, 24);
    }

    LedRow() {
      shiftRegister.sendBytes(0, 3);
    }

    void setColor(uint8_t lednum, char color) {
      uint8_t c;
      if (color == '0' || color == 0)
        c = 0b000;
      else if (color == 'r')
        c = 0b001;
      else  if (color == 'g')
        c = 0b010;
      else if (color == 'b')
        c = 0b100;
      else if (color == 'c')
        c = 0b110;
      else if (color == 'v')
        c = 0b101;
      else if (color == 'y')
        c = 0b110;
      else if (color == 'w')
        c = 0b111;
      LED[lednum] = c;

      //send directly after calling this function
      //sendSerialData();
    }
    void clearBar() {
      for (int i = 0; i < 8; i++) {
        LED[i] = 0;
      }
      shiftRegister.clearRegister();

    }

};

//LED Row controller
LedRow ledrow;
#endif
