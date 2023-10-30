#include "SR74HC595.h"
#include "variables.h"
#include "keyinput.h"
#include "ledrow.h"
#include "stepsequencer.h"
#include "midi.h"




void setup() {

}

void loop() {
  midi.controllerScan();
}
