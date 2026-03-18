/* Binary pins definitions */
const uint8_t NodeNumberPins[8] = {39, 40, 37, 38, 18, 21, 16, 17};

const char* ssid = "ExSelf";
const char* password = "gggggggggg";

char* hostName;

uint8_t command;
uint8_t parameter;
uint8_t constantCommands[12];

#define VOLTAGE_CHECK_INTERVAL 10
#define STATUS_SEND_INTERVAL 25
#define NUMBER_OF_READS 100
