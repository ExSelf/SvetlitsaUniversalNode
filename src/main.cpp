#include <Arduino.h>
#include <constants.c>

void setup() {
Serial.begin(115200);

for (int i = 0; i < 8; i++) {
    pinMode(costume_number[i], INPUT_PULLUP);
  }
}

void loop() {
  Serial.printf(costume_number[0] ? "1" : "0",
  costume_number[1] ? "1" : "0",
  costume_number[2] ? "1" : "0",
  costume_number[3] ? "1" : "0",
  costume_number[4] ? "1" : "0",
  costume_number[5] ? "1" : "0",
  costume_number[6] ? "1" : "0",
  costume_number[7] ? "1" : "0");
  delay(1000);
}
