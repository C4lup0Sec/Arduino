/*
 * utilizacion de visual studio y arduino IDE para controlar un servo por el puerto serial sin retardo
 */

#include <Servo.h>
int val; //Variable de entrada del Serial
Servo servo; //Creamos un objeto Servo de nombre... servo
 
void setup()
{
 Serial.begin(115200); //Iniciamos el serial
 servo.attach(11); //Conectamos el servo al pin digital 3
}

void loop() 
  {
    // put your main code here, to run repeatedly:
    serialevent();
  }

void serialevent()
{
    val=Serial.parseInt();
    if(val != 0)
    {
      servo.write(val);
    }
}
