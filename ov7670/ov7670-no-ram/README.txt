This is a version of code that sends data to the PC.
Unlike previous code this requires no external ram or fifo.
It just sends the data as it receives it.
The transfer rate is 1 mbps or 128kbytes per second
Connections
Order Arduino ov7670
A5->SIOC
A4<->SIOD
Note what I have just described (above) are I2C connections you will need pullup resistors to 3.3v for both SIOC and SIOD.
You must not connect the resistors to 5v.
I have found that certain resistor values do not work such as 1K and 2.2K but found 4.7K and 10K to work.
11-> (convert 5v to 3.3v) XCLK
A0<-0
A1<-1
A2<-2
A3<-3
4<-4
5<-5
6<-6
7<-7
3<-VSYNC
2<-PCLK
This is a version of code that sends data to the PC.
Unlike previous code this requires no external ram or fifo.
It just sends the data as it receives it.
The transfer rate is 1 mbps or 128kbytes per second
Connections
Order Arduino ov7670
A5->SIOC
A4<->SIOD
Note what I have just described (above) are I2C connections you will need pullup resistors to 3.3v for both SIOC and SIOD.
You must not connect the resistors to 5v.
I have found that certain resistor values do not work such as 1K and 2.2K but found 4.7K and 10K to work.
11-> (convert 5v to 3.3v) XCLK
A0<-0
A1<-1
A2<-2
A3<-3
4<-4
5<-5
6<-6
7<-7
3<-VSYNC
2<-PCLK