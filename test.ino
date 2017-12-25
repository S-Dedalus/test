#include <SoftwareSerial.h>

SoftwareSerial mySerial(A2, A1); // RX, TX

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
}

void loop() {
  String rawData;
  if (mySerial.available()) {
    rawData = Serial.readStringUntil(0xFF);
  }
  Serial.println(rawData);
  delay(500);
}
