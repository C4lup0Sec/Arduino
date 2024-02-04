/*¡Por supuesto! Aquí tienes un ejemplo de cómo podrías crear un código en Arduino para 
 controlar una tira LED RGB a través de WiFi o Bluetooth utilizando una placa ESP32-CAM 
 y también para medir la temperatura y humedad con un sensor DHT11 y mostrar los valores 
 en un servidor web. 

Este código utiliza la plataforma Arduino IDE y combina varias bibliotecas para lograr las 
funcionalidades deseadas. Asegúrate de tener instaladas las bibliotecas necesarias antes de 
cargar el código en la placa.
*/


#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>

// Configuración WiFi
const char* ssid = "Tu_SSID";
const char* password = "Tu_Contraseña";

// Configuración del servidor web
AsyncWebServer server(80);

// Configuración del LED RGB
#define LED_PIN 2 // Pin del LED RGB
#define NUM_PIXELS 1 // Número de LEDs en la tira
Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Configuración del sensor DHT11
#define DHT_PIN 4
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  // Inicialización de WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  // Configuración del servidor web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    String html = "<html><body>";
    html += "<h1>ESP32-CAM Control</h1>";
    html += "<p>Temperatura: " + String(temperature) + " °C</p>";
    html += "<p>Humedad: " + String(humidity) + " %</p>";
    html += "<p><a href=\"/led/on\">Encender LED</a> | <a href=\"/led/off\">Apagar LED</a></p>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/led/on", HTTP_GET, [](AsyncWebServerRequest *request){
    strip.setPixelColor(0, strip.Color(255, 0, 0)); // Rojo
    strip.show();
    request->send(200);
  });

  server.on("/led/off", HTTP_GET, [](AsyncWebServerRequest *request){
    strip.setPixelColor(0, strip.Color(0, 0, 0)); // Apagar
    strip.show();
    request->send(200);
  });

  // Inicialización del LED RGB
  strip.begin();
  strip.show();

  // Inicialización del sensor DHT11
  dht.begin();
}

void loop() {
  // No se necesita ningún código en el bucle loop
}
/*
Recuerda modificar "Tu_SSID" y "Tu_Contraseña" con los detalles de tu red WiFi. 
También, asegúrate de haber instalado las bibliotecas "ESPAsyncWebServer", "Adafruit NeoPixel" 
y "DHT sensor library" a través del administrador de bibliotecas en el Arduino IDE.

Este código crea un servidor web en el ESP32-CAM que muestra la temperatura y la humedad 
del sensor DHT11, y permite encender o apagar el LED RGB a través de enlaces en la página web.

Ten en cuenta que este es un ejemplo básico y deberás ajustarlo y expandirlo según tus necesidades.

*/
