#define trigPin A1
#define echoPin A2
#define ledRedPin 11
#define ledGreenPin 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // comparison for led ON/OFF
    digitalWrite(ledRedPin,HIGH); // when Red LED turns ON, Green LED turns off
  digitalWrite(ledGreenPin,LOW);
}
  else {
    digitalWrite(ledRedPin,LOW);
    digitalWrite(ledGreenPin,HIGH);
  }
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
