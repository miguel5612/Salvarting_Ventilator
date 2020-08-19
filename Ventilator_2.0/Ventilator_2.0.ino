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
#define motorMaxAcceleration    4000
#define electroVExpiracion    8
#define electroVInspiracion   9
#define delayDriverResponse   1
#define delayToRemoveInercia 100

#define pot0 A9 // Volumen
#define pot1 A5 // Relacion Inspiracion/Expiracion
#define pot2 A11 // PIP 
#define pot3 A12 // Frecuencia respiratoria

#define selector A10

// Configs
#define maxVolume 600 //cm3
#define minVolume 100 //cm3
#define maxIE 3.2 //relacion (Adimensional)
#define minIE 1 //relacion (Adimensional)
#define maxPip 80 //cmH2O
#define minPip 5 //cmH2O
#define maxFreq 35 //35 por minuto
#define minFreq 10 //10 por minuto
//EQ
float m1 = (maxVolume-minVolume)/(1024.0-0.0);
float m2 = (maxIE-minIE)/(1024.0-0.0);
float m3 = (maxPip-minPip)/(1024.0-0.0);
float m4 = (maxFreq-minFreq)/(1024.0-0.0);

short sel = 0; //0 - Apagado; 1 - Control volumen; 2 - Control Presion
int temp = 0, volume, PIP, freq;
float IE;

#include <AccelStepper.h>  // Stepper / servo library with step pulse / dir interface
AccelStepper stepper(1, pin_Stepper_Step, pin_Stepper_DIR);

double motorSpeed = 800;
double maxRecorridoMotor = 900;

double relacionInspiracionExpiracion = 1;
float tiempoInspiracionExpiracion = 0.4;

int cantidadCiclos = 0;

const int distanceToEndstopMinZ = 160;
const int distanceToTouchAmbu = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BAUD);
  pinMode(electroVExpiracion, OUTPUT);
  pinMode(electroVInspiracion, OUTPUT);
  pinMode(minZendstop, INPUT_PULLUP);
  
  pinMode(pin_Stepper_DIR, OUTPUT);
  
  pinMode(pin_Stepper_Step, OUTPUT);
  digitalWrite(pin_Stepper_Step, LOW);    // active (inverted)
  
  pinMode(pin_Stepper_Disable, OUTPUT);
  digitalWrite(pin_Stepper_Disable, HIGH);
  
  stepper.setMaxSpeed(motorMaxAcceleration);

  pinMode(pot0, INPUT);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);

  pinMode(selector, INPUT);
  
  Serial.begin(9600);
  Serial.println("Init started");
  
  digitalWrite(pin_Stepper_DIR, HIGH);     // active (inverted)
  while(!z0reached())
  {
      stepper.setSpeed(-motorSpeed);
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
  Serial.println("Inspiracion");  
  //Serial.println(stepper.currentPosition());
  while (stepper.currentPosition() < (maxRecorridoMotor - distanceToEndstopMinZ - distanceToTouchAmbu))  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    Serial.println("Avance lento");
    //Serial.println(stepper.currentPosition());
    delay(delayDriverResponse);
  }
  //while(1);
  delay(tiempoInspiracionExpiracion*1000);

  digitalWrite(electroVExpiracion, HIGH);
  digitalWrite(electroVInspiracion, LOW);
  Serial.println("Expiracion");
  while ((stepper.currentPosition() > distanceToEndstopMinZ) & (!z0reached()))   {
    stepper.setSpeed(-(motorSpeed/relacionInspiracionExpiracion));
    stepper.runSpeed();
    delay(delayDriverResponse);
    Serial.println("Reversa rapida");
    //Serial.println(stepper.currentPosition());
  }

  delay(delayToRemoveInercia); // Elimina la inercia que lleve el brazo
  if(z0reached()) alejarseFinalCarrera();
  //delay(tiempoInspiracionExpiracion*1000);
  cantidadCiclos++;
  Serial.print("Ciclos: ");
  Serial.println(cantidadCiclos);
  
  leerPots();
}

void alejarseFinalCarrera()
{
  // Para alejarme 50 pasos del final de carrera
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() < (distanceToEndstopMinZ + distanceToTouchAmbu))  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    delay(delayDriverResponse);
    Serial.print("Alejandome del final de carrera...");
    //Serial.println(stepper.currentPosition());
  }
}

bool z0reached()
{
  return !digitalRead(minZendstop);
}
