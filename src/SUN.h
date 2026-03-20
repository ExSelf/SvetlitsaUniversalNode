#pragma once
#include <stdint.h>

#include "constants.h"

#include "../src/NodeSpecific/Origami.h"
#include "../src/NodeSpecific/Solaris.h"
#include "../src/NodeSpecific/MoonFaced.h"

extern uint8_t charge;
extern uint16_t voltage;
extern uint16_t voltage_buffer[NUMBER_OF_READS];

class SUNClass {
public:
    uint16_t globalTime;

    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command, uint8_t parameter, uint8_t constantParameters[12]);
    void setupNode(uint8_t nodeNumber);
    void OTAbegin(uint8_t nodeNumber);
    String getHostName(uint8_t nodeNumber);
    uint8_t getADCPin(uint8_t nodeNumber);
};

extern SUNClass SUN;