#include <Servo.h> 
/*  servo  Turns right an servo for 9,6 second,then turn left for 9,6 second, repeatedly.  */
// Pin D2 has connected to signal(orange)
// Pin GND has connected to GND (brown)
// Pin 5V has connected to +5V (red)
Servo myservo;
int pos = 0;
int value = 0;
  void setup()
    {  
      myservo.attach(2);  
      Serial.begin(9600);
    }
  void loop()
{  
   for (pos = 0; pos <= 180; ++pos) 
    {    
      myservo.write(pos);    
      value = myservo.read();    
      Serial.println(value);    
      delay(50);
    }  
   for (pos = 180; pos >= 0; --pos) 
    {   
      myservo.write(pos); 
      value = myservo.read();    
      Serial.println(value);    
      delay(50);  
    }
}  
