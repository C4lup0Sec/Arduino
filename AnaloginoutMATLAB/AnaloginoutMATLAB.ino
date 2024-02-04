void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println('a');
char a = 'b';
while (a !='a');
  {
    a=Serial.read();  
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
/*
 * .m codigo
function [s,flag] = setupSerial(comPort)
flag=1;
s=serial(comPort);
set(s,'DataBits',8);
set(s,'StopBits',1);
set(s,'Parity','none');
fopen(s);
a='b';
while (a=='a')
  a=fread(s,1,'uchar');
end
if (a=='a')
  disp('serial read');
end
fprintf(s,'%c','a');
mbox=msbox('Serial Communication setup.'); uiwait(mbox);
fscanf(s,'%u')
end
*/
//en consola 
//comPort = '/dev/ttyACMO';
//[s,flag] = setupSerial(comPort);
