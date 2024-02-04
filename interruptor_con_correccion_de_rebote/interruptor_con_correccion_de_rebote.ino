/**************************/
/* Encender LED con Botón */
/* Interruptor sin rebote */
/**************************/

/*** Fernando Martinez Mendoza ***/

//** Definiciones **//

int pulsador=0;              //almacena el estado del botón
int estado=0;                //0=led apagado, 1=led encendido
int pulsadorAnt=0;           //almacena el estado anterior del boton

//** Programa **//

void setup() {
  pinMode(2, OUTPUT);        //declaramos el pin 2 como salida
  pinMode(4, INPUT);         //declaramos el pin 4 como entrada
}

void loop() {
  pulsador = digitalRead(4); //lee si el botón está pulsado
  
  if((pulsador==HIGH)&&(pulsadorAnt==LOW)){  //si el boton es pulsado y antes no lo estaba
    estado=1-estado;
    delay(40);               //pausa de 40 ms
  }
  pulsadorAnt=pulsador;      //actualiza el nuevo estado del boton        
  
  if(estado==1) {            //si el estado es 1
    digitalWrite(2, HIGH);   //se enciende el led
  }
  else{                      //si el estado es 0
    digitalWrite(2, LOW);    //se apaga el led
  }
}

