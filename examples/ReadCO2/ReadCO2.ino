#include "CO2Sensor.h"

CO2Sensor co2Sensor(A0);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Initialized ===");
}

void loop() {
  int val = co2Sensor.read();
  Serial.print("CO2 value: ");
  Serial.println(val);

  delay(10000);
  
//  co2Sensor.calibrate();
}
