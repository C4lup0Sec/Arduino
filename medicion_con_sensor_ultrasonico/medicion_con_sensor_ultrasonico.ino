/*
 Ejemplo de como funciona el sensor de distancia por ultrasonido
 Por la consola muestra la distancia y cuando esta llega a un 
 punto determinado se enciende un led.
 
 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 7 
  Trig al Arduino pin 9
 */
 
#define echoPin 7
#define trigPin 9
#define LEDPin 13
long duration, cm;
 
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}
 
void loop(){
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(5); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 cm = microsecondsToCentimeters(duration);
 
 Serial.print ("Milisegundos: ");
 Serial.print(duration);
 Serial.print("  Distancia estimada: ");
 Serial.print(cm);
 Serial.println(" cm");
 
 delay(1000);
}
 
long microsecondsToCentimeters(long microseconds){
  // La velocidad del sonido a 20º de temperatura es 340 m/s o
  // 29 microsegundos por centrimetro.
  // La señal tiene que ir y volver por lo que la distancia a 
  // la que se encuentra el objeto es la mitad de la recorrida.
  return microseconds / 29 /2 ;
}
