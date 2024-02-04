const int trig = 13;
const int echo = 12;
const int valor_deseado = 20;

long duracion;
int error,distancia,distancia_anterior,m,salida,x;
float INC1,INC2,INC3,DEC1,DEC2,DEC3,MAN1,MAN2,MAN3;
float N,C,P,B,E,S;
float Pinc,Pdec,Pman,fuzzy;
void setup()
{
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
   delay(10);
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   duracion = pulseIn(echo,HIGH);
   distancia = duracion*0.034/2;             //distancia
   error = valor_deseado - distancia;        //error
   error= constrain(error,-10,10);
   m = distancia_anterior - distancia;       //pendiente
   m= constrain(m,-10,10);
   distancia_anterior=distancia;
 //...........................................................................

 if(error<=-5)
 {
  N=1; C=0; P=0;
 }
 if(error>-5 && error<0)
 {
  N= -0.2*error; 
  C= (0.2*error)+1; 
  P=0;
 }
 if(error==0)
 {
  N=0; C=1; P=0;                             //PERTENENCIA ERROR
 }
 if(error>=5)
 {
  N=0; C=0; P=1;
 }
 if(error>0 && error<5)
 {
  N=0; 
  C= (-0.2*error)+1; 
  P=0.2*error;
 }
//.................................................................................

if(m<=-5)
 {
  B=1; E=0; S=0;
 }
 if(m>-5 && m<0)
 {
  B= -0.2*m; 
  E= (0.2*m)+1; 
  S=0;
 }
 if(m==0)
 {
  B=0; E=1; S=0;                             //PERTENENCIA PENDIENTE
 }
 if(m>=5)
 {
  B=0; E=0; S=1;
 }
 if(m>0 && m<5)
 {
  B=0; 
  E= (-0.2*m)+1; 
  S= 0.2*m;
 }
//...............................................................................

    DEC1=min(N,B);
    
    DEC2=min(N,E);
    
    MAN1=min(N,S);
    
    DEC3=min(C,B);
    
    MAN2=min(C,E);    
    
    INC1=min(C,S);
    
    MAN3=min(P,B);
    
    INC2=min(P,E);
    
    INC3=min(P,S);

//...................................................................................

Pinc=sqrt((INC1*INC1)+(INC2*INC2)+(INC3*INC3));
Pdec=sqrt((DEC1*DEC1)+(DEC2*DEC2)+(DEC3*DEC3));      //CALCULO CENTRO DE MASA
Pman=sqrt((MAN1*MAN1)+(MAN2*MAN2)+(MAN3*MAN3));
//...................................................................................

fuzzy = ((Pdec*-2000)+(Pman*0)+(Pinc*2000))/(Pdec+Pman+Pinc);
x=(int)fuzzy;
salida = salida + x;
salida= constrain(salida,0,255);
    
  analogWrite(3, salida);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255

  Serial.print("PWM=         EROR=       DISTANCIA= \n");
  Serial.print("     ");
  Serial.print(salida);
  Serial.print("            ");
  Serial.print(error);
  Serial.print("                ");
  Serial.print(distancia);
  Serial.print("     ");
  Serial.println("");    
}
