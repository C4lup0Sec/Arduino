// Motor Control Via Bluetooth Demo
// By keuwlsoft:  www.keuwl.com  4th Oct 2015
// cc Attribution-ShareAlike

// This sketch controls two 28BYJ-48 stepper motors using an Arduino Uno
// and ULN2003 Drivers.  Control is achieved by Bluetooth using an HC-06
// module and an Android device with keuwlsofts 'Bluetooth Electronics' App.
// Sketch assumes that it is controlling motors attached to two wheels of a car.

#include <Stepper.h>

int steps_per_rev = 2048;
Stepper stepper2(steps_per_rev, 4,6,5,7); //Left Stepper
Stepper stepper1(steps_per_rev, 8,10,9,11); //Right Stepper

int steps1=0; //number of steps for Left Stepper each loop
int steps2=0;
int roll,pitch; //roll and pitch sent from Android device
int pad_x,pad_y; //control pad values sent from Andorid device
char BluetoothData; // the Bluetooth data received
boolean acc_on=false; //Flag to inidicate if to use accelerometer values

void setup() {
  
  stepper1.setSpeed(10); //Set Stepper speed in RPM
  stepper2.setSpeed(10);

  //Set Digital Pins 2, 3, 12 and 13 as Output
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  Serial.begin(9600); //Initialise commuication for Bluetooth
}

void loop() {

  //Check Bluetooth for new Instructions
  if (Serial.available()){
    BluetoothData=Serial.read(); //Get next character from bluetooth
     
   //**** Accelerometer  -  sends 'Aroll,pitch*' every 150 ms
     if(BluetoothData=='A'){
      roll=Serial.parseInt(); 
      while (BluetoothData!='*'){
        if (Serial.available()){
          BluetoothData=Serial.read(); //Get next character from bluetooth
          if(BluetoothData==',')pitch=Serial.parseInt();
        }
      }
      if (acc_on){ 
       //Algorithm to convert roll and pitch into step movements for each loop
        if (roll>50) roll=50;
        if (roll<-50) roll=-50;
        if (pitch<45) pitch=45;
        if (pitch>135) pitch=135;
        steps1=steps2=(90.0-pitch)/4.5;
        if (roll>0) steps2-=steps1*roll/25.0;
        if (roll<0) steps1+=steps2*roll/25.0;
      }
    }
    if(BluetoothData=='B')acc_on=true;
    if(BluetoothData=='b'){
      acc_on=false;
      steps1=steps2=0;
    }
      
  //**** LEDs
    if(BluetoothData=='P') digitalWrite(2,HIGH);
    if(BluetoothData=='p') digitalWrite(2,LOW);
    if(BluetoothData=='Q') digitalWrite(3,HIGH);
    if(BluetoothData=='q') digitalWrite(3,LOW);
    if(BluetoothData=='R') digitalWrite(12,HIGH);
    if(BluetoothData=='r') digitalWrite(12,LOW);
    if(BluetoothData=='S') digitalWrite(13,HIGH);
    if(BluetoothData=='s') digitalWrite(13,LOW);

  //**** Control Pad on Right -  Sends 'X__,Y___*' every 150ms
    if(BluetoothData=='X'){
      pad_x=Serial.parseInt();
      while (BluetoothData!='*'){
        if (Serial.available()){
          BluetoothData=Serial.read(); //Get next character from bluetooth
          if(BluetoothData=='Y')pad_y=-Serial.parseInt();
        }
      }
      //Algorithm to convert pad position to number of steps for each motor
      float mag=sqrt(pad_y*pad_y+pad_x*pad_x);
      if (mag>10) mag=10;
      if (pad_y<0) mag=0-mag;
      steps1=steps2=mag;
       if (pad_x>0){ //turning right
        steps2=steps2-mag*pad_x/5.0;
      }else{ //turnign left
        steps1=steps1+mag*pad_x/5.0;
      }
    }
    
  //**** Control Pad on Left
    if(BluetoothData=='0') steps1=steps2=0; //Release 
    if(BluetoothData=='1') steps1=steps2=10; //Up
    if(BluetoothData=='3') steps1=steps2=-10; //Down
    if(BluetoothData=='4') { //Left
      steps1=-10;
      steps2=10; 
    }
    if(BluetoothData=='2') { //Right
      steps1=10;
      steps2=-10; 
    } 
    
  }

//**** Move Stepper Motors (Lasts ~60ms, if not, delay added to make it ~60ms)
  unsigned long t=millis();
  stepper1.step(steps1);
  stepper2.step(-steps2); //stepper 2 is positioned opposite orientation to stepper 1
  t=millis()-t; //calc time since started stepping
  if (t<60)delay(60-t); //add any extra time to make it up to 60ms
  
}
