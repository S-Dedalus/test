#include <SoftwareSerial.h>

char rawData0 = 0;
char rawData1 = 0;
char rawData2 = 0;
char rawData3 = 0;
SoftwareSerial mySerial(A2, A1); // RX, TX

    int SumaCal(char rawData1, char rawData2){
      return ((rawData2 << 8) + rawData1);
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
  }

   long one = long(SumaCal);
   Serial.println(one);
     delay(500);
}
