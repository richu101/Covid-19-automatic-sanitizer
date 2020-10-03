
const int motorPin = 13;//declare output pin
const int IRsensor = 2;//declare input pin

void setup()
{
    Serial.begin(9600);
    
    pinMode(motorPin, OUTPUT); 
    pinMode(IRsensor, INPUT); 
    digitalWrite(motorPin, LOW);//set output as low while starting
}

void loop()
{

    if (digitalRead(2) == HIGH)
    {
        delay(200);//delay before trigger
        digitalWrite(motorPin, HIGH);
        delay(1500);//triggerring time
        digitalWrite(motorPin, LOW);
        while (digitalRead(2) == HIGH
)
        {

            digitalWrite(motorPin, LOW);//keep low at else condition
        }
    }
}
