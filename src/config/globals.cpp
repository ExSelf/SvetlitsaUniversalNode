#include "config/globals.h"

namespace GLOBAL {

/* Binary pins definitions */
const uint8_t NodeNumberPins[8] = {39, 40, 37, 38, 18, 21, 16, 17};

const char* ssid = "test";
const char* password = "test";

char* hostName;

uint8_t command;
uint8_t parameter;
uint8_t constantCommands[12];

uint8_t voltageReadCounter;
uint16_t voltage;
uint16_t voltageBuffer[256];

uint32_t lastCheckVoltage = 0;

}
