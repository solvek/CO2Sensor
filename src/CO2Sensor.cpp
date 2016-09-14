#include "CO2Sensor.h"

// CO2 sensor readings
#define TRIES  10

#define CO2SENSOR_DEBUG false

const int co2_b = 600;
const int co2_d = 400;

CO2Sensor::CO2Sensor(int analogPin){
  _analogPin = analogPin;
  _co2_a = 1500;
}

int CO2Sensor::read(){
  _co2_v = 0;

  analogRead(_analogPin);
  for (int i = 0; i < TRIES; i++)
  {
     _co2_v += analogRead(_analogPin);
     delay(20);
  }
  _co2_v = (_co2_v*5000.0)/(1024.0*TRIES);

  double co2_exp = (_co2_a-_co2_v)/co2_b;

  _co2ppm = pow(co2_d, co2_exp);

  #if CO2SENSOR_DEBUG
  Serial.print("Exponent: ");
  Serial.println(co2_exp);

  Serial.println("CO2 == ");

  Serial.print(_co2_v);
  Serial.println(" mV");
  
  Serial.print(_co2ppm);
  Serial.println(" ppm");
  #endif

  return _co2ppm;
}
    
void CO2Sensor::calibrate(){
  #if CO2SENSOR_DEBUG
  Serial.print("Calibration. Old a: ");
  Serial.print(_co2_a);
  #endif
  
  _co2_a = _co2_v + co2_b;

  #if CO2SENSOR_DEBUG
  Serial.print(", New a: ");
  Serial.println(_co2_a);
  #endif
}

