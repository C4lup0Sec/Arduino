const int trig = 13;
const int echo = 12;
const int valor_deseado = 25;

long duracion;
int distancia,error;
int salida=1;

void setup()

{
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}



void loop()

{
  delay(6);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  duracion = pulseIn(echo,HIGH);
  distancia = duracion*0.034/2;
  
  error = distancia - valor_deseado;
  //......................................................
  if(error > 10)
  {
    salida = salida - 50;  
  }
  if(error <= 10 && error > 5)                //ABAJO
  {
    salida = salida - 40;  
  }
  if(error <= 5 && error > 2)                //PARA SUBIR
  {
    salida = salida - 30;  
  }
   if(error <= 2 && error > 0)                //PARA SUBIR
  {
    salida = salida - 10;  
  }
  //........................................................
  if(error < -10)
  {
    salida = salida + 50;  
  }
  if(error >= -10 && error < -5)             //ARRIBA
  {
    salida = salida + 40;  
  }
  if(error >= -5 && error < -2)             //PARA BAJAR
  {
    salida = salida + 30;  
  }
    if(error >= -2 && error < -0)             //PARA BAJAR
  {
    salida = salida + 10;  
  }
  if(error==0)
  {
    salida=salida+0;
  }

  
 //..........................................................
  
  error= constrain(error,-11,11);
  salida= constrain(salida,0,255);
  
  
  analogWrite(3,salida);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255


  Serial.print("PWM=         EROR=       DISTANCIA= \n");
  Serial.print("     ");
  Serial.print(salida);
  Serial.print("            ");
  Serial.print(error);
  Serial.print("                ");
  Serial.print(distancia);
  Serial.println("");
   
  
}
  
