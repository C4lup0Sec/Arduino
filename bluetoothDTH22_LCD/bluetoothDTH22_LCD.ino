// DHT22 Temperature and Humidity Sensor
// Result shown on a 16 by 2 LCD Display
// By keuwlsoft:  www.keuwl.com  12th July 2016
// cc Attribution-ShareAlike

// The DHT22 returns 5 bytes of data:
// Bytes 1 & 2 are Humidity, Bytes 3 & 4 are Temperature
// Byte 5 is the Checksum 

// A switch, when pressed will show max and min values
// Internal 20k pullup on Arduino used for switch

#include <LiquidCrystal.h>
/*
LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7);
*/
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //Digital pins used for the LCD
/* arduino-LCD
 *     GND-GND
 *      5V-VCC
 *       7-RS
 *       6-EN
 *       5-D4
 *       4-D5
 *       3-D6
 *       2-D7
 *     GND-R/W
 *       CONTRASTE A POTENCIOMETRO DE 10K OHMS
 *    TX=1
 *    RX=0
 */

int switch_pin = 9;
int DHT22_data_pin = 8;

boolean result[41]; //holds the result from reading the DHT22
unsigned int databytes[5]; // result converted into 5 bytes
unsigned int checksum;
int interval=500; // Delay between readings
float temp; //Temperature in degrees Celcius
float humidity; //Humidity in %RH
float max_temp,min_temp,last_temp;
float max_humidity,min_humidity,last_humidity;
boolean firstmeasurement=true; //flag used to set max and min on first measurement

void setup() {
  //Initialise Switch Pin to use the internal 20k Pullup resistor
    pinMode(switch_pin, INPUT_PULLUP);

  //Initialise LCD Display
    lcd.begin(16, 2);
    lcd.print("Starting ...");
     
  //Initiate Serial for Communication (Optional)
    Serial.begin(9600); 
}

void loop() {
  //Pause before taking measurement
    delay(interval); 
   
  //Trigger reading by holding data pin low for 18ms
    pinMode(DHT22_data_pin, OUTPUT);
    digitalWrite(DHT22_data_pin,LOW);
    delay(18);
    digitalWrite(DHT22_data_pin,HIGH);
    pinMode(DHT22_data_pin, INPUT_PULLUP); 
  
  //read 41 bits of signal
    for(int i=0;i<=40;i++){
      result[i]=(pulseIn(DHT22_data_pin, HIGH)>40);
    }

  //Convert result to bytes
    for (int j=0;j<5;j++){
      databytes[j]=0;
      for (int i=1;i<=8;i++){
        databytes[j]=databytes[j]<<1;
        if (result[j*8+i]) databytes[j]|=1;
      }
    }

  //Calculate Checksum
    checksum=0;
    for (int j=0;j<4;j++) checksum+=databytes[j];
    checksum&=0x00FF; //ignore exverything except lowest 8 bits

  //Check Checksum 
    if (checksum!=databytes[4]){ //Checksum Not Valid
      Serial.print("Bad Checksum"); //Optional
    }else{ //Checksum Valid -> We can Extract and Update ...
      
      //Extract Temperature and Humidity 
      humidity=(databytes[0]*256+databytes[1])/(float)10;  //Extract Humidity 
      temp=((databytes[2]&0x7F)*256+databytes[3])/(float)10; //Extract Temperature 
      if ((databytes[2]&0x80)>0) temp=-temp;   //MSB of Temperature gives it sign
  
      //Maximums and Minimums
      if (firstmeasurement){ //If first measurement, also set max and min
        max_temp=min_temp=temp;
        max_humidity=min_humidity=humidity;
        firstmeasurement=false;
      }else{
         if (temp>max_temp) max_temp=temp;
         if (temp<min_temp) min_temp=temp;
         if (humidity>max_humidity) max_humidity=humidity;
         if (humidity<min_humidity) min_humidity=humidity;
      }
  
      //Write Result to Serial Communication (Optional)
      Serial.print("*T"+String(temp,1)+"*H"+String(humidity,1)+"*");
    
      //Write Result to LCD
      if (digitalRead(switch_pin)){
        if (last_temp!=temp || last_humidity!=humidity){ //only update if reading changed
          lcd.clear();
          lcd.print("Temp  "+String(temp,1)+" degC");
          lcd.setCursor(0, 1);
          lcd.print("Humi  "+String(humidity,1)+" %RH");
          last_temp=temp;
          last_humidity=humidity;
        }
      }else{
        lcd.clear();
        lcd.print("Max "+String(max_temp,1)+"C "+String(max_humidity,1)+"%");
        lcd.setCursor(0, 1);
        lcd.print("Min "+String(min_temp,1)+"C "+String(min_humidity,1)+"%");
        last_humidity=-1;
      }
    }

}
