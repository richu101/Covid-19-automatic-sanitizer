
const int trigPin = 10;
const int echoPin = 9;// defines variables
long duration;
int distance;
int pos = 0;
int dis();
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(13,OUTPUT);
}
void loop() {

distance = dis();
if(distance<50)
{
  digitalWrite(13,HIGH);
  delay(1500);
  digitalWrite(13,LOW);
  while(distance>100)
{
digitalWrite(13,LOW);
distance = dis();
}
}
}
int dis()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
return distance;
}

