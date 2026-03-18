#include "sun.h"
#include <Arduino.h>

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

    if (nodeNumber < 10) // Origami
    {
        Origami.setupNode(nodeNumber);
    }
    else if (nodeNumber < 20) // Solaris
    {
        ADCPin = 5;
        Solaris.setupNode(nodeNumber);
    }

    pinMode(ADCPin, INPUT);

    // fill voltage buffer with initial values
    uint16_t currentVoltage = analogRead(ADCPin);
    for (int i = 0; i < NUMBER_OF_READS; i++)
    {
        voltageBuffer[i] = currentVoltage * SUN.getVoltageIndexer(nodeNumber) / 100;
    }
}