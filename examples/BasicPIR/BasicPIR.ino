/*
 * \brief Get human movement status from PIR sensor every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 30 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <DigitalSensor.h>

// Create digital PIR sensor instance on D2 pin
DigitalSensor pir(2);

void setup(void)
{
  Serial.begin(9600);
}

void loop()
{
  // Check rain state every sec

  Serial.print("PIR state: ");
  if (pir.status()) {
    Serial.print("Someone detected");
  } else {
    Serial.print("No one detected");
  }
  Serial.print("\n");

  delay(1000);
}
