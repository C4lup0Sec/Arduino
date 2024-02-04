/******************************************
	FILE:		DEMO_MQ-2.pde
	PURPOSE:	MQ-2 test sketch for Arduino
	Created by Stan Lee from Iteadstuduino
	E-mail:		Lizq@iteadstudio.com
	DATE:		2013/4/20
*******************************************/

const int ledPin =  13;      // the number of the LED pin
const int thresholdvalue=400; //The threshold to turn the led on
void setup() {
     pinMode(ledPin, OUTPUT); 
}
void loop() {
  int sensorValue = analogRead(A0); //use A0 to read the electrical signal
  if(sensorValue>thresholdvalue)
  digitalWrite(ledPin,HIGH); //if the value read from A0 is larger than 400,then light the LED
  delay(200);
  digitalWrite(ledPin,LOW);
}