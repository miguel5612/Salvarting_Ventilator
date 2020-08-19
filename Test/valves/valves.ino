#define valveInsp 8
#define valveExp 9

void setup()
{
    pinMode(valveInsp, OUTPUT);
    pinMode(valveExp, OUTPUT);
    digitalWrite(valveInsp, LOW);
    digitalWrite(valveExp, LOW);
}

void loop()
{
    digitalWrite(valveInsp, LOW);
    digitalWrite(valveExp, HIGH);
    
    delay(1000);

    digitalWrite(valveInsp, HIGH);
    digitalWrite(valveExp, LOW);

    delay(1000);
}