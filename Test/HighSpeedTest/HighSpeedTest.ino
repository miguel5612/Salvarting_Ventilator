#define DIR 55
#define STEP 54

int x = 600;

void setup() {
  // put your setup code here, to run once:
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);

  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);
}

void loop() {
  for(int j=0; j<3000; j++)
  {
   for(int i = 0; i<5; i++)
   {
      digitalWrite(STEP, HIGH);
      delayMicroseconds(x);
      digitalWrite(STEP, LOW); 
   }
   if(x>=24) x--;
  }
}
