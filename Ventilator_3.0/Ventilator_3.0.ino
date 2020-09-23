/*
 * 
 * Ventilator software version 3.0 
 * Created By: Miguel Califa
 * Start: 09.2020
 * Motivation: Implementing FreeRTOS we can do all tasks managed by OS.
 * Support: miguelangel5612@gmail.com
 * 
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

#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include <AccelStepper.h>  // Stepper / servo library with step pulse / dir interface

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
#define minFreq 6 //6 por minuto
//EQ
float m1 = (maxVolume-minVolume)/(1024.0-0.0);
float m2 = (maxIE-minIE)/(1024.0-0.0);
float m3 = (maxPip-minPip)/(1024.0-0.0);
float m4 = (maxFreq-minFreq)/(1024.0-0.0);

short sel = 0; //0 - Apagado; 1 - Control volumen; 2 - Control Presion
int temp = 0, volume, PIP, freq;
float IE;


double motorSpeed = 800;
double maxRecorridoMotor = 900;

double relacionInspiracionExpiracion = 1;
float tiempoInspiracionExpiracion = 0.4;

int cantidadCiclos = 0;

const int distanceToEndstopMinZ = 160;
const int distanceToTouchAmbu = 0;
const int PressureSensorPin = A3;
const int FlowSensorPin = 32;

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;
AccelStepper stepper(1, pin_Stepper_Step, pin_Stepper_DIR);

// define two Tasks for DigitalRead & AnalogRead
void TaskDigitalRead( void *pvParameters );
void TaskAnalogRead( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  ArduinoSetup();
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
  
  // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
  // because it is sharing a resource, such as the Serial port.
  // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

  // Now set up Tasks to run independently.
  xTaskCreate(
    TaskVentilatePatient
    ,  "Ventilate_Patient"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

  xTaskCreate(
    TaskLeerPots
    ,  "Read controls"
    ,  128  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL );

  xTaskCreate(
    TaskMonitorVars
    ,  "Monitor vars"
    ,  128  // Stack size
    ,  NULL
    ,  3  // Priority
    ,  NULL );
  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
  
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskMonitorVars( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    monitorVars();
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskLeerPots( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    leerPots();
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskVentilatePatient( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    loopVentilator();
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void monitorVars()
{
  serialShow("Flow Sensor lecture: ");
  serialShow(String(digitalRead(FlowSensorPin)));
  serialShow("Pressure Sensor lecture: ");
  serialShow(String(analogRead(PressureSensorPin)));  
  vTaskDelay(32);  // one tick delay (15ms) in between reads for stability
  vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
}
void ArduinoSetup()
{
  
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BAUD);
  pinMode(electroVExpiracion, OUTPUT);
  pinMode(electroVInspiracion, OUTPUT);
  pinMode(FlowSensorPin, INPUT);
  pinMode(PressureSensorPin, INPUT);
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

  /* DESCOMENTAR, IMPORTANTEEEE
  while(!z0reached())
  {
      stepper.setSpeed(-motorSpeed);
      stepper.runSpeed();
      Serial.println("Buscando origen...");
  }

  delay(150);

  alejarseFinalCarrera();
  
  delay(150);
  */
}

void loopVentilator()
{
   digitalWrite(electroVExpiracion, LOW);
  digitalWrite(electroVInspiracion, HIGH);
  serialShow("Inspiracion");  
  //serialShowln(stepper.currentPosition());
  serialShow("Avance lento");
  while (stepper.currentPosition() < (maxRecorridoMotor - distanceToEndstopMinZ - distanceToTouchAmbu))  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    //serialShowln(stepper.currentPosition());
    vTaskDelay(delayDriverResponse);
  }
  //while(1);
  vTaskDelay(tiempoInspiracionExpiracion*1000);

  digitalWrite(electroVExpiracion, HIGH);
  digitalWrite(electroVInspiracion, LOW);
  serialShow("Expiracion");
  serialShow("Reversa rapida");
  while ((stepper.currentPosition() > distanceToEndstopMinZ) & (!z0reached()))   {
    stepper.setSpeed(-(motorSpeed/relacionInspiracionExpiracion));
    stepper.runSpeed();
    vTaskDelay(delayDriverResponse);
    //serialShowln(stepper.currentPosition());
  }

  delay(delayToRemoveInercia); // Elimina la inercia que lleve el brazo
  if(z0reached()) alejarseFinalCarrera();
  //delay(tiempoInspiracionExpiracion*1000);
  cantidadCiclos++;
  serialShow("Ciclos: ");
  serialShow(String(cantidadCiclos));
  
}
void leerPots()
{
    temp = analogRead(pot0);
    volume = m1*temp + minVolume;
    
    temp = analogRead(pot1);
    IE = m2*temp + minIE;
    
    temp = analogRead(pot2);
    PIP = m3*temp + minPip;

    temp = analogRead(pot3);
    freq = m4*temp + minFreq;

    temp = analogRead(selector);
    if(temp <= 10)  sel = 1;
    else if(temp > 10 & temp<900) sel = 0;
    else sel = 2;
}
void calcularTiempos()
{
  // 19 de agosto de 2020
  // Elaborado por Miguel Angel Califa Urquiza
  // Esta funcion es de vital importancia para el correcto funcionamiento del ventilador, por ello sera documentada especialmente
  // 1. Con base en la frecuencia respiratoria, hallo el periodo de cada ciclo
  // 2. Con la relacion inspiracion y expiracion hallo los tiempos que debe tardar cada parte del ciclo
  // 3. Por ultimo si tengo bastante tiempo de expiracion, puedo permitir que el motor descanse o se detenga por completo puesto que la expiracion es un proceso mecanico
  int periodo = 0;
}

void alejarseFinalCarrera()
{
  // Para alejarme 50 pasos del final de carrera
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() < (distanceToEndstopMinZ + distanceToTouchAmbu))  {
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();
    delay(delayDriverResponse);
    serialShow("Alejandome del final de carrera...");
    //serialShowln(stepper.currentPosition());
  }
}

bool z0reached()
{
  return !digitalRead(minZendstop);
}
void serialShow(String msg)
{ 
  if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {  
      Serial.println(msg);
      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }
}
