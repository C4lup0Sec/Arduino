int Sensor=A0; /* definimos el pin A0 con el nombre sensor  */
float temperatura; /* variable flotante donde se almacena la temperatura */

void setup()
{
 Serial.begin(9600); /* iniciamos la Com. Serial a 9600 baud  */
}

void loop()
{
  temperatura = analogRead(Sensor);     /* lectura del pin analogico en la variale de temperatura */
  temperatura = temperatura*0.48828125; /* conversion para llevar el valor a grados celcius */
  Serial.print(temperatura);            /* imprimimos el valor en el monitor serial */
  Serial.println("*C");                 /* imprimimos *C (grados celcius) */
  delay(1000);                          /* 1 segundo de espera entre sensado */
}
