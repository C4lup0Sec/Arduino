 /* 
     En este proyecto vamos a desplegar numeros en un Display de 7 segmentos
       
   */

   // Arreglo con los numeros    ABCDEFGP
      const byte numeros[11] = {B11111100, // 0
                                B01100000, // 1
                                B11011010, // 2
                                B11110010, // 3
                                B01100110, // 4
                                B10110110, // 5
                                B00111110, // 6
                                B11100000, // 7
                                B11111110, // 8
                                B11100110, // 9
                                B00000001  // PD
                             };
                             
      // Un arreglo con los pines del display
                                 //DP G F E D C B A 
         const int pinSegmento[] = {9,4,5,2,3,8,7,6};
                             
      void setup() {
         // Para definir los pines de salida 
          for(int i=0; i < 8; i++){  
               pinMode(pinSegmento[i], OUTPUT);
          }
        Serial.begin(9600);  
      }                       
      
      void loop() {
        for (int i=0; i <= 10; i++) {
            pintaDigito(i);
            delay(1000);
        }
        for (int i=10; i > 0; i--) {
            pintaDigito(i);
            delay(1000);
        }
      }
      
      void pintaDigito(int numero) {
      
           boolean prendido;
           for(int segmento = 0; segmento < 8; segmento++) {
                 prendido = bitRead(numeros[numero], segmento);
                 digitalWrite( pinSegmento[segmento], prendido);
            }
      }
