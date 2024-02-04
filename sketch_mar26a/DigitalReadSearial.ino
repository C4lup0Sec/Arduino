/*
 DigitalReadSerial
 Reads a digital input pin 2, prints the result in serial monitor

 Conditionals - If statement
 This example demonstrates the use of if() statements.
 It reads the state of a potentiometer (an analog input) and turns on an LED
 only if the potentiometer goes above a certain threshold level. It prints the analog value
 regardless of the level.
 The circuit:
 * potentiometer connected to analog pin 0.
 Center pin of the potentiometer goes to the analog pin.
 side pins of the potentiometer go to +5V and ground
*/
int pushBoton = 2;// digital pin 2 has a pushbutton attached to it. Give it a name:
// These constants won't change:
const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input
// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pushBoton, INPUT); // make the pushbutton's pin an input:
  pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output:
}
// the loop routine runs over and over again forever:
void loop() 
{  
  int buttonState = digitalRead(pushButton);// read the input pin:
  int analogValue = analogRead(analogPin); // read the value of the potentiometer:
    if (analogValue > threshold)// if the analog value is high enough, turn on the LED:
    {
        digitalWrite(ledPin, HIGH);
    }
    else 
    {
        digitalWrite(ledPin, LOW);
    }
  Serial.println(buttonState);// print out the state of the button:
  Serial.println(analogValue);  // print the analog value:
  delay(1);        // delay in between reads for stability
}
