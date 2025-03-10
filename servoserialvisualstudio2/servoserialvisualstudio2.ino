/*
 * utilizacion de visual studio y arduino IDE para controlar un servo por el puerto serial sin retardo
//PWM LED Brightness and Bluetooth Serial Link Demo checar la app
//By keuwlsoft:  www.keuwl.com  23rd Aug 2015
*/
int Red_LED_Pin = 9; // PWM Pin for Red LED
int Green_LED_Pin = 10; // PWM Pin for Green LED
int Blue_LED_Pin = 11; // PWM Pin for Blue LED

//Varibles to hold brightness values ranging from 0 (off) to 255 (fully on)
int Red_value=0;
int Green_value=0;
int Blue_value=0;

char BluetoothData; // the data received from bluetooth serial link

void setup()
{
  // Initialise LED pins as outputs
  pinMode(Red_LED_Pin, OUTPUT);
  pinMode(Green_LED_Pin, OUTPUT);
  pinMode(Blue_LED_Pin, OUTPUT);
  Serial.begin(115200); //Iniciamos el serial
}

void loop() // put your main code here, to run repeatedly:
{
  //Process any info coming from the bluetooth serial link
  if (Serial.available())
    {
      BluetoothData=Serial.read(); //Get next character from bluetooth
      if(BluetoothData=='R') Red_value=Serial.parseInt(); //Read Red value
      if(BluetoothData=='G') Green_value=Serial.parseInt(); //Read Green Value
      if(BluetoothData=='B') Blue_value=Serial.parseInt(); //Read Blue Value
    }  
  //update LED Brightness
  analogWrite(Red_LED_Pin, Red_value);
  analogWrite(Green_LED_Pin, Green_value);
  analogWrite(Blue_LED_Pin, Blue_value);
  delay(10);
}
