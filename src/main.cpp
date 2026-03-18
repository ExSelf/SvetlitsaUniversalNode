#include <Arduino.h>
#include <constants.c>
#include <esp_now.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>

#include "NodeSpecific/Solaris.c"
#include "NodeSpecific/Origami.c"

// Node specific includes
#include "SUN.h"

uint8_t NodeNumber = 0;

void OTAbegin();
void handleMIDI(uint8_t NodeNumber);

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < 8; i++)
  {
    pinMode(NodeNumberPins[i], INPUT_PULLUP);
    NodeNumber += (!digitalRead(NodeNumberPins[i]) * pow(2, i));
  }

  SUN.setupNode(NodeNumber);

  OTAbegin();
  Serial.println(NodeNumber);
}

void loop()
{
  ArduinoOTA.handle();

  handleMIDI(NodeNumber);
}

void OTAbegin()
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  if (!MDNS.begin(hostName))
  {
    Serial.println("Error starting mDNS");
  }
  else
  {
    Serial.println("mDNS started");
  }

  ArduinoOTA.setHostname(hostName);

  Serial.println();
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.onStart([]()
                     { Serial.println("OTA Start"); });

  ArduinoOTA.onEnd([]()
                   { Serial.println("\nOTA End"); });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                        { Serial.printf("Progress: %u%%\r", (progress * 100) / total); });

  ArduinoOTA.onError([](ota_error_t error)
                     { Serial.printf("Error[%u]\n", error); });

  ArduinoOTA.begin();
}

void handleMIDI(uint8_t Node)
{
  if (Node < 10)
  {
  }
  else if (Node < 20)
  { // Origami
  }
  else if (Node < 30)
  { // Solaris
    SolarisMIDI();
  }
  else if (Node < 40)
  {
  }
  else if (Node < 50)
  {
  }
  else if (Node < 60)
  {
  }
  else if (Node < 70)
  {
  }
  else if (Node < 80)
  {
  }
  else if (Node < 90)
  {
  }
  else if (Node < 100)
  {
  }
}