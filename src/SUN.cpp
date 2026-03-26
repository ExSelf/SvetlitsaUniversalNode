#include <Arduino.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

#ifndef ARDUINO_OTA_H
#include <ArduinoOTA.h>
#endif

#include "SUN.h"
#include "config/globals.h"

// Create global instance
SUNClass SUN;

uint16_t SUNClass::getVoltageIndexer(uint8_t nodeNumber)
{
    switch (nodeNumber)
    {
    case 12:
        return 730;

    default:
        return 0;
    }
}

void SUNClass::setNodeCommand(uint8_t nodeNumber, uint8_t command, uint8_t parameter, uint8_t constantParameters[12])
{
    Serial.printf("Send command %d to node %d\n", command, nodeNumber);
}

void SUNClass::setupNode(uint8_t nodeNumber)
{
    analogReadResolution(12);

    if (nodeNumber > 10 && nodeNumber <= 20) // Origami
    {
        Origami.setupNode(nodeNumber);
    }
    else if (nodeNumber <= 30) // Solaris
    {
        Solaris.setupNode(nodeNumber);
    }
    else if (nodeNumber <= 40) // MoonFaced
    {
        // MoonFaced.setupNode(nodeNumber);
    }

    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_STA);
    esp_wifi_set_channel(GLOBAL::DEFAULT_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);
    WiFi.begin(GLOBAL::ssid, GLOBAL::password);
    WiFi.hostname(SUN.getHostName(nodeNumber).c_str());

    if (!MDNS.begin(SUN.getHostName(nodeNumber).c_str()))
    {
        Serial.println("Error starting mDNS");
    }
    else
    {
        Serial.println("mDNS started");
    }

    ArduinoOTA.setHostname(SUN.getHostName(nodeNumber).c_str());

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

    Serial.print("Device is being configured as number ");
    Serial.print(String(nodeNumber));
    Serial.print(" with hostname ");
    Serial.println(SUN.getHostName(nodeNumber));

    pinMode(SUN.getADCPin(nodeNumber), INPUT);

    // fill voltage buffer with initial values
    uint16_t currentVoltage = analogRead(SUN.getADCPin(nodeNumber));
    for (int i = 0; i < 256; i++)
    {
        GLOBAL::voltageBuffer[i] = currentVoltage * SUN.getVoltageIndexer(nodeNumber) / 100;
    }

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW init failed");
        return;
    }
}

String SUNClass::getHostName(uint8_t nodeNumber)
{
    if (nodeNumber >= 10 && nodeNumber < 20)
    {
        return "Origami_" + String(nodeNumber);
    }
    else if (nodeNumber < 30)
    {
        return "Solaris_" + String(nodeNumber % 10);
    }
    else if (nodeNumber < 40)
    {
        return "MoonFaced_" + String(nodeNumber % 10);
    }
    else
    {
        return "UnknownNode_" + String(nodeNumber % 10);
    }
}

uint8_t SUNClass::getADCPin(uint8_t nodeNumber)
{
    {
        switch (nodeNumber)
        {

        default:
            return 5;
        }
    }
}

uint8_t SUNClass::getCharge(uint8_t nodeNumber)
{
    GLOBAL::voltageReadCounter++;
    GLOBAL::voltageBuffer[GLOBAL::voltageReadCounter] = analogRead(SUN.getADCPin(nodeNumber)) * SUN.getVoltageIndexer(nodeNumber) / 100;

    uint16_t total = 0;
    for (uint8_t i = 0; i < 256; i++)
    {
        total += GLOBAL::voltageBuffer[i];
    }
    GLOBAL::voltage = total / 256;

    uint8_t charge = constrain(map(GLOBAL::voltage, SUN.getLowVoltage(nodeNumber), SUN.getHighVoltage(nodeNumber), 0, 100), 0, 100);

    return charge;

    //bright = constrain(map(charge, 0, SAFE_CHARGE, MIN_BRIGHT, MAX_BRIGHT), MIN_BRIGHT, MAX_BRIGHT);
}

uint16_t SUNClass::getLowVoltage(uint8_t nodeNumber)
{
    switch (nodeNumber)
    {
    case 21:
        return 9000;

    case 22:
        return 9000;

    case 23:
        return 9000;

    case 24:
        return 9000;

    case 25:
        return 9000;

    default:
        return 0;
    }
}

uint16_t SUNClass::getHighVoltage(uint8_t nodeNumber)
{
    switch (nodeNumber)
    {

    case 21:
        return 12600;

    case 22:
        return 12600;

    case 23:
        return 12600;

    case 24:
        return 12600;

    case 25:
        return 12600;

    default:
        return 65535;
    }
}