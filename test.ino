#include <SoftwareSerial.h>

SoftwareSerial mySerial(A2, A1); // RX, TX

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
}

void loop() {
  String rawData;
  if (mySerial.available()> 0) {
    rawData = mySerial.read();
    Serial.println(rawData);
  }
  else {
    Serial.println("Nie zainicjowalem portu mySerial");
  }
    delay(500);
}
