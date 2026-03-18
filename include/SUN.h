#pragma once
#include <stdint.h>

extern uint8_t charge;
extern uint16_t voltage;
extern uint16_t voltage_buffer[NUMBER_OF_READS];

class SUNClass {
public:
    uint16_t globalTime;

    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command);
    void setupNode(uint8_t nodeNumber);
    string getHostName(uint8_t nodeNumber);

};

extern SUNClass SUN;