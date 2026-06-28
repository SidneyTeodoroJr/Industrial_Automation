//TESTE SENSOR DALLAS DS18B20
//CONECTAR O PINO DE DADOS DO SENSOR
//NO BORNE "SCL" E OS PINOS DE ALIMENTAÇÃO
//NOS BORNES +5V E GND


#include <OneWire.h>
#include <DallasTemperature.h>

// DEFINE QUAL PINO DO ESP32 SERÁ UTILIZADO (22=SCL)
#define ONE_WIRE_BUS 22
#define TEMPERATURE_PRECISION 9 // Lower resolution

float TEMPERATURA;

//DEFINE INSTÂNCIA DE COMUNICAÇÃO ONE WIRE
OneWire oneWire(ONE_WIRE_BUS);

//DEFINE INSTÂNCIA ONE WIRE PARA SENSOR DALLAS 18B20
DallasTemperature sensors(&oneWire);

//DEFINE VARIAVEL COM OS DADOS DO SENSOR
DeviceAddress tempDeviceAddress; 

void setup() {
  // INICIALIZA SERIAL 
  Serial.begin(9600);
  Serial.println("DEMO SENSOR DALLAS 18B20");
  
  //INICIALIZA BIBLIOTECA
  sensors.begin();

  //BUSCA ENDEREÇO DO SENSOR
  sensors.getAddress(tempDeviceAddress, 0);

  //AJUSTA PRECISÃO DO SENSOR
  sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
}

void loop() {
  // BUSCA TEMPERATURA
  sensors.requestTemperatures();

  //ARMAZEWNA TEMPERATURA NA VARIÁVEL
  TEMPERATURA = sensors.getTempC(tempDeviceAddress);
  Serial.println("Valor da temperatura = " + String(TEMPERATURA));
  delay(1000);
}
