
#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
Servo myservo; 
int pos=0;
/*
Pins	SPI	   UNO  
1 (NSS) SAD (SS)   10    
2       SCK        13   
3       MOSI       11    
4       MISO       12   
5       IRQ        *      
6       GND       GND    
7       RST        5      
8      +3.3V (VCC) 3V3   
* Not needed
1 on ICPS header
*/
#define SAD 10
#define RST 9
MFRC522 nfc(SAD, RST);
#define ledPinAbierto    5
#define ledPinCerrado  6

void setup() {
   myservo.attach(3);  
   lcd.begin(16,2);  
   pinMode(ledPinAbierto  , OUTPUT); 
   pinMode(ledPinCerrado, OUTPUT);
   SPI.begin();
   Serial.begin(115200);
   Serial.println("BUSCANDO MFRC522.");
   nfc.begin();
   byte version = nfc.getFirmwareVersion();
   if (! version) {
    Serial.print("NO SE ENCONTRO MFRC522 ");
    while(1); //halt
   }
   myservo.write(180); 
   Serial.print("BUSCANDO CHIP MFRC522 ");
   Serial.print("FIRMWARE VERSION. 0x");
   Serial.print(version, HEX);
   Serial.println(".");
}

#define TARJETA 1 
#define LLAVE 1 
//CLAVE DE LA TAJETA
byte Autorizado[TARJETA][6] = {{0xD7, 0xE9, 0x7E, 0xB5, 0xFF, 0xFF, }};
// CLAVE DEL LLAVERO
byte Autorizado2[LLAVE][6] = {{0x83, 0x10, 0xF6, 0xE2, 0xFF, 0xFF, }}; 
void imprimeClave(byte *serial);
boolean esIgual(byte *key, byte *serial);
boolean chekaKey(byte *serial);

void loop() {
  lcd.setCursor(0,0);
  lcd.print("CECYTEM TECAMAC");
  lcd.setCursor(0,1);
  lcd.print("CERRADO        ");
  byte status;
  byte data[MAX_LEN];
  byte serial[5];
  boolean Abierto = false;
  digitalWrite(ledPinAbierto, Abierto);
  digitalWrite(ledPinCerrado, !Abierto);
  status = nfc.requestTag(MF1_REQIDL, data);
  myservo.write(180);
  
  if (status == MI_OK) {
    status = nfc.antiCollision(data);
    memcpy(serial, data, 5);    
    if(chekaKey(serial)){ 
      Serial.println("AUTORIZADO");
       imprimeClave(serial);
      lcd.setCursor(0,1);
      lcd.print("AUTORIZADO         ");
      Abierto = true;
      myservo.write(90);
    }else{ 
      imprimeClave(serial);
      lcd.setCursor(0,1);
      lcd.print("NO AUTORIZADO          ");
      Serial.println("NO AUTORIZADO");
      Abierto = false;
    }    
    nfc.haltTag();
    digitalWrite(ledPinAbierto, Abierto);
    digitalWrite(ledPinCerrado, !Abierto);
    delay(2000);
  }
  delay(500);
}

boolean esIgual(byte *key, byte *serial){
    for (int i = 0; i < 4; i++){
      if (key[i] != serial[i]){ 
        return false; 
      }
    }    
    return true;
  }

boolean chekaKey(byte *serial)
{
    for(int i = 0; i<TARJETA; i++)
    {
      if(esIgual(serial, Autorizado[i]))
        return true;
    }
      for(int i = 0; i<LLAVE; i++)
    {
      if(esIgual(serial, Autorizado2[i]))
        return true;
    }
   return false;
}

void imprimeClave(byte *serial)
{
    Serial.print("CLAVE: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(serial[i], HEX);
      Serial.print(" ");
    }
}
