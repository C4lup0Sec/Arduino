int pinLED = 3;                                 //declaracion de entrada "pinLED" en el pin 13(incorporado en la placa)
int pinPush = 7;                                //declaracion de entrada "pinPush" en el pin 7
int command = 0;                                 //iniciamos command con un valor 0       
int pot = 3;
int val = 0;           // variable to store the value read
void setup() { 
Serial.begin(115200);                            //iniciamos el monitor serial a 115200 bitesporsegundo
pinMode(pinLED, OUTPUT);                         //Declaramos "pinLED" como una salida 
pinMode(pinPush, INPUT);                         //Declaramos "pinPush" como una entrada 
pinMode(pot,INPUT);
}
  void loop() {                                  //iniciamos un ciclo "infinito"
  getCommand();                                  //utilizamos el comando getCommand que anteriormente creamos
  execCommand();                                 //utilizamos el comando execCommand que anteriormente creamos
 // lectura();
  
  }
  void getCommand() {                            //iniciamos un nuevo comando (getCommand)
    if(Serial.available()) {                     //si el puerto serial esta disponible 
      command = Serial.read();                   //igualamos el valor de comando a el valor serial que no arrojen
      command = digitalRead(pinPush);   // read the input pin
  digitalWrite(pinLED, command);
  
  }
}
  void execCommand() {                           //iniciamos un nuevo comando (execComand)
    switch(command) {                            //iniciamos un comando de seleccion en base a el valor obtenido de "command"
      
      case 'a'://Turn ON LED                     //primer caso (caso "a")
        digitalWrite(pinLED, HIGH);              //declaramos la salida digital "pinLed"
        Serial.println(command);
        command = 0;                             //iniciamos comand con un valor 0 
        break;                                   //le decimos al programa que hasta aqui acaba el caso "a"   
     
      case 'b'://Turn OFF LED                    //primer caso (caso "b")     
        digitalWrite(pinLED, LOW);               //declaramos la salida digital "pinLed"   
        command = 0;                             // iniciamos comand con un valor 0 
        break;                                   //le decimos al programa que hasta aqui acaba el caso "b"  
      
      case 'c'://Send pinPush Status             //primer caso (caso "c")      
        Serial.println(digitalRead(pinPush));    //el serial imprimira la lectura del pinPush     
        command = 0;                             //iniciamos comand con un valor 0     
        break;                                   //le decimos al programa que hasta aqui acaba el caso "c"   
  }                                                    
}
 void lectura() {
   analogRead(pot);
   val = analogRead(pot);    // read the input pin
   Serial.println(val);             // debug value                                             
 }
