/*
 * \brief Get human movement status from PIR sensor asynchronously (with interrupt)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 30 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <DigitalSensor.h>

// Create digital PIR sensor instance on D2 pin (this pin is linked to interrupts
// for most Arduino boards (https://www.arduino.cc/en/Reference/AttachInterrupt)
DigitalSensor pir(2);

void showPIRState()
{
  Serial.print("PIR state: ");
  if (pir.status()) {
    Serial.print("Someone detected");
  } else {
    Serial.print("No one detected");
  }
  Serial.print("\n");
}

void setup(void)
{
  Serial.begin(9600);

  // All possible modes for next call: CHANGE, LOW, RISING, FALLING, HIGH
  pir.attachStateChangeToFunction(showPIRState/*, CHANGE*/);

  Serial.print("Interrupts attached to PIR sensor.\nState changes will be detected.\n");
}

void loop()
{
}
