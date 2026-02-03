/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(115200);
  myservo.attach(26);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  int num = Serial.read(); //substituir pela leitura do esp now vinda da outra placa
  if (num == 1){
    myservo.write(0); 
    delay(100);
    myservo.write(180);
    delay(105);
    myservo.write(90); //parado
    delay(1000);
  }else if (num == 2){
    myservo.write(180); 
    delay(100);
    myservo.write(0);
    delay(105);
    myservo.write(90); //parado
    delay(1000);
  }
}
