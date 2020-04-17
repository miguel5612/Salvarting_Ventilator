#define pin_Stepper_DIR        6
#define pin_Stepper_Step       7
#define pin_Stepper_Disable    5

#define pin_SDA               A4
#define pin_SCL               A5

#define SERIAL_BAUD 115200  // Serial port communication speed
#define motorMaxAcceleration    20000

#include <AccelStepper.h>  // Stepper / servo library with step pulse / dir interface
AccelStepper stepper(1, pin_Stepper_Step, pin_Stepper_DIR);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BAUD);
  pinMode(pin_Stepper_DIR, OUTPUT);
  digitalWrite(pin_Stepper_DIR, LOW);     // active (inverted)
  pinMode(pin_Stepper_Step, OUTPUT);
  digitalWrite(pin_Stepper_Step, LOW);    // active (inverted)

  stepper.setMaxSpeed(motorMaxAcceleration);
  Serial.println("Init started");
}

void loop() {
  // put your main code here, to run repeatedly:
  //stepper.setCurrentPosition(0);
  Serial.println("Direccion 1");
  digitalWrite(pin_Stepper_DIR, HIGH);     // active (inverted)
  // Reset the position to 0:
  //stepper.setCurrentPosition(0);
  while (stepper.currentPosition() < 1500)  {
    stepper.setSpeed(1000);
    stepper.runSpeed();
    Serial.print("Dir 1 - ");
    Serial.println(stepper.currentPosition());
  }
  while (stepper.currentPosition() < 1800)  {
    stepper.setSpeed(800);
    stepper.runSpeed();
    Serial.print("Dir 1 - ");
    Serial.println(stepper.currentPosition());
  }
  while (stepper.currentPosition() < 2000)  {
    stepper.setSpeed(200);
    stepper.runSpeed();
    Serial.print("Dir 1 - ");
    Serial.println(stepper.currentPosition());
  }
  while (stepper.currentPosition() < 2300)  {
    stepper.setSpeed(100);
    stepper.runSpeed();
    Serial.print("Dir 1 - ");
    Serial.println(stepper.currentPosition());
  }
  delay(1000);
  Serial.println("Direccion 2");
  digitalWrite(pin_Stepper_DIR, LOW);     // active (inverted)
  // Run the motor backwards at 600 steps/second until the motor reaches -200 steps (1 revolution):
  while (stepper.currentPosition() > 400)   {
    stepper.setSpeed(-800);
    stepper.runSpeed();
    Serial.print("Dir 2 - ");
    Serial.println(stepper.currentPosition());
  }
  while (stepper.currentPosition() > 0)   {
    stepper.setSpeed(-600);
    stepper.runSpeed();
    Serial.print("Dir 2 - ");
    Serial.println(stepper.currentPosition());
  }
  delay(1000);
}
