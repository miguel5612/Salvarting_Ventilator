/*
 * 
// Pins for the RAMPS board
const int X_STEP_PIN         = 54;
const int X_DIR_PIN          = 55;
const int X_ENABLE_PIN       = 38;  // Active LOW

const int Y_STEP_PIN         = 60;
const int Y_DIR_PIN          = 61;
const int Y_ENABLE_PIN       = 56;  // Active LOW

const int Z_STEP_PIN         = 46;
const int Z_DIR_PIN          = 48;
const int Z_ENABLE_PIN       = 62;  // Active LOW
 */

#define pin_Stepper_DIR        55
#define pin_Stepper_Step       54
#define pin_Stepper_Disable    38

#define pin_SDA               A4
#define pin_SCL               A5
#define minZendstop           19

#define SERIAL_BAUD 115200  // Serial port communication speed
#define motorMaxAcceleration    20000
#define electroVExpiracion    8
#define electroVInspiracion   9

#include <AccelStepper.h>  // Stepper / servo library with step pulse / dir interface
AccelStepper stepper(1, pin_Stepper_Step, pin_Stepper_DIR);

double relacionInspiracionExpiracion = 3.2;
double motorSpeed = 8000;
double maxRecorridoMotor = 3000;
float tiempoInspiracionExpiracion = 1;
int cantidadCiclos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BAUD);
  pinMode(electroVExpiracion, OUTPUT);
  pinMode(electroVInspiracion, OUTPUT);
  pinMode(minZendstop, INPUT_PULLUP);
  
  pinMode(pin_Stepper_DIR, OUTPUT);
  digitalWrite(pin_Stepper_DIR, LOW);     // active (inverted)
  
  pinMode(pin_Stepper_Step, OUTPUT);
  digitalWrite(pin_Stepper_Step, LOW);    // active (inverted)
  
  pinMode(pin_Stepper_Disable, OUTPUT);
  digitalWrite(pin_Stepper_Disable, LOW);
  
  stepper.setMaxSpeed(motorMaxAcceleration);
  Serial.println("Init started");
  
  digitalWrite(pin_Stepper_DIR, HIGH);     // active (inverted)
  while(digitalRead(minZendstop))
  {
      stepper.setSpeed(-800);
      stepper.runSpeed();
      Serial.println("Buscando origen...");
  }

  delay(150);

  alejarseFinalCarrera();
  
  delay(150);
}

void loop() {
  digitalWrite(electroVExpiracion, LOW);
  digitalWrite(electroVInspiracion, HIGH);
  digitalWrite(pin_Stepper_DIR, LOW);     // active (inverted)
  Serial.println("Inspiracion");  
  //Serial.println(stepper.currentPosition());
  while (stepper.currentPosition() < (maxRecorridoMotor - maxRecorridoMotor/8))  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    //Serial.print("Dir 1 - ");
    //Serial.println(stepper.currentPosition());
    delay(1);
  }
  //Serial.println(stepper.currentPosition());
  while(stepper.currentPosition() < maxRecorridoMotor)
  {
    stepper.setSpeed(motorSpeed/1.5);
    stepper.runSpeed();
    delay(1);
    //Serial.print("Dir 1 - ");
    //Serial.println(stepper.currentPosition());
  }
  
  delay(tiempoInspiracionExpiracion*1000);

  digitalWrite(electroVExpiracion, HIGH);
  digitalWrite(electroVInspiracion, LOW);
  digitalWrite(pin_Stepper_DIR, HIGH);     // active (inverted)
  Serial.println("Expiracion");
  while (stepper.currentPosition() > maxRecorridoMotor/4)   {
    stepper.setSpeed(-(motorSpeed/relacionInspiracionExpiracion));
    stepper.runSpeed();
    delay(1);
    //Serial.print("Dir 2 - ");
    //Serial.println(stepper.currentPosition());
  }
  while(stepper.currentPosition() > 0)
  {
    stepper.setSpeed(-(motorSpeed/relacionInspiracionExpiracion)/1.2);
    stepper.runSpeed();
    delay(1);
    //Serial.print("Dir 1 - ");
   // Serial.println(stepper.currentPosition());
  }

  delay(250); // Elimina la inercia que lleve el brazo
  if(!digitalRead(minZendstop)) alejarseFinalCarrera();
  //delay(tiempoInspiracionExpiracion*1000);
  cantidadCiclos++;
  Serial.print("Ciclos: ");
  Serial.println(cantidadCiclos);
}

void alejarseFinalCarrera()
{
  // Para alejarme 50 pasos del final de carrera
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() < 100)  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    delay(1);
    Serial.print("Alejandome del final de carrera...");
    //Serial.println(stepper.currentPosition());
  }
  
  stepper.setCurrentPosition(0);
}
