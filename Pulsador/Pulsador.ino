/**************************/
/* Encender LED con Botón */
/*              Pulsador             */
/**************************/

/*** Fernando Martinez Mendoza ***/

//** Definiciones **//

int pulsador=0;                     //almacena el estado del botón

//** Programa **//
void setup() {
  pinMode(2, OUTPUT);        //declaramos el pin 2 como salida
  pinMode(4, INPUT);           //declaramos el pin 4 como entrada
}

void loop() {
  pulsador = digitalRead(4);   //lee el estado del botón
  if(pulsador==HIGH) {          //si el estado es pulsado
    digitalWrite(2, HIGH);       //se enciende el led
  }
  else{                                   //si el estado es no pulsado
    digitalWrite(2, LOW);       //se apaga el led
  }
}
