#include <Arduino.h>
#include <constants.c>
#include <esp_now.h>
#include <ArduinoOTA.h>

uint8_t NodeNum = 0;

void setup() {
Serial.begin(115200);


for (int i = 0; i < 8; i++) {
    pinMode(NodeNumber[i], INPUT_PULLUP);

    NodeNum += (!digitalRead(NodeNumber[i]) * pow(2, i));
  }

Serial.println(NodeNum);
}

void loop() {
  Serial.printf("Node Number: %d\n", NodeNum);
  delay(1000);
}
