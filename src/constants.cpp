#include <Arduino.h>

/* Binary pins definitions */
extern const uint8_t NodeNumberPins[8] = {39, 40, 37, 38, 18, 21, 16, 17};

extern const char* ssid = "ExSelf";
extern const char* password = "gggggggggg";

extern char* hostName;

extern uint8_t command;
extern uint8_t parameter;
extern uint8_t constantCommands[12];

#define VOLTAGE_CHECK_INTERVAL 10
#define STATUS_SEND_INTERVAL 25
