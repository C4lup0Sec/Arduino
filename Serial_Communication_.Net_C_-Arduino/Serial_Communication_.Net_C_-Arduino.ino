//https://youtu.be/QNLr-3TJWYI
//HMI 3 Serial UART Communication .Net C# and Arduino
//Autor:Hazael Fernando Mojica García
int pinLed =8;
int pinServo=13;
int pinPush=4;
int pinPotA=0;
int pwmVal=0;

void setup() 
{
 Serial.begin(115200);
 pinMode(pinLed, OUTPUT); 
 pinMode(pinServo, OUTPUT); 
 pinMode(pinPush, INPUT); 
 pinMode(pinPotA, INPUT);
}

void loop() 
{
if(Serial.available())
  {
    switch(Serial.read())
    {
      case 'a':
        digitalWrite(pinLed, HIGH);
      break;
      case 'b':
        digitalWrite(pinLed, LOW);
      break;   
      case 'c':
         increaseServo();
      break;   
      case 'd':
         decreaseServo();
      break;   
      case 'e':
         readDigitalVal();
      break;
      case 'f':
         readAnalogVal();
      break;

    }  
  }
}

void increaseServo(){
 pwmVal += 5;
 if(pwmVal > 255){
  pwmVal = 255;
 }
  analogWrite(pinServo, pwmVal);
//Serial.println(pwmVal);
}

void decreaseServo()
{
 pwmVal -= 5;
 if(pwmVal < 0)
  {
    pwmVal = 0;
  }
 analogWrite(pinServo, pwmVal);
//Serial.println(pwmVal);
}

void readDigitalVal()
{
  if (digitalRead(pinPush))
    {
      Serial.println("HIGH");   
    }
  else  
    {
      Serial.println("LOW");
    }
}

void readAnalogVal()
{
  Serial.println(analogRead(pinPotA));
}

