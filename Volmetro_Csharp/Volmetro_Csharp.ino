int pot=14; /* analogico A0 */
int volt=0;
String voltaje2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  volt=analogRead(pot);
  voltaje2=String(volt);
  Serial.println(voltaje2);
  delay(100);
}
