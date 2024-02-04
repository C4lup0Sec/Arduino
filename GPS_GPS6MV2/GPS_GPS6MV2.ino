//http://www.leantec.es/blog/54_Tutorial-Arduino--Modulo-GPS-GPS6MV2.html

#include <SoftwareSerial.h>
SoftwareSerial gps(4,3);
char dato=' ';

void setup()
{
 Serial.begin(115200);            
 gps.begin(9600); 
}

void loop()
{
  if(gps.available())
  {
    dato=gps.read();
    Serial.print(dato);
    delay (50);
  }
}

/* 
 Con el código de más arriba se reciben los datos 'puros' es 
 decir datos que siguen el protocolo NMEA (National Marine 
 electronics Asociation). Este es un protocolo standar para 
 la recepcion de datos GPS.
 */
/*
 ejemplo de datos arrojados
 GPRMC,120121.00,A,3718.51170,N,00614.55235,W,1.114,,210416 
 120121.00: Nos indica la hora GMT ()
 A: Nos indica que el dato de posición es correcto. 
 (Si aparece una V es que no es correcto)
 3718.51170: Nos indica la longitud ()
 N: Nos indica al Norte.
 00614.55235: Nos indica la latitud ()
 W: Nos indica al Oeste
 1.114: Nos indica la velocidad en nudos.
 210416: Nos indica la fecha ()
*/
