/*
Date: 26.06.2020
Autor: Miguel Califa
Objective:
    Send a JSON using serialPort without libraries and the most simplified
    as posible.
Base: json.json
*/
String jsonObject = "";
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    jsonObject = '\
    {\
        "Nombre_Ventilador": "Salvarting-Demo-0001",\
        "Fecha_Fabricacion": "2020/06/26",\
        "Volumen_Ambu": "600",\
        "Peep": "60%",\
        "FiO2": "Manual - Valvulas",\
        "Relacion_IE": "1:1",\
        "PIP": "30%",\
        "Modo_Control": "CV-Control por volumen",\
        "Alarmas": "No - habilitado",\
        "Frecuencia_Respiratoria": 15,\
        "Valvula_Alivio_Presion": "Ambu - Default",\
        "Sensor_Flujo": "YF-S201",\
        "Flujo": 1.23,\
        "Unidad_Flujo": "m3",\
        "Sensor_Presion": "MPX5010GP",\
        "Presion": 20,\
        "Unidad_Presion": "KPa"\
    }';
    Serial.println(jsonObject);
    delay(1000);
}