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


// Origami Specific constants


// Solaris specific constants
#define SOLARIS_BREATHE_INTERVAL_1 250
#define SOLARIS_BREATHE_INTERVAL_2 2500
#define SOLARIS_BUTTON_PRESS_DELAY 750