/* 
     Para desplegar numeros en un Display de 7 segmentos

   */

       //  para el boton
       int boton = 0;     // para leer el estado del boton
       int qa = 2; // pin donde esta el boton
       int numin = 0;     // el valor minimo que generara
       int numax = 11;     // el valor maximo-1 que generara
       
       //  para guardar el numero aleatorio
       int resultado;
    
       // Arreglo con los numeros    
       // valor de cada segmento ABCDEFGP    num.
      const byte numeros[12] = {B00000010, // 0
                                B10011110, // 1
                                B00100100, // 2
                                B00001100, // 3
                                B10011000, // 4
                                B01001000, // 5
                                B01000000, // 6
                                B00011110, // 7
                                B11111110, // 8
                                B11110110, // 9
                                B11111110,  // Punto Decimal
                                B11111110  // Blanco
                             };
                             
      // Arreglo con los pines del Arduino correspondientes a cada segmento del display
                                 //DP  G F  E D C B A 
         const int pinSegmento[] = {1,11,10,9,8,7,6,5};
                             
      void setup() {
          //  pone el pinboton de salida
          pinMode(qa, INPUT);
          // Para definir los pines como de salida
          for(int i=0; i < 12; i++){  
               pinMode(pinSegmento[i], OUTPUT);
          // pone el punto para indicar que esta listo
          pintaDigito(10);         
          }
          //  para inicializar el generador de numeros aleatorios
          randomSeed(analogRead(0));
      }                       
      
      void loop() {
           // lee el estado del boton
           boton = digitalRead(qa);

           // checa si el boton fue presionado
            if (boton == HIGH) { 
               pintaDigito(23);  //  pone el display en negro 
               delay(100); 
               resultado = numin;  // genera un numero aleatorio entre 0 y 9
               pintaDigito(resultado);  // pinta el numero generado
               delay(500);
            }
      }
     
      void pintaDigito(int numero) {
      
           boolean prendido;
           for(int segmento = 0; segmento < 8; segmento++) {
                 prendido = bitRead(numeros[numero], segmento);
                 digitalWrite( pinSegmento[segmento], prendido);
            }
      }

