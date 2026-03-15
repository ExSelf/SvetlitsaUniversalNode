#include <string.h>

#include "solaris.c"

uint16_t NodeSpecificConstant(uint8_t nodeNumber, char *constantName) {
    if (nodeNumber < 10) {

    } else if (nodeNumber < 20) { //Origami

    } else if (nodeNumber < 30) { // Solaris
        if (strcmp(constantName, "VOLTAGE_INDEXER") == 0) {
            return 730;
        }
    } else if (nodeNumber < 40) {

    } else if (nodeNumber < 50) {

    } else if (nodeNumber < 60) {

    } else if (nodeNumber < 70) {

    } else if (nodeNumber < 80) {

    } else if (nodeNumber < 90) {

    } else if (nodeNumber < 100) {

    }
}
