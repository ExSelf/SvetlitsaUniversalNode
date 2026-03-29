#include <Arduino.h>
#include "Solaris.h"


uint8_t SolarisClass::getInnerDataPin(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 35;

  case 22:
    return 35;

  case 23:
    return 35;

  case 24:
    return 35;

  case 25:
    return 35;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getMiddleDataPin(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 36;

  case 22:
    return 36;

  case 23:
    return 36;

  case 24:
    return 36;

  case 25:
    return 36;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getOuterDataPin(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 33;

  case 22:
    return 33;

  case 23:
    return 34;

  case 24:
    return 34;

  case 25:
    return 34;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getExtraDataPin(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 34;

  case 22:
    return 34;

  case 23:
    return 33;

  case 24:
    return 33;

  case 25:
    return 33;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getInnerStripPixelsQuantity(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 31;

  case 22:
    return 31;

  case 23:
    return 55;

  case 24:
    return 55;

  case 25:
    return 55;

  default:
    return 0;
  }
}

uint8_t SolarisClass::getMiddleStripPixelsQuantity(uint8_t nodeNumber)
{
  switch (nodeNumber)
  {
  case 21:
    return 29;

  case 22:
    return 29;

  case 23:
    return 29;

  case 24:
    return 62;

  case 25:
    return 62;

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
    return 68;

  case 24:
    return 68;

  case 25:
    return 68;

  default:
    return 0;
  }
}

void SolarisClass::setupNode(uint8_t nodeNumber)
{
  pinMode(SOLARIS::INNER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::MIDDLE_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::OUTER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS::EXTRA_PWM_PIN, OUTPUT);
}

SolarisClass Solaris;