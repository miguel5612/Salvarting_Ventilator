/*Example sketch to control a stepper motor with A4988/DRV8825 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */
// Define stepper motor connections and steps per revolution:
#define dirPin 6
#define stepPin 7
#define stepsPerRevolution 200
void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop() {
  giroCompletoContinuo();
  //medioGiro();
}

void giroCompletoContinuo()
{
  digitalWrite(dirPin, LOW);
  for(int i=0; i<=50; i++)
  {
    analogWrite(stepPin, 5);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);      
  }
}
void medioGiro()
{
  
    digitalWrite(dirPin, LOW);
    for(int i=0; i<=50; i++)
    {
      analogWrite(stepPin, 5);
      delay(10);
      digitalWrite(stepPin, LOW);
      delay(10);      
    }
    delay(2000);
    digitalWrite(dirPin, HIGH);
    for(int i=0; i<=50; i++)
    {
      analogWrite(stepPin, 5);
      delay(10);
      digitalWrite(stepPin, LOW);
      delay(10);      
    }
    delay(1500);
}
