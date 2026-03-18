#include "sun.h"
#include <Arduino.h>

// Create global instance
SUNClass SUN;

uint16_t SUNClass::getVoltageIndexer(uint8_t nodeNumber) {
    switch (nodeNumber) {
        case 12:
        return 730;
        
        default:
        return 0;
    }
}

void SUNClass::setNodeCommand(uint8_t nodeNumber, uint8_t command, uint8_t parameter, uint8_t constantParameters[12]) {
    Serial.printf("Send command %d to node %d\n", command, nodeNumber);
}