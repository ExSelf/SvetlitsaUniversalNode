#pragma once
#include <stdint.h>

class SolarisClass {
public:

    // Solaris Specific methods
    uint8_t getInnerStripPixelsQuantity(uint8_t nodeNumber);
    uint8_t getMiddleStripPixelsQuantity(uint8_t nodeNumber);
    uint8_t getOuterStripPixelsQuantity(uint8_t nodeNumber);
    void setupNode(uint8_t nodeNumber);
};

extern class SolarisClass Solaris;