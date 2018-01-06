unsigned long echo = 0;
int ultraSoundSignal = A1; // Ultrasound signal pin, trigger
int ultraSoundSignalIN = A2; // Ultrasound signal pin, echo

unsigned long ultrasoundValue = 0;

void setup()
{
Serial.begin(9600);
pinMode(ultraSoundSignal,OUTPUT);
pinMode(ultraSoundSignalIN,INPUT_PULLUP);

}





void loop()
{
int one;
one = Serial.read(); 
Serial.print(one);

}
