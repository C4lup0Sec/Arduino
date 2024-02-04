int val;
void setup()
  {
    Serial.begin(9600);
  }
void loop()
  {
    val = analogRead(3);
    val = val / 4;
    delay(100);
    Serial.write(val);
  }
  /*
La secuencia de pasos a seguir una para realizar este programa, se explican a 
continuación:
Primeramente es necesario declarar una variable, en la cual se guardara el dato a 
leer del puerto análogo, esta variable se declara de forma global en la parte de 
arriba de todo el código.

Después, dentro del ciclo setup(), configurar la velocidad con la que se recibirán 
los datos. El siguiente paso es dentro del ciclo infinito void loop(), donde se 
declara la línea val=analogRead(3); para especificar que a la variable 
val se le asignara el valor leído del puerto 3 análogo. Para finalizar, se mandara 
el valor de la variable utilizando el puerto serial y la función write, no sin 
antes poner una instrucción delay(100); para retardar un poco el proceso dentro 
del ciclo.
Nota: la línea val=val/4; se explicara mas adelante, pero si es necesario incluirla.
 */
