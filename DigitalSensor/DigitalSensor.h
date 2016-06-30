/*
 * \brief Get status (True/False) from digital sensor
 *
 * Use examples are given with PIR sensor but any digital sensor are handled.
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 30 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#ifndef DigitalSensor_h
#define DigitalSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class DigitalSensor
{
  public:

    /*!
     * \brief DigitalSensor Initialize Digital sensor
     *
     * \param pin (int) Sensor digital output pin
     */
    DigitalSensor(int pin);

    /*!
     * \brief status Return digital sensor pin value
     *
     * \return (bool) Digital sensor pin value
     */
    bool status();

    /*!
     * \brief attachStateChangeToFunction Attach a specific user function to sensor state change
     *
     * \param (void function()) Function that will be launched every time the sensor changes its state
     * \param mode (int) Event for which the function will be launched (LOW, CHANGE, RISING, FALLING, HIGH)
	                     Full list of mode: https://www.arduino.cc/en/Reference/AttachInterrupt
     */
    void attachStateChangeToFunction(void (*function)(), int mode = CHANGE);

  private:
    int _pin;
};

#endif //DigitalSensor_h

