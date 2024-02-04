const int sensorPin = A1;

double Current = 0;
double OutputSensorVoltage =0;

void setup() {
  Serial.begin(9600);
}

void loop() {
 OutputSensorVoltage = analogRead(sensorPin)*30.0/1023.0;
 Current = (OutputSensorVoltage -2.5 )/0.066;

 Serial.print("Current = ");
 Serial.print(Current);
 Serial.print("\n");
 delay(1000);
}
