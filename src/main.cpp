#include <Arduino.h>

#include <esp_now.h>
#include <ArduinoOTA.h>

// Include main class
#include "SUN.h"

uint8_t NodeNumber = 0;

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < 8; i++)
  {
    pinMode(NodeNumberPins[i], INPUT_PULLUP);
    NodeNumber += (!digitalRead(NodeNumberPins[i]) * pow(2, i));
  }

  SUN.setupNode(NodeNumber);

  Serial.print("Configured and starting as ");
  Serial.println(SUN.getHostName(NodeNumber));
}

void loop()
{
  ArduinoOTA.handle();

  if (millis() - lastCheckVoltage > VOLTAGE_CHECK_INTERVAL * 100)
  {
    lastCheckVoltage = millis();
  }
}