#pragma once
#include <stdint.h>

#include "../src/NodeSpecific/Origami.h"
#include "../src/NodeSpecific/Solaris.h"
#include "../src/NodeSpecific/MoonFaced.h"

class SUNClass
{
public:
    uint16_t globalTime;

    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command, uint8_t parameter, uint8_t constantParameters[12]);
    void setupNode(uint8_t nodeNumber);
    String getHostName(uint8_t nodeNumber);
    uint8_t getADCPin(uint8_t nodeNumber);
    uint8_t getCharge(uint8_t nodeNumber);
    uint16_t getLowVoltage(uint8_t nodeNumber);
    uint16_t getHighVoltage(uint8_t nodeNumber);
    void sendStatus(uint8_t nodeNumber);
    bool sendMessage(const uint8_t *payload, size_t payloadSize);
    void parseReceviedData(const uint8_t * mac_addr, const uint8_t *incomingData, int len);
};

extern SUNClass SUN;