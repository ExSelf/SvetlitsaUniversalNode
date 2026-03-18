#pragma once
#include <stdint.h>

class SUNClass {
public:
    uint16_t getVoltageIndexer(uint8_t nodeNumber);
    void setNodeCommand(uint8_t nodeNumber, uint8_t command);

    // Origami Specific methods

    // Solaris Specific methods
    uint8_t solarisGetInnerStripPixelsQuantity(uint8_t nodeNumber);
    uint8_t solarisGetMiddleStripPixelsQuantity(uint8_t nodeNumber);
    uint8_t solarisGetOuterStripPixelsQuantity(uint8_t nodeNumber);
};

extern SUNClass SUN;