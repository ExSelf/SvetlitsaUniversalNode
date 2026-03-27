#pragma once
#include <stdint.h>

namespace GLOBAL
{

    static constexpr uint8_t VOLTAGE_CHECK_INTERVAL = 10;
    static constexpr uint8_t STATUS_SEND_INTERVAL = 25;
    static constexpr uint8_t DEFAULT_WIFI_CHANNEL = 13;

    extern uint8_t TTL;
    extern int32_t globalTimeOffset;

    extern uint8_t voltageReadCounter;
    extern uint16_t voltage;
    extern uint16_t voltageBuffer[256];

    extern uint32_t lastCheckVoltage;
    extern uint32_t lastSendStatus;

    extern const uint8_t NodeNumberPins[8];
    extern const char *ssid;
    extern const char *password;
    extern char *hostName;
    extern uint8_t command;
    extern uint8_t parameter;
    extern uint8_t constantCommands[12];
}