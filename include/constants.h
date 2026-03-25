/* Binary pins definitions */
extern const uint8_t NodeNumberPins[8];

extern const char* ssid;
extern const char* password;

extern char* hostName;

extern uint8_t command;
extern uint8_t parameter;
extern uint8_t constantCommands[12];

extern unsigned long lastCheckVoltage;

#define VOLTAGE_CHECK_INTERVAL 10
#define STATUS_SEND_INTERVAL 25