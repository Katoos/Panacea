int motion = 0;
// defines pins numbers
const int trig = 9;
const int echo = 10;
const int led = 4;

// defines variables
long duration;
int distance;
int safetyDistance;
void setup() {
  // put your setup code here, to run once:
pinMode(2, INPUT);
pinMode(8,OUTPUT);
pinMode(trig, OUTPUT); // Sets the trigPin as an Output
pinMode(echo, INPUT); // Sets the echoPin as an Input
pinMode(led, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop()
{
  // put your main code here, to run repeatedly:
motion = digitalRead(2);
if (motion == HIGH) {
  digitalWrite(8, HIGH);
  delay(5000);
}
else {
  digitalWrite(8, LOW);
}
// Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance > 20){
  digitalWrite(led, LOW);
}
if (safetyDistance > 10 && safetyDistance < 20)
{
  digitalWrite(led, HIGH);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
