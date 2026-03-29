#include <Arduino.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <ArduinoOTA.h>

#include "config/globals.h"

// Include main class
#include "SUN.h"

uint8_t NodeNumber = 0;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  SUN.parseReceviedData(mac, incomingData, len);
}

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

  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void loop()
{
  ArduinoOTA.handle();

  if (millis() - GLOBAL::lastCheckVoltage > GLOBAL::VOLTAGE_CHECK_INTERVAL)
  {
    GLOBAL::lastCheckVoltage = millis();
    SUN.getCharge(NodeNumber);
  }

  if (millis() - GLOBAL::lastSendStatus > GLOBAL::STATUS_SEND_INTERVAL)
  {
    GLOBAL::lastSendStatus = millis();
    SUN.sendStatus(NodeNumber);
  }

  if(millis() - GLOBAL::lastTick > GLOBAL::TICK_INTERVAL)
  {
    GLOBAL::lastTick = millis();
    bool ledState = digitalRead(GLOBAL::BUILT_IN_LED_PIN);
    digitalWrite(GLOBAL::BUILT_IN_LED_PIN, !ledState);
  }
}