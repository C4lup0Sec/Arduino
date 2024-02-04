/*  ----------------------------------------------------------------
    www.prometec.net
    Prog_38_1
    
    Gobernando una matriz LED de 8x8 con un MAX7219 y SPI
--------------------------------------------------------------------  
*/

#include "LedControlMS.h"
#define NumMatrix 1       // Cuantas matrices vamos a usar

LedControl lc=LedControl(12,11,10, NumMatrix);  // Creamos una instancia de LedControl

 void setup() 
 {
  for (int i=0; i< NumMatrix ; i++)
     {
        lc.shutdown(i,false);    // Activar las matrices       
        lc.setIntensity(i,8);    // Poner el brillo a un valor intermedio
        lc.clearDisplay(i);      // Y borrar todo
     }
}

void loop() 
{
  lc.writeString(0,"Curso Arduino de Prometec.net");
  delay(1000);
}
