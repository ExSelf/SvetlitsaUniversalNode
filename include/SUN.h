#pragma once
#include <stdint.h>

class SUNClass {
public:
    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command);
    void setupNode(uint8_t nodeNumber);
    string getHostName(uint8_t nodeNumber);

};

extern SUNClass SUN;