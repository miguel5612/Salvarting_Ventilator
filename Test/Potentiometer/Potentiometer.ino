#define pot0 A0 // Volumen
#define pot1 A1 // Relacion Inspiracion/Expiracion
#define pot2 A2 // PIP 
#define pot3 A3 // Frecuencia respiratoria

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
int m1 = (maxVolume-minVolume)/(255-0);
int m2 = (maxIE-minIE)/(255-0);
int m3 = (maxPip-minPip)/(255-0);
int m4 = (maxFreq-minFreq)/(255-0);

int temp = 0, volume, PIP, freq;
float IE;

void setup()
{
    pinMode(pot0, INPUT);
    pinMode(pot1, INPUT);
    pinMode(pot2, INPUT);
    pinMode(pot3, INPUT);

    Serial.begin(9600);
}
void loop()
{
    leerPots();

    Serial.print("Volume: "); Serial.print(volume); Serial.println("cm3");
    Serial.print("Relacion IE: "); Serial.print(IE); Serial.println("");
    Serial.print("PIP: "); Serial.print(PIP); Serial.println("cmH2O");
    Serial.print("Freq: "); Serial.print(Freq); Serial.println("");
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
}