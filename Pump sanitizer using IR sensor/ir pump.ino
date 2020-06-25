
const int motorPin = 13;
const int IRsensor = 2;

void setup()
{
    Serial.begin(9600);
    
    pinMode(motorPin, OUTPUT); 
    pinMode(IRsensor, INPUT); 
    digitalWrite(motorPin, LOW);
}

void loop()
{

    if (digitalRead(2) == HIGH)
    {
        digitalWrite(motorPin, HIGH);
        delay(1500);
        digitalWrite(motorPin, LOW);
        while (digitalRead(2) == HIGH
)
        {

            digitalWrite(motorPin, LOW);
        }
    }
}
