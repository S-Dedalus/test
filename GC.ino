/**
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define GeigerCounter 4             // geiger counter pin
#define ledPin 2

const float factor = 0.006666;      // define constans factor CPM to uS/h
float uSperH;                           // dose of radiation in uS/h
int counts = 0; 
unsigned long perv = 0;

ESP8266WiFiMulti WiFiMulti; 

void zapytanie (float uSperH) {
    if ((WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    Serial.print("[HTTP] begin...\n");
    String domoticz = "http://192.168.1.55:8080/json.htm?type=command&param=udevice&idx=37&nvalue=0&svalue=";
    String quote = (domoticz + String(uSperH));
    if (http.begin(client, quote)) {  // HTTP
      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }
}


 void licz () {
  unsigned long now = millis();
  unsigned long *pervWsk = &perv;
  int *countsWsk = &counts;
  if (now - *pervWsk <= 60000UL) {
    if (digitalRead(GeigerCounter) == LOW){
      ++*countsWsk;
      Serial.print("*countsWsk=");
      Serial.println(*countsWsk);
      digitalWrite(ledPin, LOW); 
    }
    else {
      digitalWrite(ledPin, HIGH); 
    }
  }
  if (now - *pervWsk > 60000UL) {
    *pervWsk = now;
    uSperH = *countsWsk * factor;
    Serial.print("uS/h");
    Serial.println(uSperH);
    zapytanie(uSperH);
    uSperH = 0;
    *countsWsk = 0;
  }
 }
void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  pinMode(GeigerCounter, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); 
  Serial.println();
  Serial.println();
  Serial.println();
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

    WiFi.begin("*************", "****************");

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}
void loop() {
licz();
 }
