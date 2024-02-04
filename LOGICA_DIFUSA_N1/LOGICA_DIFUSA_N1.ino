const int trig = 13;
const int echo = 12;
const int valor_deseado = 15;

long duracion;
int error,distancia,distancia_anterior,pendiente,salida,x;
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
   delay(250);
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   duracion = pulseIn(echo,HIGH);
   distancia = duracion*0.034/2;           //distancia
     
 error = valor_deseado - distancia;                  //error
 error= constrain(error,-10,10);

 pendiente = distancia_anterior - distancia;        //pendiente
 pendiente= constrain(pendiente,-10,10);
 distancia_anterior=distancia;
 //...........................................................................

 if(error<=-5)
 {
  N=1; C=0; P=0;
 }
 if(-5<error<0)
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
 if(0<error<5)
 {
  N=0; 
  C= (-0.2*error)+1; 
  P=0.2*error;
 }
//.................................................................................

if(pendiente<=-5)
 {
  B=1; E=0; S=0;
 }
 if(-5<pendiente<0)
 {
  B= -0.2*pendiente; 
  E= (0.2*pendiente)+1; 
  S=0;
 }
 if(pendiente==0)
 {
  B=0; E=1; S=0;                             //PERTENENCIA PENDIENTE
 }
 if(pendiente>=5)
 {
  B=0; E=0; S=1;
 }
 if(0<pendiente<5)
 {
  B=0; 
  E= (-0.2*pendiente)+1; 
  S= 0.2*pendiente;
 }
//...............................................................................

if( (error<0) && (pendiente<0) )
{
    if(N<B)
    {
      DEC1=N;
    }
    if(B<N)
    {
      DEC1=B;
    }
    else{DEC1=N;}
}

if( (error<0) && (-5<pendiente<5) )
{
    if(N<E)
    {
      DEC2=N;
    }
    if(E<N)
    {
      DEC2=E;
    }
    else{DEC2=N;}
}

if( (error<0) && (pendiente>0) )
{
    if(N<S)
    {
      MAN1=N;
    }
    if(S<N)
    {
      MAN1=S;
    }
    else{MAN1=N;}
}

if( (-5<error<5) && (pendiente<0) )
{
    if(C<B)
    {
      DEC3=C;
    }
    if(B<C)
    {
      DEC3=B;
    }
    else{DEC3=C;}
}

if( (-5<error<5) && (-5<pendiente<5) )                 //REGLAS LOGICA DIFUSA
{
    if(C<E)
    {
      MAN2=C;
    }
    if(E<C)
    {
      MAN2=E;
    }
    else{MAN2=C;}
}

if( (-5<error<5) && (pendiente>0) )
{
    if(C<S)
    {
      INC1=C;
    }
    if(S<C)
    {
      INC1=S;
    }
    else{INC1=C;}
}

if( (error>0) && (pendiente<0) )
{
    if(P<B)
    {
      MAN3=P;
    }
    if(B<P)
    {
      MAN3=B;
    }
    else{MAN3=P;}
}

if( (error>0) && (-5<pendiente<5) )
{
    if(P<E)
    {
      INC2=P;
    }
    if(E<P)
    {
      INC2=E;
    }
    else{INC2=P;}
}

if( (error>0) && (pendiente>0) )
{
    if(P<S)
    {
      INC3=P;
    }
    if(S<P)
    {
      INC3=S;
    }
    else{INC3=P;}
}
//...................................................................................

Pinc=sqrt((INC1*INC1)+(INC2*INC2)+(INC3*INC3));
Pdec=sqrt((DEC1*DEC1)+(DEC2*DEC2)+(DEC3*DEC3));      //CALCULO CENTRO DE MASA
Pman=sqrt((MAN1*MAN1)+(MAN2*MAN2)+(MAN3*MAN3));
//...................................................................................

fuzzy = ((Pdec*-10)+(Pman*0)+(Pinc*10))/(Pdec+Pman+Pinc);
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
  Serial.println("");    
}
