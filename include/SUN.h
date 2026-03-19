#pragma once
#include <stdint.h>

#include "constants.c"

#include "NodeSpecific/Origami.h"
#include "NodeSpecific/Solaris.h"
#include "NodeSpecific/MoonFaced.h"

extern uint8_t charge;
extern uint16_t voltage;
extern uint16_t voltage_buffer[NUMBER_OF_READS];

class SUNClass {
public:
    uint16_t globalTime;

    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command);
    void setupNode(uint8_t nodeNumber);
    void OTAbegin(uint8_t nodeNumber);
    String getHostName(uint8_t nodeNumber);

};

extern SUNClass SUN;