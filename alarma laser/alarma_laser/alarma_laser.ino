//Circuito creado por electroARDUINO, Suscribiros a mi canal para mas proyectos.
http://www.youtube.com/user/electroARDUINO

//
int led1 = 12; //Declaramos cada led en su pin de arduino
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int ldr = 0;//Declaramos el pin donde va situado el ldr

void setup(){
  
pinMode(led1, OUTPUT);  //Declaramos los pines de los leds como salidas
pinMode(led2, OUTPUT);                           
pinMode(led3, OUTPUT);                                                                                            
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
  
  analogReference(EXTERNAL); //Decimos a arduino que vamos a usar una referencia externa (Potenciómetro)
}
  
void loop(){
  
  int estado=analogRead (ldr);//Esta variable(estado),lee el valor de la resistencia del ldr
  
  
  if(estado <=823){        //Establecemos una condicion de modo que cuando el valor de la resistencia del ldr sea menor o igual a 823, parpaden los leds en un determinado tiempo
 digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
 delay(100);
  digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
 delay(100);
  digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
 delay(100);
  digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
 delay(100);
  digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
 delay(100);
  digitalWrite (led1, HIGH);
 digitalWrite (led2, HIGH);
 digitalWrite (led3, HIGH);
 digitalWrite (led4, HIGH);
 digitalWrite (led5, HIGH);
 delay(100);
  }else {
 digitalWrite (led1, LOW);
 digitalWrite (led2, LOW);
 digitalWrite (led3, LOW);
 digitalWrite (led4, LOW);
 digitalWrite (led5, LOW);
    }
  }
