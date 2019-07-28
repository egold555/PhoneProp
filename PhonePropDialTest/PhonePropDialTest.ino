#include "RotaryDialer.h"

#define PIN_RING 3
#define PIN_DIAL_PULSE 4
#define PIN_DIAL_READY 5
#define PIN_HANGUP 7
#define PIN_EXT 9

RotaryDialer dialer = RotaryDialer(PIN_DIAL_READY, PIN_DIAL_PULSE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Hi"));
  dialer.setup();
}

void loop() {
  if (dialer.update()) {
    Serial.println(dialer.getNextNumber());
  }
}
