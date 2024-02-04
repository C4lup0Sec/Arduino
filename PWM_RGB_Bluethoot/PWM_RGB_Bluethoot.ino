//PWM LED Brightness and Bluetooth Serial Link Demo
//By keuwlsoft:  www.keuwl.com  23rd Aug 2015


/*
Open the Arduino software, select the correct COM Port and Arduino device in the Tools menu, 
copy and paste the sketch and click upload. 
To program the device, 
make sure you remove pins 0 and 1 connecting to the Bluetooth module otherwise 
the Arduino will get confused trying to communicate to two serial devices simultaneously on the same pins. 
Re-connect them after programming. analogueWrite() 
takes two arguments, the pin number and a value which is an 8-bit number ranging from 0 (always low) to 255 (always high). 
When a slider identification character is received, in this case the 'R', 'G' or 'B' characters, 
it calls the parseInt() function which will read the next integer from the serial stream. 
The 3 sliders will send a character ('R', 'G' or 'B' in this case) to tell the arduino to be ready to receive the new brightness value, 
followed by the value. A final non numerical end character is also sent to make sure that the arduino parses
the integer value immediately rather than waiting around until another non numerical character is received. 
*/

int Red_LED_Pin = 9; // PWM Pin for Red LED
int Green_LED_Pin = 10; // PWM Pin for Green LED
int Blue_LED_Pin = 11; // PWM Pin for Blue LED

//Varibles to hold brightness values ranging from 0 (off) to 255 (fully on)
int Red_value=0;
int Green_value=0;
int Blue_value=0;

char BluetoothData; // the data received from bluetooth serial link

void setup() {
  
  // Initialise LED pins as outputs
  pinMode(Red_LED_Pin, OUTPUT);
  pinMode(Green_LED_Pin, OUTPUT);
  pinMode(Blue_LED_Pin, OUTPUT);

  //initialsie serial communication
  Serial.begin(115200);
}

void loop() {

  //Process any info coming from the bluetooth serial link
  if (Serial.available()){
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

