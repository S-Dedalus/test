#include <SoftwareSerial.h>

int rawData = 0;
SoftwareSerial mySerial(A2, A1); // RX, TX

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
     Serial.println("Przeszetem setup");
}

void loop() {
  
  if (mySerial.available()> 0) {
    Serial.println("mySerial available");
    rawData = mySerial.read();
    Serial.println("SKonczylem odbierac mySerial");
    Serial.println(rawData, HEX);
  }
  else {
    Serial.println("Nie zainicjowalem portu mySerial");
  }
    delay(500);
}
