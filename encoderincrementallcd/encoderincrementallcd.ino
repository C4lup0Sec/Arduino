#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int retardo=1000;
const int n = 8;
const int ledA = 13;
int sensor = 0;
long int cont = 0;
long int cont2 = 0;
byte t;
byte rpm;

void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(ledA,OUTPUT);
  attachInterrupt(0,sensorA,CHANGE);
}

void loop()
 {
  lcd.setCursor(0, 0);
  lcd.print("v totales=");
  t=(cont/n);
  lcd.print(t);
  lcd.setCursor(0, 1);
  lcd.print("v RPM=");
  rpm=(cont2*60000/(n*retardo));
  lcd.print(rpm);
  cont2=0;
  delay(retardo);
  lcd.write(Serial.read());
  lcd.clear();
 } 
void sensorA(){
  sensor = digitalRead(8);
  if (sensor == 1) {
    digitalWrite(ledA, HIGH);
    cont = cont + 1;
    cont2 = cont2 + 1;
  }
  else
  digitalWrite(ledA, LOW);
}
