int pot;        // variable to store the read value
int pos;
void setup()
{
  Serial.begin(115200);
}

void loop()
{
  pot= analogRead(A0);
  pos=map(pot,0,1023,0,255);
  analogWrite(3, pos);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
   
  Serial.println("% POTENCIOMETRO ");
  Serial.println(" ");
  Serial.println(pos);
}
