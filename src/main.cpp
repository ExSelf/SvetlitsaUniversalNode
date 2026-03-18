#include <Arduino.h>
#include <constants.c>
#include <esp_now.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>

// Node specific includes
#include "SUN.h"

uint8_t NodeNumber = 0;

void OTAbegin();
void handleMIDI(uint8_t NodeNumber);

void setup() {
Serial.begin(115200);

for (int i = 0; i < 8; i++) {
    pinMode(NodeNumber[i], INPUT_PULLUP);
    NodeNum += (!digitalRead(NodeNumber[i]) * pow(2, i));
  }

OTAbegin();
Serial.println(NodeNumber);
}

void loop() {
  ArduinoOTA.handle();


  handleMIDI(NodeNumber);
}

void OTAbegin() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  if (!MDNS.begin(hostName)) {
    Serial.println("Error starting mDNS");
  } else {
    Serial.println("mDNS started");
  }

  ArduinoOTA.setHostname(hostName);

  Serial.println();
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.onStart([]() {
    Serial.println("OTA Start");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA End");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress * 100) / total);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]\n", error);
  });

  ArduinoOTA.begin();
}

void handleMIDI(uint8_t NodeNumber) {
    if (NodeNumber < 10) {

    } else if (NodeNumber < 20) { //Origami

    } else if (NodeNumber < 30) { // Solaris
      SolarisMIDI();
    } else if (NodeNumber < 40) {

    } else if (NodeNumber < 50) {

    } else if (NodeNumber < 60) {

    } else if (NodeNumber < 70) {

    } else if (NodeNumber < 80) {

    } else if (NodeNumber < 90) {

    } else if (NodeNumber < 100) {

    }
}