/*
 * \brief Get value from Digital sensor (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 30 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(int pin)
{
  _pin = pin;
  pinMode(pin, INPUT);
}

bool DigitalSensor::status()
{
  return (digitalRead(_pin));
}

void DigitalSensor::attachStateChangeToFunction(void (*function)(), int mode)
{
  attachInterrupt(digitalPinToInterrupt(_pin), function, mode);
}
