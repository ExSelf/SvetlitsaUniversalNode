#include <Arduino.h>
#include <ArduinoOTA.h>

#include "config/globals.h"

// Include main class
#include "SUN.h"

uint8_t NodeNumber = 0;

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < 8; i++)
  {
    pinMode(GLOBAL::NodeNumberPins[i], INPUT_PULLUP);
    NodeNumber += (!digitalRead(GLOBAL::NodeNumberPins[i]) * pow(2, i));
  }

  SUN.setupNode(NodeNumber);

  Serial.print("Configured and starting as ");
  Serial.println(SUN.getHostName(NodeNumber));
}

void loop()
{
  ArduinoOTA.handle();

  if (millis() - GLOBAL::lastCheckVoltage > GLOBAL::VOLTAGE_CHECK_INTERVAL * 100)
  {
    GLOBAL::lastCheckVoltage = millis();
    SUN.getCharge(NodeNumber);
  }
}