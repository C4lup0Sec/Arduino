// Ultrasonic Distance Sensor Demo
// By keuwlsoft:  www.keuwl.com  16th Sept 2015
// cc Attribution-ShareAlike
//
// This sketch controls a HC-SR04 Ultrasonic Distance sensor on pins 8 & 9
// The distance is calculated and sent over using an HC-06 Bluetooth module
// Keuwlsofts 'Bluetooth Electronics' App is used to view the results
/*
    Temperature°C-Speed of Sound
               30-349.1
               20-343.2
               15-340.0
               10-337.3
                0-331.3
              -10-325.2
              -20-318.9
 */

int trig_pin = 8;
int echo_pin = 9;
long echotime; //in micro seconds
float distance; //in cm

void setup() {
  Serial.begin (9600);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW); //Start with trigger LOW
}

void loop() {
  
  //trigger a pulse-echo measurement
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  //get the result
  echotime= pulseIn(echo_pin, HIGH);
  distance= 0.0001*((float)echotime*340.0)/2.0;
  
  //send over Bluetooth 
  Serial.print("*T"+String(echotime)+"*");
  Serial.print("*D"+String(distance,1)+"*");
  if (distance<20) Serial.print("*LR255G0B0*"); //Red
  if (distance>=20&&distance<=50) Serial.print("*LR255G200B0*"); //Orange
  if (distance>50) Serial.print("*LR0G255B0*"); //Green
  
  delay(100);
}
