const int trigPin = 2;
const int echoPin = 3;
const int motorPin = 4;
const int ledPin = 5;
const int musicPin = 9;

int hand = 1;
int triginterval = 1; // interval in milliseconds at which trigPin turns on

unsigned long previousMillis = 0; // will store last time LED was updated
int trigState = LOW;              //state of trigPin

long duration;
int d, distance = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(ledPin, OUTPUT);   // Sets the ledPin as an Output
  pinMode(motorPin, OUTPUT); // Sets the buzzPin as an Output
  pinMode(musicPin, OUTPUT); // Sets the buzzPin as an Output

  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  digitalWrite(ledPin, LOW);
  digitalWrite(musicPin, LOW); // Sets the buzzPin as an Output

  digitalWrite(motorPin, LOW);
}

void loop()
{

distance = dis();
  if (distance < 50)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
    digitalWrite(musicPin, HIGH);
    delay(1500);
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    digitalWrite(musicPin, LOW);
    while (distance < 80)
    {
      digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    digitalWrite(musicPin, LOW);
      distance = dis();
    }
}
}
int dis()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  distance = 0;
  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  Serial.println(distance);
  return distance;
}
