// #include <Arduino.h>

// const int BUTTON_PIN = 10;
// const int LED_PIN = LED_BUILTIN;

// void setup(){
//   Serial.begin(115200);
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   digitalWrite(LED_PIN, LOW);
//   Serial.println("Sistema iniciado");
// }

// void loop(){
//   if (digitalRead(BUTTON_PIN) == LOW) {
//     delay(20);  // debounce
//     if (digitalRead(BUTTON_PIN) == LOW) {
//       digitalWrite(LED_PIN, HIGH);
//       Serial.println("Botão pressionado - LED ON");
//       while(digitalRead(BUTTON_PIN) == LOW) {
//         delay(10);
//       }
//       delay(20);  // debounce ao soltar
//     }
//   } else {
//     digitalWrite(LED_PIN, LOW);
//   }
// }