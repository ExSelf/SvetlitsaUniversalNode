#include <Arduino.h>
#include "Solaris.h"

uint8_t SolarisClass::getInnerStripPixelsQuantity(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 50;

  case 22:
    return 50;

  case 23:
    return 50;

  case 24:
    return 50;

  case 25:
    return 50;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getMiddleStripPixelsQuantity(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 50;

  case 22:
    return 50;

  case 23:
    return 50;

  case 24:
    return 50;

  case 25:
    return 50;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getOuterStripPixelsQuantity(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 98;

  case 22:
    return 98;

  case 23:
    return 98;

  case 24:
    return 98;

  case 25:
    return 98;

  default:
    return 0;
  }
}

void SolarisClass::setupNode(uint8_t nodeNumber)
{
  pinMode(SOLARIS::INNER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::MIDDLE_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::OUTER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::HANDS_PWM_PIN, OUTPUT);
}

SolarisClass Solaris;