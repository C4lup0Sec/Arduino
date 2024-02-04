#include <SoftwareSerial.h> //library for software serial

//define software serial: RX on Pin 2, TX on Pin 3
SoftwareSerial softSerial(2, 3); 

void setup()  
{
  Serial.begin(9600); //Initialise serial at 9600 baud
  softSerial.begin(9600); //Initialise software serial
}

void loop() 
{
  //send any software serial data back out on serial link
  if (softSerial.available()) Serial.write(softSerial.read());
  
  //send any serial data back out on software serial link
  if (Serial.available())softSerial.write(Serial.read());
}

