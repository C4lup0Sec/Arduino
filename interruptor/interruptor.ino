/**************************/
/* Encender LED con Botón */
/*           Interruptor 1          */
/**************************/

/*** Fernando Martinez Mendoza ***/

//** Definiciones **//

int pulsador=0;                   //almacena el estado del botón
int estado=0;                      //0=led apagado, 1=led encendido

//** Programa **//

void setup() {
  pinMode(2, OUTPUT);       //declaramos el pin 2 como salida
  pinMode(4, INPUT);          //declaramos el pin 4 como entrada
}

void loop() {
  pulsador = digitalRead(4); //lee si el botón está pulsado
  
  if(pulsador==HIGH){         //si el boton es pulsado
    estado=1-estado;
  }
  
  if(estado==1) {                 //si el estado es 1
    digitalWrite(2, HIGH);    //se enciende el led
  }
  else{                                //si el estado es 0
    digitalWrite(2, LOW);    //se apaga el led
  }
}
