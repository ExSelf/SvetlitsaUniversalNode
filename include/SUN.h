#pragma once
#include <stdint.h>

class SUNClass {
public:
    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command);
};

extern SUNClass SUN;