// http://www.prometec.net/8x8-max7219/


#include "LedControlMS.h"
#define NumMatrix 1       // Cuantas matrices vamos a usar

LedControl lc=LedControl(12,11,10, NumMatrix);  // Creamos una instancia de LedControl

void setup()
   {
      for (int i=0; i< NumMatrix ; i++)
        {
           lc.shutdown(i,false);    // Activar las matrices
           lc.setIntensity(i,1);    // Poner el brillo a un valor intermedio
           lc.clearDisplay(i);      // Y borrar todo
        }
   }

void loop()
   {
        lc.writeString(0," HOLA MUNDO 0123456789 9876543210");
        delay(1000);
   }

/*
 * 
 * SI me habéis aguantado hasta aquí, ya estáis familiarizados con la idea, de que cuando en electrónica algo es un asco, 
 * por trabajoso, pesado o molesto, alguien se descuelga con un chip integrado que nos resuelve 
 * la papeleta y así podemos dedicarnos a pensar en lo que queremos y no estar preocupados 
 * por si se suelta un cable o por si habremos definido bien las matrices de caracteres.

Y como ya sospechabais, las matrices LED de 8×8, no son una excepción.

De hecho, tenemos un integrado muy extendido del fabricante Maxim, 
el MAX7219/MAX7221 que nos hace reconciliarnos con las matrices 
LEDs y hasta con los displays de 7 segmentos. Sus características son:

MAX7219
  
Entrada y salida en serie, para necesitar menos pines.
Controla displays de 7 segmentos de hasta 8 dígitos.
Bar graph displays o Barras de LEDs.
Matrices de 8×8 o hasta 64 LEDs individuales.
Solo requiere una resistencia externa para los 64 LEDs.
Incluye decodificador BCD (No hay necesidad de dibujar matrices de caracteres, 
las lleva incluidas. Mayúsculas, minúsculas y hasta números y signos).
Se encarga del multiplexado de los caracteres y dígitos.
Incluye memoria de los caracteres.
Es compatible con SPI y QSPI, (Algún día tendremos que hablar del SPI).
Es barato y se consiguen por pocos euros.
 
Así que la única razón para manejar cualquier tipo de displays LED a mano y cableando, 
es la de comprender un circuito y aprender (Sufriendo por supuesto), 
pero en el mundo real usaremos un chip de este estilo, porque nos ahorrará muchas horas de  improperios.

Array LED 8x8
En el futuro incluiremos alguna sesión mostrando como manejar displays con el chip directamente, 
pero de momento vamos a empezar por una placa que incluye una matriz de 8×8 con uno de estos chips.

Por menos  de lo que valen los componentes, 
ya nos venden unas plaquitas con una matriz gobernada por un MAX7219
y con pines para olvidarnos de las complicaciones. 
Son fáciles de montar en una protoboard y con la ventaja añadida de que se pueden cascadear, 
es decir, montar hasta 8 en serie. La conexión con nuestros Duino es a través de un puerto serie asíncrono SPI
 * 
 * Para manejar el array, existe disponible una librería de control, llamada LedControlMS y que podéis descargar desde aquí Libreria adafruit LEDControl

Una vez que la hayáis instalado con Programa\Importar Librería\Añadir librería, debéis lo primer hacer el include correspondiente:

#include "LedControlMS.h"
Después indicar cuantos displays vamos a usar, uno de momento y crear una instancia de la clase LedControl, 
pasándole los pines de control y por último el número de matrices que vamos a usar:

#define NumMatrix 1
LedControl lc=LedControl(12,11,10, NumMatrix);
Cuando arrancamos las matrices están en modo standby. Hay que levantarlas

for (int i=0; i< NumMatrix ; i++)
   {
       lc.shutdown(i,false);  // Activar la matriz
       lc.setIntensity(i,8);  // Poner el brillo a un valor intermedio
       lc.clearDisplay(i);    // Y borrar todo
   }
Y ya solo queda escribir el mensaje:

lc.writeString(0,"Curso Arduino de Prometec.net");
 * 
 * Como podeis ver, igual igual que en la sesión anterior.No tenemos que definir arrays de caracteres, 
 * ni preocuparnos de multiplexar los pines.

 
Soy un fiel defensor de trabajar lo mínimo para conseguir nuestros objetivos 
(en la jerga informática se llama optimizar recursos), pero esto es porque los chicos de Adafruit, 
a los que nunca les daremos suficientemente las gracias, se han trabajado una librería para nosotros.
Pero no os equivoquéis, esta librería por debajo, hace exactamente lo que vimos en la sesión anterior. 
Definir arrays de caracteres y funciones de multiplexado de LEDs.
Si tenéis interés, (Alguien habrá digo yo) podéis verlo, porque haciendo 
\\Programa\Añadir fichero podéis buscar dos programas en vuestro directorio de librerías, 
que suele ser\Documents\Arduino\libraries\LedControlMS en Windows y si cargáis LedControlMS.cpp veréis 
los programas que forman la librería(No os asusteis, que las libreiras no estan hechas para que las entiendan los novatos).
 * 
 */
   
