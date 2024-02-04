/*
Sensor de proximidad y al ser inferior a 30cm 
envia un pulso de alarma al servo por  el pin 13

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 7 
  Trig al Arduino pin 6
*/
/* en ese ejemplo el servo parte de 0 grados se mueve 90 grados y vuelve a 0 grados. te recomiendo el foro de arduino para que saques todas tus dudas
http://forum.arduino.cc/ y http://arduino.cc/es/Reference/HomePage saludos */

 
#define Pecho 7
#define Ptrig 6
#include <Servo.h> // incluye la librera servo
Servo servo; // crea un objeto tipo servo para controlar el servo
long duracion, distancia;   
 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(13, 1);            // Define el pin 13 como salida
  servo.attach(3); // asocia el servo conectado en el pin 3 al objeto servo

  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // no mide nada
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(13, 0);               // en bajo el pin 13
  }
  
   if (distancia <= 10 && distancia >= 1){
    Serial.println("Abrir.......");         // envia la palabra Abrir por el puerto serial
    servo.write(180); // le dice al servo que se ubique en la posición 90
    delay(5000); // espera 1500 ms para dar tiempo al servo a llegar a la nueva posición (no es necesario)
    servo.write(90); // le dice al servo que se ubique en la posición 0
    digitalWrite(13, 1);                     // en alto el pin 13 si la distancia es menor a 30cm
  }
  delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
