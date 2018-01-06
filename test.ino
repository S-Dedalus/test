#include <SoftwareSerial.h>

byte rawData0 = 0;
uint16_t rawData1 = 0;
byte rawData2 = 0;
byte rawData3 = 0;
uint16_t dist = 0;
SoftwareSerial mySerial(A2, A1); // RX, TX

    int SumaCal(byte rawData0, byte rawData1, byte rawData2){
      return long(SumaCal);
    }

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
     
}

void loop() {
  
  if (mySerial.available()> 0) {
    rawData0 = mySerial.read();
//    Serial.print(rawData0, HEX);
//    Serial.print("|");
    rawData1 = mySerial.read();
//    Serial.print(rawData1, HEX);
//    Serial.print("|");
    rawData2 = mySerial.read();
//    Serial.print(rawData2, HEX);
//    Serial.print("|");
    rawData3 = mySerial.read();
//    Serial.print(rawData3, HEX);
//    Serial.println("|");
     long one = long(SumaCal);
//     Serial.println(one, HEX);
     rawData1 = rawData1 << 8;
     dist = (rawData1 + rawData2);
//     Serial.print(rawData1, BIN);
//     Serial.print("|");
//     Serial.println(rawData2, BIN);
//     Serial.println(dist, BIN);
     Serial.print(dist/10);
     Serial.println(" cm");
     
     delay(500);
  }
}

