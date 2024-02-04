/////////////////////////////////////////////////////////
// Lectura de los valores medidos por un sensor LDR  ///
////////////////////////////////////////////////////////
#include <LiquidCrystal.h>//utilizacion de la libreria lcd que esa por defecto
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//pines utilizados de lcd
int LDR_pin = 0; //declaracion de pin a0
int LDR_val = 0; //declaracion del valor del sensor = a cero

void setup(){//comando de inicio
  lcd.begin(16, 2);
  // Visualización de los valores por la consola, hay que ciclar en el botón Serial Monitor
  Serial.begin(9600);
}

void loop(){//comando de ciclo
  LDR_val = analogRead(LDR_pin); //lectura del pin a0
  lcd.print("LDR = "); //nombre preeliminar
  lcd.print(LDR_val, DEC); //impresion de la lectura expresada en sistema decimal 
  delay(1000); //tiempo de espera
  lcd.write(Serial.read()); //lectura del monior serial a lcd
  lcd.clear();
  }
