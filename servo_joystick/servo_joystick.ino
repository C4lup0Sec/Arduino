#include <Servo.h>          // Incluir la librería Servo
Servo servo1;               // Crear un objeto tipo Servo llamado servo1
int angulo = 0 ;
int Eje_X = A1 ;            // eje x en la entrada analogica 1
int Eje_Y = A2 ;            // eje y en la entrada analogica 2
int boton = 4  , LED = 12 ;

void setup()
    {
        servo1.attach(6) ;  // Conectar servo1 al pin 6
        pinMode( boton, INPUT_PULLUP) ;
    }

void loop()
    {
        angulo  = map( analogRead(A1), 0, 1024, 0, 180);
        servo1.write(angulo);       //escritura del servo en base al valor anterior mapeado
        if ( ! digitalRead(boton))  
              digitalWrite(LED, HIGH);
        else
              digitalWrite(LED, LOW);
        delay(250) ;
     }
