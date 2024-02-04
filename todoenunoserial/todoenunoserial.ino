#include <Servo.h>

int B = 11;      //declaracion de entrada "pinLED" en el pin 13(incorporado en la placa)
int G = 10;      //declaracion de entrada "pinPush" en el pin 2
int R = 9;
int command = 0;      //iniciamos command con un valor 0 
int val; //Variable de entrada del Serial
int val1;
Servo servo; //Creamos un objeto Servo de nombre... servo
 
void setup()
{
  Serial.begin(115200); //Iniciamos el serial
  servo.attach(3); //Conectamos el servo al pin digital 3
  pinMode(R, OUTPUT); 
  pinMode(G, OUTPUT);    //Declaramos "pinLED" como una salida
  pinMode(B, OUTPUT);    //Declaramos "pinPush" como una entrada
 
/*
 * 
*/
}

void loop() 
{
/* grafica
//      int deger=analogRead(A0);
//      Serial.println(deger);  // gönderilen her veri bir alt satıra geçirilmelidir
//      delay(100);
//

//programavisualstudio 
//      if (Serial.available() > 0)
//      {
//        int option = Serial.read();
//        if (option == 'a')
//          {
//          digitalWrite(pinLED, LOW); 
//      }
//        if (option == 'b')
//          {
//            digitalWrite(pinLED, HIGH);
//          }
//      }
      
//Led n veces con serial
//repite el encendido y apagado mediante el puerto serial y visual studio//
//  if (Serial.available()>0) 
//  {
//    char option = Serial.read();
//      if (option >= '1' && option <= '9')
//      {
//         option -= '0';
//          for (int i = 0;i<option;i++) 
//          {
//           digitalWrite(pinLED, HIGH);
//           delay(100);
//           digitalWrite(pinLED, LOW);
//           delay(200);
//          }
//      }
//  }
  
enviar valores numericos
  //si existe información pendiente
//  if (Serial.available()>0){
    //leeemos la opcion
//    char option = Serial.read();
    //si la opcion esta entre '1' y '9'
   if (option >= '0' && option <= '9')
    {
      //restamos el valor '0' para obtener el numeroenviado
      option -= '0';
      for(int i=0;i<option;i++){
         digitalWrite(led, HIGH);
         delay(100);
         digitalWrite(led, LOW);
         delay(200);
      }
    }
  }
}


servo serial
      if(Serial.available() > 0) //Detecta si hay alguna entrada por serial
        {
          val = Serial.parseInt();
            if(val != 0)
             {
                servo.write(val); //Mueve el servo a la posición entrada (excepto si es 0)
              }
        }
        delay(500);
*/
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


/*
  void loop() {       //iniciamos un ciclo "infinito"
    getCommand();     //utilizamos el comando getCommand que anteriormente creamos
    execCommand();    //utilizamos el comando execCommand que anteriormente creamos
}
    void getCommand(){ //iniciamos un nuevo comando (getCommand)
      if(Serial.available()){ //si el puerto serial esta disponible
        command = Serial.read(); //igualamos el valor de comando a el valor serial que no arrojen
  }
}
    void execCommand(){//iniciamos un nuevo comando (execComand)
      switch(command){//iniciamos un comando de seleccion en base a el valor obtenido de "command"
      
        case 'a'://asci tabla 97 checar , Turn ON LED,primer caso (caso "a")
          digitalWrite(pinLED, HIGH); //declaramos la salida digital "pinLed" alto
          break; //le decimos al programa que hasta aqui acaba el caso "a"   
     
        command = 0; //iniciamos comand con un valor 0
        case 'b': //segundo caso (caso "b")
          digitalWrite(pinLED, LOW); //declaramos la salida digital "pinLed" bajo
          break; //le decimos al programa que hasta aqui acaba el caso "b"  
      
       command = 0;//iniciamos comand con un valor 0
        case 'c': //tercer caso (caso "c") Send pinPush Status    
          Serial.println(digitalRead(pinPush)); //el serial imprimira la lectura del pinPush
          break;//le decimos al programa que hasta aqui acaba el caso "c"   
                                              
        command = 0; //iniciamos comand con un valor 0
        case 'd'://cuarto caso (caseo "d") lectura del potenciometro
          Serial.println(analogRead(analogPin)); //el serial imprimira la lectura del pinPush
          command = 0; //iniciamos comand con un valor 0
          break;//le decimos al programa que hasta aqui acaba el caso "d"                
  }
}
*/
