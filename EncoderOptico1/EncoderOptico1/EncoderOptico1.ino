#include <digitalWriteFast.h>

//definimos los pines, recuerden que la interrupcion 0 esta en el pin 2
// mas info sobre la sintaxis https://www.arduino.cc/en/Reference/AttachInterrupt

#define InterEncoder1 0  ///interrupcion 0, es decir el pin 2
#define EncoderPinA 2   /// encoder pin 2 e interrupcion 0
#define EncoderPinB 4  ///encoder pin 4

//motores enable en pins 8 y 7, pwm en 9
#define motor1A 8
#define motor1B 7
#define motor1_PWM 9



// Cuadratura de Encoders
#define encoder1
volatile bool EncoderSet1;
volatile long ticksEncoder1 = 0;



void setup(void)
{
Serial.begin(115200);

 // Cuadratura encoder 
  // encoder izq
  pinMode(EncoderPinA, INPUT);      
  digitalWrite(EncoderPinA, LOW);  
  pinMode(EncoderPinB, INPUT);      
  digitalWrite(EncoderPinB, LOW);  
  attachInterrupt(InterEncoder1, Encoder1A, RISING); 
// mas info sobre intetrrupciones https://www.arduino.cc/en/Reference/AttachInterrupt



//para la direccion del motor
 pinMode(motor1A, OUTPUT);      
 pinMode(motor1B, OUTPUT);      

 digitalWrite(motor1A, HIGH); //el motor comienza a girar

}



void loop(void){


analogWrite(motor1_PWM, 200); // hasta 255


if (ticksEncoder1 == -1800){
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
}



if (ticksEncoder1 == 1800){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
}


 //imprimimos el valor del encoder en el monitor serial
Serial.print("Encoder 1: "); Serial.print(ticksEncoder1); Serial.print("\n");   

  
  }

/*
 *  interrupciones para la cuadratura de encoders 
 */
void Encoder1A()
{
  
  EncoderSet1 = digitalReadFast(EncoderPinB);   

#ifdef encoder1
  ticksEncoder1 -= EncoderSet1 ? -1 : +1;
#else
  ticksEncoder1 += EncoderSet1 ? -1 : +1;
#endif
}




