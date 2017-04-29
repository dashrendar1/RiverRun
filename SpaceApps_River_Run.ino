#include <NewPing.h> // libreria para sonar ultrasonico
#include <OneWire.h> // libreria para comunicacion serial
#include <DallasTemperature.h> //libreria para formulas de temperatura

#define ONE_WIRE_BUS 2
#define Voltage 13
#define TRIGGER_PIN  4
#define ECHO_PIN     3
#define MAX_DISTANCE 300

OneWire oneWire(ONE_WIRE_BUS); // creacion objeto one wire
DallasTemperature sensors(&oneWire); // enlace para lecturas a objeto dallas temperature
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//creacion objeto sonar

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(Voltage,OUTPUT);
  digitalWrite(Voltage, HIGH); 
}
 
 
void loop(void)
{
  delay(1000);
  temperatura();
  ultrasonico();
}

void temperatura(void){  
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); 
  Serial.println("DONE");
  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0)); 
 }

void ultrasonico(void){
  int uS = sonar.ping_median();
  Serial.println("");
  Serial.print("Distancia: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
} 

