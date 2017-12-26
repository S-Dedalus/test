unsigned long echo = 0;
int ultraSoundSignal = A1; // Ultrasound signal pin, trigger
int ultraSoundSignalIN = A2; // Ultrasound signal pin, echo

unsigned long ultrasoundValue = 0;

void setup()
{
Serial.begin(9600);
pinMode(ultraSoundSignal,OUTPUT);
pinMode(ultraSoundSignalIN,INPUT);

}

unsigned long ping(){
pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
digitalWrite(ultraSoundSignal, LOW); // Send low pulse
delayMicroseconds(2); // Wait for 2 microseconds
digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
delayMicroseconds(15); // Wait for 15 microseconds
digitalWrite(ultraSoundSignal, LOW); // Holdoff
pinMode(ultraSoundSignalIN, INPUT); // Switch signalpin to input
digitalWrite(ultraSoundSignalIN, HIGH); // Turn on pullup resistor
// please note that pulseIn has a 1sec timeout, which may
// not be desirable. Depending on your sensor specs, you
// can likely bound the time like this — marcmerlin
// echo = pulseIn(ultraSoundSignal, HIGH, 38000)
echo = pulseIn(ultraSoundSignalIN, HIGH); //Listen for echo
Serial.println(echo);
ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
return ultrasoundValue;

}

void loop()
{
int x = 0;
x = ping();
//Serial.println(x);
delay(250); //delay 1/4 seconds.

}
