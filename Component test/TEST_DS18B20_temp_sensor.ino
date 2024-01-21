#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 4

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer1, insideThermometer2;

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);

  // Start up the library
}

void loop(void){ 
 //VARIABLE POUR MESURER BDSP19B20 //
    sensors.begin();
    sensors.getAddress(insideThermometer1, 0);
    sensors.getAddress(insideThermometer2, 1);
    sensors.requestTemperatures();
    float temperature0 =  sensors.getTempC(insideThermometer1);
    float temperature1 = sensors.getTempC(insideThermometer2);
     Serial.println("Temperature1 DS18B20 = " + String(temperature0) +" °C");
    Serial.println("Temperature2 DS18B20 = " + String(temperature1) +" °C");
    delay (5000);
}