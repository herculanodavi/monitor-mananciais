#include <OneWire.h>
#include <DallasTemperature.h>

// Turbidity sensor
int turbidityPin = 8;
 
// Temperature sensor
#define ONE_WIRE_BUS 28
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

int turb;
float tempC;

void setup() {
  // serial init
  Serial.begin(9600);

  // temperature sensor init
  sensors.begin();
  if (!sensors.getAddress(sensor1, 0)) 
     Serial.println("Temperature sensor error!"); 
}

void loop() {
  // temperature
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print(tempC);
  Serial.print(" ");

  // turbidity
  turb = analogRead(turbidityPin);
  Serial.println(turb);
  delay(50);
}
