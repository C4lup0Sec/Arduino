
// CONS
int setheight = 15 ; //MAX 19
int totalheight = 29; 
int balldiameter = 5;

//VARS

long duration;
int sensorballdistance = 0;
int pwmoperation = 0;
int floorballdistance = 0 ;
int pwmvalue = 225;

// def pins 
const int trigPin = 9;
const int echoPin = 10;
int pwm = 6;

//EXPERT SYSTEM
void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(1200);
}

void loop()
{

//RS04
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
sensorballdistance = duration*0.034/2 - 1;

//Height set
floorballdistance = totalheight - sensorballdistance - balldiameter;
pwmoperation = pwmvalue * 0.39215686274;

pwmvalue = max(pwmvalue, 215);
pwmvalue = min(pwmvalue, 230);

if (floorballdistance < setheight){ pwmvalue = pwmvalue + 1; }
if (floorballdistance > setheight){ pwmvalue = pwmvalue - 1; }
if (floorballdistance == setheight){ pwmvalue = pwmvalue; }

//PWM
// analogRead 0-1023, analogWrite 0-255
analogWrite(pwm, pwmvalue);

// SERIAL MONITOR PRINT

Serial.println(" ");
Serial.println("-----------------------");

Serial.print("PWM %OPERATION VALUE:""\t");
Serial.println(pwmoperation);

Serial.print("TOTAL HEIGHT:""\t""\t");
Serial.println(totalheight);

Serial.print("SENSOR-BALL DISTANCE:""\t");
Serial.println(sensorballdistance);

Serial.print("FLOOR-BALL DISTANCE:""\t");
Serial.println(floorballdistance);

Serial.print("PWM VALUE:""\t");
Serial.println(pwmvalue);

}
