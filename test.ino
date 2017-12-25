#include <SoftwareSerial.h>

byte rawData0 = 0;
byte rawData1 = 0;
byte rawData2 = 0;
byte rawData3 = 0;
SoftwareSerial mySerial(A2, A1); // RX, TX

    int SumaCal(byte rawData0, byte rawData1, byte rawData2){
      return int(SumaCal);
    }

void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  
     Serial.println("Przeszetem setup");
}

void loop() {
  
  if (mySerial.available()> 0) {
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
     long one = long(SumaCal);
     Serial.println(one, HEX);
     delay(500);
  }
}
