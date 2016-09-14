void setup() {
  Serial.begin(9600);
  Serial.println("=== Initialized ===");
}

void loop() {
  int val = analogRead(A0);
  Serial.print("Signal value: ");
  Serial.println(val);

  delay(1000);
}
