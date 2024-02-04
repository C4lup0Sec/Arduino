// Relacion Pines arduino - termianles de nuestro led
int rojo = 9;//   9  PWM
int verde = 10;// 10 PWM
int azul = 11;//  11 PWM
 
void setup()
{
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
  Serial.begin(9600);
  Serial.println("Controlar LED RGB mediante Aplicacion C# y Arduinon JonathanMelgoza.com/BLOG");
  delay(1000);
}
 
String color = "";
int c = 0;

void loop()
{
   while (Serial.available())
   {
       char dato= Serial.read();
       color += dato;
       c++;
       
       if(c==9)
       {
         int r = color.substring(0,3).toInt();//  color rojo primeros 3 digitos
         int g = color.substring(3,6).toInt();//  color verde segundos 3 digitos
         int b = color.substring(6,9).toInt();//  color azul terceros 3 digitos
         setColor(r,g,b); // 000 000 000 apagado 255255255 encendido
                         //   R   G   B
         color = "";
         c=0;  
       }      
   }
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(rojo, red);
  analogWrite(verde, green);
  analogWrite(azul, blue);  
}
