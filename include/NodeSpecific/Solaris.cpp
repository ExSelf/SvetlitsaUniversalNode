#include "Solaris.h"

#define SOLARIS_BREATHE_INTERVAL_1 250
#define SOLARIS_BREATHE_INTERVAL_2 2500
#define SOLARIS_BUTTON_PRESS_DELAY 750


uint8_t getInnerStripPixelsQuantity(uint8_t nodeNumber)
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

uint8_t getMiddleStripPixelsQuantity(uint8_t nodeNumber)
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

uint8_t getOuterStripPixelsQuantity(uint8_t nodeNumber)
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

void setupNode(uint8_t nodeNumber)
{
  pinMode(INNER_PWM_PIN, OUTPUT);
  pinMode(MIDDLE_PWM_PIN, OUTPUT);
  pinMode(OUTER_PWM_PIN, OUTPUT);
  pinMode(HANDS_PWM_PIN, OUTPUT);
}