const int pinLED = 13;
 
void setup()
{
 Serial.begin(9600);
 pinMode(pinLED, OUTPUT);
}
 
void loop() {
      if (Serial.available() > 0){
        int option = Serial.read();
        if (option == 'a'){
          digitalWrite(pinLED, LOW); 
        }
      if (option == 'b'){
        digitalWrite(pinLED, HIGH);
        }
    }
}
