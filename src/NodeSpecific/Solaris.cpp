#include <Arduino.h>
#include "Solaris.h"

#define SOLARIS_BREATHE_INTERVAL_1 250
#define SOLARIS_BREATHE_INTERVAL_2 2500
#define SOLARIS_BUTTON_PRESS_DELAY 750

#define SOLARIS_INNER_PWM_PIN 1
#define SOLARIS_MIDDLE_PWM_PIN 2
#define SOLARIS_OUTER_PWM_PIN 4
#define SOLARIS_HANDS_PWM_PIN 6

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
  pinMode(SOLARIS_INNER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS_MIDDLE_PWM_PIN, OUTPUT);
  pinMode(SOLARIS_OUTER_PWM_PIN, OUTPUT);
  pinMode(SOLARIS_HANDS_PWM_PIN, OUTPUT);
}

SolarisClass Solaris;