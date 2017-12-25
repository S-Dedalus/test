#include <SoftwareSerial.h>

int rawData0 = 0;
int rawData1 = 0;
int rawData2 = 0;
int rawData3 = 0;
SoftwareSerial mySerial(A2, A1); // RX, TX

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
     Serial.println("Przeszetem setup");
}

void loop() {
  
  if (mySerial.available()> 0) {
    Serial.println("mySerial available");
    rawData0 = mySerial.read();
    Serial.print(rawData0, HEX);
    Serial.print("|");
    rawData1 = mySerial.read();
    Serial.print(rawData1, HEX);
    Serial.print("|");
    rawData2 = mySerial.read();
    Serial.print(rawData2, HEX);
    Serial.print("|");
    rawData3 = mySerial.read();
    Serial.print(rawData3, HEX);
    Serial.println("|");
  }
  else {
    Serial.println("Nie zainicjowalem portu mySerial");
  }
    delay(500);
}
