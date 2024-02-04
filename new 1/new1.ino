int pinLED = 13;
int pinPUSH = 2;
int command = 0;
int analogPin = 3;
void setup() {
  Serial.begin(115200);
  pinMode(pinLED, OUTPUT);
pinMode(pinPUSH, INPUT);

}

void loop() {
  getCommand();
  execCommand();
}
void getCommand(){
  if(Serial.available()){
    command = Serial.read();
  }
}
void execCommand(){
  switch(command){
    case 'a'://asci tabla 97 checar//
    digitalWrite(pinLED, HIGH);
    break;
     command = 0;
     case 'b':
    digitalWrite(pinLED, LOW);
    break;
     command = 0;
     case 'c':
   Serial.println(digitalRead(pinPUSH));
    break;
     command = 0;
    case 'd':
   Serial.println(analogRead(analogPin));
   command = 0;
    break;
  }
 
}