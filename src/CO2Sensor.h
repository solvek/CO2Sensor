/*
  CO2Sensor.h - Reading and calibrating CO2 module
  Created by Sergi Adamchuk, September 14, 2016.
  Released into the public domain.
*/
#ifndef CO2Sensor_h
#define CO2Sensor_h

#include <Arduino.h>

class CO2Sensor
{
  public:
    CO2Sensor(int analogPin);
    CO2Sensor(int analogPin, float inertia, int tries);
    int read();
    void calibrate();

  private:
    void init();

    int _analogPin;
    int _inertia;
    int _tries;
    int _co2_v;
    double _co2_a;
    double _co2ppm;
};

#endif
