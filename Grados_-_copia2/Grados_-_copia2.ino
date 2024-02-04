#include <digitalWriteFast.h>
#define motor1A 11
#define motor1B 12
#define motor1_PWM 10
#define encoder1
  int long encoder0PinA = 2; //pin 3 aurduino uno
  int long encoder0PinB = 3; //pin 4 aurduino uno
  int long encoder0Pos = 0;
  int encoder0PinALast = LOW;
  int n = LOW;
  float grados=135;
  int interrupciones=0;
  volatile bool EncoderSet1;
  volatile long ticksEncoder1 = 0;

 void setup() 
 { 
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

     if((grados>0) && (grados<=135))
     {
      digitalWrite(motor1A, HIGH);   
     } 
      if((grados<=-1) && (grados>=-135))
      {
      digitalWrite(motor1B, HIGH);
      }
 } 

 void loop(void) 
 { 
  analogWrite(motor1_PWM,  150); // hasta 255 
  n = digitalRead(encoder0PinA);
   //Motor 1
   //DE -45 A 45 GRADOS
   if ((grados>=-45) && (grados<=45))
   {
      if ((encoder0PinALast == LOW) && (n == HIGH)) 
      {
        if (digitalRead(encoder0PinB) == LOW) 
        {
          encoder0Pos--;
          //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
          interrupciones = ((grados*410/360));
          if (encoder0Pos == interrupciones)
          {
            (encoder0Pos = 0);
            digitalWrite(motor1A, LOW);
            digitalWrite(motor1B, LOW);
          }
        } 
        else 
        {
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
   if ((grados>45) && (grados<=135))
    {
      if ((encoder0PinALast == LOW) && (n == HIGH)) 
      {
        if (digitalRead(encoder0PinB) == LOW) 
        {
          encoder0Pos--;
          //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
          interrupciones = ((grados*450/360));
          if (encoder0Pos == interrupciones)
          {
            (encoder0Pos = 0);
            digitalWrite(motor1A, LOW);
            digitalWrite(motor1B, LOW);
          } 
        } 
        else 
        {
          encoder0Pos++;
          //grados = ((encoder0Pos*360/580));
          interrupciones = ((grados*450/360));
          if (encoder0Pos == interrupciones)
          {
            (encoder0Pos = 0);
            digitalWrite(motor1A, LOW);
            digitalWrite(motor1B, LOW);
          }
        }
       Serial.print ("Pulsos antes de detenerse ");
       Serial.println (interrupciones);
     }
   }
// DE -46 A -135
   if ((grados<-46) && (grados>=-135))
      {
        if ((encoder0PinALast == LOW) && (n == HIGH)) 
        {
          if (digitalRead(encoder0PinB) == LOW) 
          {
          encoder0Pos--;
          //grados = ((encoder0Pos*360/580)); //cambia 255 por tus pulsos de tu encoder
          interrupciones = ((grados*450/360));
            if (encoder0Pos == interrupciones)
            {
              (encoder0Pos = 0);
              digitalWrite(motor1A, LOW);
              digitalWrite(motor1B, LOW);
            } 
          } 
          else  
          {
            encoder0Pos++;
            //grados = ((encoder0Pos*360/580));
            interrupciones = ((grados*450/360));
            if (encoder0Pos == interrupciones)
            {
              (encoder0Pos = 0);
              digitalWrite(motor1A, LOW);
              digitalWrite(motor1B, LOW);
            }
          }
        Serial.print ("Pulsos antes de detenerse ");
        Serial.println (interrupciones);
        }
      }
      encoder0PinALast = n; 
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
