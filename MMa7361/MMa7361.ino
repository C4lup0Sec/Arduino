
int x; // x axis variable
int y; // y axis variable
int z; // z axis variable
void setup()
{ 
   Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
void loop()
{
  x = analogRead(5); // read A5 input pin
  y = analogRead(4); // read A4 input pin
  z = analogRead(3); // read A3 input pin
  Serial.print("X = "); // print x adc value
  Serial.println(x);
  Serial.print("Y = "); // print y adc value
  Serial.println(y);
  Serial.print("Z = "); // print z adc value
  Serial.println(z);
  delay(100);
}
