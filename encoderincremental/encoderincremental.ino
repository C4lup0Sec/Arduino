const int retardo=1000;
const int n = 8;
const int ledA = 13;
int sensor = 0;
long int cont = 0;
long int cont2 = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(ledA,OUTPUT);
  attachInterrupt(0,sensorA,CHANGE);
}

void loop()
 {
  Serial.print("v totales=");
  Serial.println(cont/n);
  Serial.print("v RPM=");
  Serial.println(cont2*60000/(n*retardo));
  Serial.println();
  cont2=0;
  delay(retardo);
 } 
void sensorA(){
  sensor = digitalRead(2);
  if (sensor == 1) {
    digitalWrite(ledA, HIGH);
    cont = cont + 1;
    cont2 = cont2 + 1;
  }
  else
  digitalWrite(ledA, LOW);
}
