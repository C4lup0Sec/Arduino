const int trig = 13;                   //EL PIN TRIG DEL SENSOR, SE ASIGNA AL PIN DIGITAL 13 DEL ARDUINO
const int echo = 12;                   //EL PIN ECHO DEL SENSOR, SE ASIGNA AL PIN DIGITAL 12 DEL ARDUINO
const int valor_deseado = 15;          //SE ASIGNA LA DISTANCIA DESEADA DE LA PELOTA DE UNICEL

long duracion;
int distancia,error;                   //SE DAN DE ALTA LAS VARIABLES
int salida=1;

void setup()
{
  Serial.begin(115200);
  pinMode(trig, OUTPUT);              //SE INICIALIZA LA COMUNICACION SERIAL Y SE INICIALIZAN LOS PINES TRIG Y ECHO COMO SALIDA O ENTRADA
  pinMode(echo, INPUT);
}

void loop()
{
  delay(250);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);                 //EL SENSOR EMPIEZA A FUNCIONAR POR MEDIO DE ESTOS PASOS
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  duracion = pulseIn(echo,HIGH);
  distancia = duracion*0.034/2;         //SE TOMA LA LECTURA DE LA DISTANCIA POR MEDIO DE OPERACIONES LOGICAS
  
  error = distancia - valor_deseado;
  error= constrain(error,-10,10);       //POR MEDIO DE OPERACIONES OBTENEMOS EL ERROR Y SE CONSTRAE A VALORES ENTRE -10 Y 10
  //......................................................

switch(error)
{                                      //SE REALIZAN DIVERSAS ACCIONES DEPENDIENDO DEL VALOR DEL ERROR
  case 10:
  salida=0;
  break;
  case 9:
  salida=3;
  break;
  case 8:
  salida=5;
  break;
  case 7:
  salida=15;
  break;
  case 6:
  salida=35;
  break;
  case 5:
  salida=55;
  break;
  case 4:
  salida=70;
  break;
  case 3:
  salida=80;
  break;
  case 2:
  salida=85;
  break;
  case 1:
  salida=88;
  break;
  case 0:
  salida=90;
  break;
  case -1:
  salida=92;
  break;
  case -2:
  salida=95;
  break;
  case -3:
  salida=100;
  break;
  case -4:
  salida=110;
  break;
  case -5:
  salida=125;
  break;
  case -6:
  salida=145;
  break;
  case -7:
  salida=170;
  break;
  case -8:
  salida=200;
  break;
  case -9:
  salida=235;
  break;
  case -10:
  salida=255;
  break;
  default:
  salida=0;
  break;  
}
 //..........................................................
  
salida= constrain(salida,0,255);
  
  analogWrite(3,salida);  //SE LE ASIGNA UN VALOR DE SALIDA AL PIN 3, USANDO LA FUNCION analogWrite, que es lo mismo que PWM

  Serial.print("PWM=         EROR=       DISTANCIA= \n");
  Serial.print("     ");
  Serial.print(salida);
  Serial.print("            ");
  Serial.print(error);
  Serial.print("                ");
  Serial.print(distancia);
  Serial.println(""); 
}  
