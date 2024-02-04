// sistema secuencial de un servo 
#include <Servo.h>

Servo servo1; //muneca
Servo servo2; //codo
Servo servo3; //hombro
int command = 0;      //iniciamos command con un valor 0       

void setup() 
{
  Serial.begin(115200);       //iniciamos el monitor serial a 115200 bitesporsegundo
  servo1.attach(11);
  servo2.attach(10);
}
  void loop()        //iniciamos un ciclo "infinito"
  { 
    getCommand();     //utilizamos el comando getCommand que anteriormente creamos
    execCommand();    //utilizamos el comando execCommand que anteriormente creamos
  }
    void getCommand()//iniciamos un nuevo comando (getCommand)
    { 
      if(Serial.available())//si el puerto serial esta disponible
      {
        command = Serial.read(); //igualamos el valor de comando a el valor serial que no arrojen
      }
    }
    void execCommand()//iniciamos un nuevo comando (execComand)
    { 
      switch(command)  //iniciamos un comando de seleccion en base a el valor obtenido de "command"
      {
        case 'a'://asci tabla 97 checar , Turn ON LED,primer caso (caso "a")
          servo1.write(90);
          delay(1500);
          servo1.write(180);
          delay(1500);
          servo2.write(45);
          delay(1000);
          servo2.write(135);
          delay(1000);
          break; //le decimos al programa que hasta aqui acaba el caso "a"   
     
          command = 0; //iniciamos comand con un valor 0
        case 'b': //segundo caso (caso "b")
          servo2.write(90);
          delay(1500);
          servo2.write(40);
          delay(1500);
          servo1.write(0);
          delay(2500);
          servo1.write(180);
          delay(2500);
          break; //le decimos al programa que hasta aqui acaba el caso "b"  
      }
    }
