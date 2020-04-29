#define DIR 55
#define STEP 54
#define pin_Stepper_Disable    38
void setup() {
  // put your setup code here, to run once:
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(pin_Stepper_Disable, OUTPUT);
  
  digitalWrite(pin_Stepper_Disable, LOW);
  digitalWrite(DIR, HIGH);
  Serial.begin(115200);
  Serial.println("Started");
 }
int rpm = 0;
unsigned long base = 0;
void loop() {
  base = millis();
  // put your main code here, to run repeatedly:
  while(millis() - base <= 60000){
      for(int x = 0; x < 200; x++) {
      digitalWrite(STEP,HIGH); 
      delayMicroseconds(380); 
      digitalWrite(STEP,LOW); 
      delayMicroseconds(380); 
    }
    rpm++;
  }
  Serial.print("rpm: ");
  Serial.println(rpm);
  while(1);
}
