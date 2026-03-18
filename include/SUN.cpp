#include "sun.h"
#include <Arduino.h>
#include <esp_now.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>

#include "NodeSpecific/Origami.cpp"
#include "NodeSpecific/Solaris.cpp"

uint8_t charge;
uint16_t voltage;
uint16_t voltage_buffer[NUMBER_OF_READS];

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
    uint8_t ADCPin = 0;

    if (nodeNumber > 10 && nodeNumber <= 20) // Origami
    {
        Origami.setupNode(nodeNumber);
    }
    else if (nodeNumber <= 30) // Solaris
    {
        ADCPin = 5;
        Solaris.setupNode(nodeNumber);
    }
    else if (nodeNumber <= 40) // MoonFaced
    {
        ADCPin = 5;
    }

    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    WiFi.hostname(SUN.getHostName(nodeNumber).c_str());

    pinMode(ADCPin, INPUT);

    // fill voltage buffer with initial values
    uint16_t currentVoltage = analogRead(ADCPin);
    for (int i = 0; i < NUMBER_OF_READS; i++)
    {
        voltageBuffer[i] = currentVoltage * SUN.getVoltageIndexer(nodeNumber) / 100;
    }
}

void SUNClass::OTAbegin(uint8_t nodeNumber)
{
    WiFi.begin(ssid, password);
    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

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
}

string SUNClass::getHostName(uint8_t nodeNumber)
{
    if (nodeNumber < 20)
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