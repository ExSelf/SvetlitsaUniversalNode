#include "config/globals.h"

namespace GLOBAL
{
    /* Binary pins definitions */
    const uint8_t NodeNumberPins[8] = {39, 40, 37, 38, 18, 21, 16, 17};

    // static constexpr uint8_t VOLTAGE_CHECK_INTERVAL = 10;
    // static constexpr uint8_t STATUS_SEND_INTERVAL = 25;
    // static constexpr uint8_t DEFAULT_WIFI_CHANNEL = 13;

    const char *ssid = "test";
    const char *password = "test";

    char *hostName;

    uint8_t command;
    uint8_t parameter;
    uint8_t constantCommands[12];

    uint8_t voltageReadCounter;
    uint16_t voltage;
    uint16_t voltageBuffer[256];

    uint32_t lastCheckVoltage = 0;

}
