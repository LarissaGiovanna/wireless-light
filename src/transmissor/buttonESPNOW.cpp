// /*
//   Rui Santos & Sara Santos - Random Nerd Tutorials
//   Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
//   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
//   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// */
// #include <esp_now.h>
// #include <WiFi.h>
// #include <Arduino.h>

// // REPLACE WITH YOUR RECEIVER MAC Address
// //enviar para main
// uint8_t broadcastAddress[] = {0x14, 0x33, 0x5C, 0x04, 0x00, 0xF8};

// // Structure example to send data
// // Must match the receiver structure
// typedef struct struct_message
// {
//     int valor;
// } struct_message;

// // Create a struct_message called myData
// struct_message estadoBotao;

// esp_now_peer_info_t peerInfo;

// // callback when data is sent
// void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
// {
//     Serial.print("\r\nLast Packet Send Status:\t");
//     Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
// }

// void setup()
// {
//     // Init Serial Monitor
//     Serial.begin(115200);

//     // Set device as a Wi-Fi Station
//     WiFi.mode(WIFI_STA);

//     // Init ESP-NOW
//     if (esp_now_init() != ESP_OK)
//     {
//         Serial.println("Error initializing ESP-NOW");
//         return;
//     }

//     // Once ESPNow is successfully Init, we will register for Send CB to
//     // get the status of Trasnmitted packet
//     esp_now_register_send_cb(esp_now_send_cb_t(OnDataSent));

//     // Register peer
//     memcpy(peerInfo.peer_addr, broadcastAddress, 6);
//     peerInfo.channel = 0;
//     peerInfo.encrypt = false;

//     // Add peer
//     if (esp_now_add_peer(&peerInfo) != ESP_OK)
//     {
//         Serial.println("Failed to add peer");
//         return;
//     }

//     // configurando botao e led para teste
//     pinMode(10, INPUT_PULLUP);
//     pinMode(LED_BUILTIN, OUTPUT);
// }

// // Variável para controle de debounce
// bool ultimoEstadoBotao = HIGH;

// void loop()
// {
//     // Ler estado atual do botão
//     bool estadoAtual = digitalRead(10);
    
//     // Detectar borda de descida (botão foi pressionado)
//     if (estadoAtual == LOW && ultimoEstadoBotao == HIGH)
//     {
//         estadoBotao.valor = 1;
       
//         // Send message via ESP-NOW
//         esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&estadoBotao, sizeof(estadoBotao));

//         if (result == ESP_OK)
//         {
//             Serial.println("Sent with success");
//         }
//         else
//         {
//             Serial.println("Error sending the data");
//         }

//         digitalWrite(LED_BUILTIN, HIGH);
        
//         // Debounce: aguardar botão ser solto
//         delay(50);
//     }
//     else if (estadoAtual == HIGH)
//     {
//         digitalWrite(LED_BUILTIN, LOW);
//     }
    
//     // Atualizar último estado
//     ultimoEstadoBotao = estadoAtual;
    
//     delay(10); // Pequeno delay para estabilidade
// }