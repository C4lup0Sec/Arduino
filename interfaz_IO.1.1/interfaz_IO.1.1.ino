int pinLED = 13;      //declaracion de entrada "pinLED" en el pin 13(incorporado en la placa)
int pinPush = 2;      //declaracion de entrada "pinPush" en el pin 2
int command = 0;      //iniciamos command con un valor 0       
int analogPin = 3;   //declaramos variable store the value read en el pin 3
void setup() {
  Serial.begin(115200);       //iniciamos el monitor serial a 115200 bitesporsegundo
  pinMode(pinLED, OUTPUT);    //Declaramos "pinLED" como una salida
  pinMode(pinPush, INPUT);    //Declaramos "pinPush" como una entrada
  pinMode(analogPin, INPUT);  //Declaramos "analogPin" como una entrada
}
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
