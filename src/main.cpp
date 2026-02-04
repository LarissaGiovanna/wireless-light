/*
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp-now-two-way-communication-esp32/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/

//RECEPTOR MAIN

#include <esp_now.h>
#include <WiFi.h>
#include <Servo.h>

// Variable to store if sending data was successful
String success;

//Must match the receiver structure
typedef struct struct_message {
    int valor;
} struct_message;

// Create a struct_message to hold incoming sensor readings
struct_message estadoBotaoRecebido; //apertado ou nao 

esp_now_peer_info_t peerInfo;

//criação servo
Servo servo;

//contador para controlar estado do interruptor
int estadoInterruptor = 0; // 0 = apagado, 1 = aceso

void alternarInterruptor(){
    if (estadoInterruptor == 0){ 
        // Acender
        Serial.println("Acendendo luz...");
        servo.write(0); 
        delay(100);
        servo.write(180);
        delay(105);
        servo.write(90); // parado
        estadoInterruptor = 1;
    }
    else { 
        // Apagar
        Serial.println("Apagando luz...");
        servo.write(180); 
        delay(100);
        servo.write(0);
        delay(105);
        servo.write(90); // parado
        estadoInterruptor = 0;
    }
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&estadoBotaoRecebido, incomingData, sizeof(estadoBotaoRecebido));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Valor recebido: ");
  Serial.println(estadoBotaoRecebido.valor);

  // Se recebeu comando de botão pressionado, alternar
  if (estadoBotaoRecebido.valor == 1){
    alternarInterruptor();
  }
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  servo.attach(26); // Attach the servo to pin 26 (adjust the pin number as needed)
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}
 
void loop() {
}
