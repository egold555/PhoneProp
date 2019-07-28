
#define PIN_RING 3
#define PIN_DIAL_PULSE 4
#define PIN_DIAL_READY 5
#define PIN_HANGUP 7
#define PIN_EXT 9

//Ringing constants to match the US ringing 20hz
const int delayTime = 1000 / (20 * 2);
const long ringLength = 2000;
const int nonRingLength = 4000;

void ringOnce() {
  digitalWrite(PIN_RING, HIGH);
  delay(delayTime);
  digitalWrite(PIN_RING, LOW);
  delay(delayTime);
}

void ringCall() {
  long tm = millis();

  while (millis() - tm < ringLength) {
    ringOnce();
  }
  delay(nonRingLength);
}

void setup() {
  pinMode(PIN_RING, OUTPUT);
  pinMode(PIN_EXT, INPUT_PULLUP);

  //Initalised everything, ring very quickly
  ringOnce();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIN_EXT) == LOW) {
    ring();
  }
}



