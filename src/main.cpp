#include <Arduino.h>
#include <constants.c>
#include <node_specific_constants.c>
#include <esp_now.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>

// Node specific includes
#include "solaris.c"

uint8_t NodeNum = 0;

void OTAbegin();
void handleMIDI(uint8_t nodeNumber);

void setup() {
Serial.begin(115200);

for (int i = 0; i < 8; i++) {
    pinMode(NodeNumber[i], INPUT_PULLUP);

    NodeNum += (!digitalRead(NodeNumber[i]) * pow(2, i));
  }

OTAbegin();
Serial.println(NodeNum);
}

void loop() {
  ArduinoOTA.handle();


  handleMIDI(NodeNum);
}

void OTAbegin() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  if (!MDNS.begin(hostname)) {
    Serial.println("Error starting mDNS");
  } else {
    Serial.println("mDNS started");
  }

  ArduinoOTA.setHostname(hostname);

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

void handleMIDI(uint8_t nodeNumber) {
    if (nodeNumber < 10) {

    } else if (nodeNumber < 20) { //Origami

    } else if (nodeNumber < 30) { // Solaris
      SolarisMIDI();
    } else if (nodeNumber < 40) {

    } else if (nodeNumber < 50) {

    } else if (nodeNumber < 60) {

    } else if (nodeNumber < 70) {

    } else if (nodeNumber < 80) {

    } else if (nodeNumber < 90) {

    } else if (nodeNumber < 100) {

    }
}