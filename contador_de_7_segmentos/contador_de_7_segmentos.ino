/*
Contador de 7-segmentos
POR Loperz Hates
*/

const int a0 = 22;
const int b0 = 23;
const int c0 = 24;
const int d0 = 25;
const int e0 = 26;
const int f0 = 27;
const int g0 = 28;

int QA0 = 2;   // pushbutton connected to digital pin 7
int QB0 = 3;
int QC0 = 4;
int QD0 = 5;
int val0 = 0;

const int a1 = 29;
const int b1 = 30;
const int c1 = 31;
const int d1 = 32;
const int e1 = 33;
const int f1 = 34;
const int g1 = 35;

int QA1 = 6;   // pushbutton connected to digital pin 7
int QB1 = 7;
int QC1 = 8;
int QD1 = 9;
int val1 = 0;

// The setup() method runs once, when the sketch starts

void setup() { 
// initialize the digital pin as an output:
pinMode(a0, OUTPUT);
pinMode(b0, OUTPUT);
pinMode(c0, OUTPUT);
pinMode(d0, OUTPUT);
pinMode(e0, OUTPUT);
pinMode(f0, OUTPUT);
pinMode(g0, OUTPUT);

pinMode(a1, OUTPUT);
pinMode(b1, OUTPUT);
pinMode(c1, OUTPUT);
pinMode(d1, OUTPUT);
pinMode(e1, OUTPUT);
pinMode(f1, OUTPUT);
pinMode(g1, OUTPUT);

}
void Representar(int valor){
switch(valor){
case 0:

digitalWrite(a0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(d0, LOW);
digitalWrite(e0, LOW);
digitalWrite(f0, LOW);
digitalWrite(g0, HIGH);
break;

case 1:
digitalWrite(a0, HIGH);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(d0, HIGH);
digitalWrite(e0, HIGH);
digitalWrite(f0, HIGH);
digitalWrite(g0, HIGH);
break;

case 2:
digitalWrite(a0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, HIGH);
digitalWrite(d0, LOW);
digitalWrite(e0, LOW);
digitalWrite(f0, HIGH);
digitalWrite(g0, LOW);
break;

case 3:
digitalWrite(a0, LOW);
digitalWrite(e0, HIGH);
digitalWrite(f0, HIGH);
digitalWrite(d0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(g0, LOW);
break;

case 4:
digitalWrite(a0, HIGH);
digitalWrite(b0, LOW);
digitalWrite(e0, HIGH);
digitalWrite(g0, LOW);
digitalWrite(c0, LOW);
digitalWrite(f0, LOW);
digitalWrite(d0, HIGH);
break;

case 5:
digitalWrite(a0, LOW);
digitalWrite(b0, HIGH);
digitalWrite(c0, LOW);
digitalWrite(d0, LOW);
digitalWrite(e0, HIGH);
digitalWrite(f0, LOW);
digitalWrite(g0, LOW);
break;

case 6:
digitalWrite(a0, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(c0, LOW);
digitalWrite(d0, LOW);
digitalWrite(e0, LOW);
digitalWrite(f0, LOW);
digitalWrite(g0, LOW);
break;

case 7:
digitalWrite(a0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(d0, HIGH);
digitalWrite(e0, HIGH);
digitalWrite(f0, HIGH);
digitalWrite(g0, HIGH);
break;

case 8:
digitalWrite(a0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(d0, LOW);
digitalWrite(e0, LOW);
digitalWrite(f0, LOW);
digitalWrite(g0, LOW);
break;

case 9:
digitalWrite(a0, LOW);
digitalWrite(b0, LOW);
digitalWrite(c0, LOW);
digitalWrite(g0, LOW);
digitalWrite(e0, HIGH);
digitalWrite(f0, LOW);
digitalWrite(d0, HIGH);
break;

}
}
void LimpiarDisplay(){
digitalWrite(a0, HIGH);
digitalWrite(b0, HIGH);
digitalWrite(c0, HIGH);
digitalWrite(d0, HIGH);
digitalWrite(e0, HIGH);
digitalWrite(f0, HIGH);
digitalWrite(g0, HIGH);
}

void LimpiarDisplay1(){
digitalWrite(a1, HIGH);
digitalWrite(b1, HIGH);
digitalWrite(c1, HIGH);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
}

void loop(){
for(int i=0;i<=9;i++)
{ LimpiarDisplay(); 
Representar(i); delay(500); }
} 
