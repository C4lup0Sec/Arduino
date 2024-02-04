/*
Sensor de proximidad y al ser inferior a 30cm 
envia un pulso de alarma al servo por  el pin 13

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 7 
  Trig al Arduino pin 6
*/
#define Pecho 7
#define Ptrig 6
long duracion, distancia;   
int val = 0;         // variable to store the read value
int ledPin = 9;      // LED connected to digital pin 9
 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(ledPin, OUTPUT);
  }

void loop() {
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  val = digitalRead(duracion);   // read the input pin
  duracion = pulseIn(Pecho, HIGH);
  
  if (val >= 500 || val <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    analogWrite(ledPin, 255);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    if (val >= 400){
     analogWrite(ledPin, 200);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
                   }
      if (val >= 300){
       analogWrite(ledPin, 180);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
                    }
        if (val >= 200){
         analogWrite(ledPin, 120);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
                    } 
                    if (val >= 100){
                     analogWrite(ledPin, 80);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
                    }            
                             }
              }
