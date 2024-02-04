#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h> 
/*
 * VCC VCC
 * GND GND
 * SCL A5
 * SDA A4
 */
Servo servo1;
Servo servo2;

MPU6050 accelgyro; // sensor con acelerometro y giroscopio

int16_t ax, ay, az; 
int16_t gx, gy, gz;

//Usado para calcular el angulo - Variantes del acelerometro
double accXangle; 
double accYangle; 
double accZangle;
//Usado para calcular el angulo - Variantes del giroscopio
double gyroXangle = 180;
double gyroYangle = 180;
double gyroZangle = 180;

uint32_t timer;

void setup()
{ 
  Wire.begin();

  // Iniciando la comunicacion serial
  // funciona en 8MHz o en 16MHz
  Serial.begin(38400);

  // Iniciando dispositivos
  Serial.println("Iniciando cominicacion I2C...");
  
  accelgyro.initialize();

  // Testando la conexion con MPU6050
  Serial.println("Testando la conexion con MPU6050...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 conectada con exito" : "Fallo en la conexion con el MPU6050");
  
  servo1.attach(11);
  servo2.attach(10);
  
  timer = micros();
}

void loop() {
  // haciendo la lectura de conexion con el MPU6050
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calcular los angulos con base los sensores del acelerometro
  accXangle = (atan2(ax,az) + PI) * RAD_TO_DEG;
  accYangle = (atan2(ay,az) + PI) * RAD_TO_DEG;
  accZangle = (atan2(ax,ay) + PI) * RAD_TO_DEG;  

  double gyroXrate = ((double)gx / 131.0);
  double gyroYrate = -((double)gy / 131.0);
  double gyroZrate = -((double)gz / 131.0);
  
  //###################### Calcular del angulo de giro sin colocar filtro ######################### 
  gyroXangle += gyroXrate*((double)(micros()-timer)/1000000); 
  gyroYangle += gyroYrate*((double)(micros()-timer)/1000000);
  gyroZangle += gyroZrate*((double)(micros()-timer)/1000000);
 
  servo1.write(gyroYangle);
  servo2.write(gyroXangle);
  
  timer = micros();
  //tasa a mostrar máxima del acelerometro es de 1KHz
  delay(1); 

  //Tabla Separada para los valores accel/gyro x/y/z values
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);
  
  //Angulo Giroscopio x/y/z
  Serial.print(gyroXangle); Serial.print("\t");
  Serial.print(gyroYangle); Serial.print("\t"); 
  Serial.print(gyroZangle); Serial.print("\t");
  Serial.print("\n");
}
