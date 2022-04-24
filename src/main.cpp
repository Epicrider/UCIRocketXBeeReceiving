#include <Arduino.h>
#include <SoftwareSerial.h>

char incomingByte = '0';
// SoftwareSerial XBee(0, 1);

void setup() {
  // Serial Ports for Receiving
  Serial1.begin(11520);
  Serial.begin(11520);
}

void loop() {
  // Wait until package arrives
  while(Serial1.available()) {
//    incomingByte = Serial1.read();
//    Serial.print("I recieved: ");
//    Serial.println(incomingByte);
      incomingByte = Serial1.read();
      Serial.print((char)incomingByte);
  }
  while(Serial.available() != 0) {
    Serial.print(Serial.read());
  }
  
}