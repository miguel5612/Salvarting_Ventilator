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

void setup()
{
    pinMode(pot0, INPUT);
    pinMode(pot1, INPUT);
    pinMode(pot2, INPUT);
    pinMode(pot3, INPUT);

    pinMode(selector, INPUT);
    Serial.begin(9600);
}
void loop()
{
    leerPots();

    serialPots();
    
    delay(1000);
}
void serialPots()
{
    Serial.print("Volume: "); Serial.print(volume); Serial.println(" cm3");
    Serial.print("Relacion IE: "); Serial.print(IE); Serial.println("");
    Serial.print("PIP: "); Serial.print(PIP); Serial.println(" cmH2O");
    Serial.print("Freq: "); Serial.print(freq); Serial.println("");
    Serial.print("Sel: "); Serial.print(sel); Serial.println("");
    Serial.println("***********************************");
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