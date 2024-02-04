void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.printIn((514 - sensorValue) * 27.03 / 1023;
  delay(250);
}
