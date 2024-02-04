#include <digitalWriteFast.h>
 int long encoder0PinA = 2; //pin 3 aurduino uno
 int long encoder0PinB = 3; //pin 4 aurduino uno
 int long encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 float grados=90;
 int interrupciones;
 
 int long encoder1PinA = 4; //pin 3 aurduino uno
 int long encoder1PinB = 5; //pin 4 aurduino uno
 int long encoder1Pos = 0;
 int encoder1PinALast = LOW;
 int n2 = LOW;
 float grados2=90;
 int interrupciones2;

 #define motor1A 7
#define motor1B 8
 #define motor2A 11
#define motor2B 12
#define motor1_PWM 6
#define motor2_PWM 10

#define encoder1
volatile bool EncoderSet1;
volatile long ticksEncoder1 = 0;
#define encoder2
volatile bool EncoderSet2;
volatile long ticksEncoder2 = 0;

 void setup() { 
  //motor 1
   pinMode (encoder0PinA,INPUT);
   digitalWrite(encoder0PinA, LOW);
   pinMode (encoder0PinB,INPUT);
   digitalWrite(encoder0PinB, LOW);
   attachInterrupt(encoder0Pos, Encoder1A, RISING); 
   Serial.begin (115200);
   //para la direccion del motor
 pinMode(motor1A, OUTPUT);      
 pinMode(motor1B, OUTPUT); 
 

 
 if((grados>0) && (grados<=135)){
 digitalWrite(motor1A, HIGH);   
    } 
    if((grados<=-1) && (grados>=-135)){
      digitalWrite(motor1B, HIGH);
    }

//motor 2
 pinMode (encoder1PinA,INPUT);
   digitalWrite(encoder1PinA, LOW);
   pinMode (encoder1PinB,INPUT);
   digitalWrite(encoder1PinB, LOW);
   attachInterrupt(encoder1Pos, Encoder2A, RISING); 
   Serial.begin (115200);
   //para la direccion del motor
 pinMode(motor2A, OUTPUT);      
 pinMode(motor2B, OUTPUT); 
 

 
 if((grados2>0) && (grados2<=135)){
 digitalWrite(motor2A, HIGH);   
    } 
    if((grados2<=-1) && (grados2>=-135)){
      digitalWrite(motor2B, HIGH);
    }
    
 } 

 void loop(void) { 
  analogWrite(motor1_PWM,  55);//hasta 255
  analogWrite(motor2_PWM,  55);
  
   n = digitalRead(encoder0PinA);
   n = digitalRead(encoder1PinA);


//Motor 1
   //DE -45 A 45 GRADOS
   if ((grados>=-45) && (grados<=45)){
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones = ((grados*410/360));
       if (encoder0Pos == interrupciones){
        (encoder0Pos = 0);
       digitalWrite(motor1A, LOW);
       digitalWrite(motor1B, LOW);}
       
     } 
     else {
       encoder0Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones = ((grados*410/360));
        if (encoder0Pos == interrupciones){(encoder0Pos = 0);
        digitalWrite(motor1A, LOW);
        digitalWrite(motor1B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse ");
    Serial.println (interrupciones);
     }
     }

// DE 46 A 135 GRADOS
      if ((grados>45) && (grados<=135)){
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones = ((grados*450/360));
       if (encoder0Pos == interrupciones){(encoder0Pos = 0);
       digitalWrite(motor1A, LOW);
       digitalWrite(motor1B, LOW);}
       
     } 
     else {
       encoder0Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones = ((grados*450/360));
        if (encoder0Pos == interrupciones){(encoder0Pos = 0);
        digitalWrite(motor1A, LOW);
        digitalWrite(motor1B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse ");
    Serial.println (interrupciones);
     }
       }

      // DE -46 A -135
      if ((grados<-46) && (grados>=-135)){
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones = ((grados*450/360));
       if (encoder0Pos == interrupciones){(encoder0Pos = 0);
       digitalWrite(motor1A, LOW);
       digitalWrite(motor1B, LOW);}
       
     } 
     else {
       encoder0Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones = ((grados*450/360));
        if (encoder0Pos == interrupciones){(encoder0Pos = 0);
        digitalWrite(motor1A, LOW);
        digitalWrite(motor1B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse ");
    Serial.println (interrupciones);
     }
       }

   encoder0PinALast = n;

    //Motor 2

 //DE -45 A 45 GRADOS
   if ((grados2>=-45) && (grados2<=45)){
   if ((encoder1PinALast == LOW) && (n2 == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones2 = ((grados2*410/360));
       if (encoder1Pos == interrupciones2){
        (encoder1Pos = 0);
       digitalWrite(motor2A, LOW);
       digitalWrite(motor2B, LOW);}
       
     } 
     else {
       encoder1Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones2 = ((grados2*410/360));
        if (encoder1Pos == interrupciones2){(encoder1Pos = 0);
        digitalWrite(motor2A, LOW);
        digitalWrite(motor2B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse motor 2 ");
    Serial.println (interrupciones2);
     }
     }

// DE 46 A 135 GRADOS
      if ((grados2>45) && (grados2<=135)){
   if ((encoder1PinALast == LOW) && (n2 == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones2 = ((grados2*450/360));
       if (encoder1Pos == interrupciones2){(encoder1Pos = 0);
       digitalWrite(motor2A, LOW);
       digitalWrite(motor2B, LOW);}
       
     } 
     else {
       encoder1Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones2 = ((grados2*450/360));
        if (encoder1Pos == interrupciones2){(encoder1Pos = 0);
        digitalWrite(motor2A, LOW);
        digitalWrite(motor2B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse motor 2");
    Serial.println (interrupciones2);
     }
       }

      // DE -46 A -135
      if ((grados2<-46) && (grados2>=-135)){
   if ((encoder1PinALast == LOW) && (n2 == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
       //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
       interrupciones2 = ((grados2*450/360));
       if (encoder1Pos == interrupciones2){(encoder1Pos = 0);
       digitalWrite(motor2A, LOW);
       digitalWrite(motor2B, LOW);}
       
     } 
     else {
       encoder1Pos++;
       //grados = ((encoder0Pos*360/580));
       interrupciones2 = ((grados2*450/360));
        if (encoder1Pos == interrupciones2){(encoder1Pos = 0);
        digitalWrite(motor2A, LOW);
        digitalWrite(motor2B, LOW);}
     }
     Serial.print ("Pulsos antes de detenerse motor 2 ");
    Serial.println (interrupciones2);
     }
       }

   encoder1PinALast = n2;
 }   
 void Encoder1A()
{
  
  EncoderSet1 = digitalReadFast(encoder0PinB);   
#ifdef encoder1
  ticksEncoder1 -= EncoderSet1 ? -1 : +1;
#else
  ticksEncoder1 += EncoderSet1 ? -1 : +1;
#endif
}
 
 void Encoder2A()
{
  
  EncoderSet2 = digitalReadFast(encoder1PinB);   
#ifdef encoder2
  ticksEncoder2 -= EncoderSet2 ? -1 : +1;
#else
  ticksEncoder2 += EncoderSet2 ? -1 : +1;
#endif
}
