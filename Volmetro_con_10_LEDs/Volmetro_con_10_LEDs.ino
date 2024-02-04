int val,j=2;

void setup()
{
  Serial.begin(9600);
    for(int i=2;i<12;i++)
    {
      pinMode(j,OUTPUT);
      j++;
    }
}

void loop()
{
  val = analogRead(3);
  int j =0;
    for (int i=2;i<11;i++)  
      {
        if(bitRead(val,j)==1) 
          {
            digitalWrite(i,HIGH);
          }
        else
          {
            digitalWrite(i,LOW);
          }
        j++;
      }
  delay(100);
  Serial.println(val);
}
