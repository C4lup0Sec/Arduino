 #include <LiquidCrystal.h>
 LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 byte deg[7] = {           //to display ° character
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  };
 unsigned char a, b,i,rh1,rh2,t1,t2,sum;
 void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.createChar(0, deg);
 }
 int startsignal(){
  pinMode(8, OUTPUT);
  digitalWrite(8,LOW);
  delay(18);
  digitalWrite(8,HIGH);
  delayMicroseconds(30);digitalWrite(8,LOW);
  pinMode(8, INPUT);}
  
 int checkresponse(){
  a = 0;delayMicroseconds(40);
  if(digitalRead(8)==LOW){
    delayMicroseconds(80);
    if(digitalRead(8)==HIGH)
     a = 1;}
    delayMicroseconds(40);
  }
 
 int readdata(){
 for(b=0;b<8;b++){ 
   while(!digitalRead(8));  //Wait pin8 goes high
   delayMicroseconds(30);
   if(digitalRead(8)==LOW){ 
    bitClear(i,7-b);}
   else { bitSet(i,7-b); 
       while(digitalRead(8));//Wait pin8 goes low
      }
      }
  }
 void loop() {
  startsignal();    //send the start signal to the sensor
  checkresponse();  //check if the sensor sends the response signal
  if (a==1){
   readdata();
   rh1 = i;
   readdata();
   rh2 = i;
   readdata();
   t1=i;
   readdata();
   t2 = i;
   readdata();
   sum = i;
   if (sum == rh1+rh2+t1+t2){      //Checksum
     //Display Temperature  
     lcd.clear();
     lcd.setCursor(0, 0); lcd.print("Temp    =   .0 C");
     lcd.setCursor(10, 0); lcd.print(t1);
     lcd.setCursor(14, 0);lcd.write(byte(0));
     //Display Humidity:
     lcd.setCursor(0, 1); lcd.print("Humidity=   .0%");
     lcd.setCursor(10, 1); lcd.print(rh1);
   }
   else{        //If the checksum is incorrect
   lcd.clear();
     lcd.setCursor(1, 0); lcd.print("Checksum error");}  
 }
   else {       //If the sensor does not respond
    lcd.clear(); 
    lcd.setCursor(2, 0); lcd.print("no response");
    lcd.setCursor(0, 1); lcd.print("from the sensor");
    } 
 delay(1000); 
 }    
