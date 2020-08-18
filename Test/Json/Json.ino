/*
Date: 26.06.2020
Autor: Miguel Califa
Objective:
    Send a JSON using serialPort without libraries and the most simplified
    as posible.
Base: json.json
*/

// Program vars
String jsonObject = "";
int volumen = 0;
int peep = 1;
String relaIE = 2:4;
int PIP = 3;
String alarmas = "";
String CM = "CV - Control por volumen";
int frecuencuencia_respiratoria = 4;
int flujo = "";
int presion = "";

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    jsonObject = "{\
    'Nombre_Ventilador': 'Salvarting-Demo-0001',\
    'Fecha_Fabricacion': '2020/06/26',\
    'Volumen_Ambu': '600',\
    'Peep': '60%',\
    'FiO2': 'Manual - Valvulas',\
    'Relacion_IE': '1:1',\
    'PIP': '30%',\
    'Modo_Control': 'CV-Control por volumen',\
    'Alarmas': 'No - habilitado',\
    'Frecuencia_Respiratoria': 15,\
    'Valvula_Alivio_Presion': 'Ambu - Default',\
    'Sensor_Flujo': 'YF-S201',\
    'Flujo': 1.23,\
    'Unidad_Flujo': 'm3',\
    'Sensor_Presion': 'MPX5010GP',\
    'Presion': 20,\
    'Unidad_Presion': 'KPa'\
    }";
    
    jsonObject.replace("600", volumen);
    jsonObject.replace("60", peep);
    jsonObject.replace("1:1", volumen);
    jsonObject.replace("600", volumen);
    jsonObject.replace("600", volumen);
    jsonObject.replace("600", volumen);

    Serial.println(jsonObject);
    delay(1000);
}