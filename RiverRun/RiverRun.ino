#include <NewPing.h> // libreria para sonar ultrasonico
#include <OneWire.h> // libreria para comunicacion serial
#include <DallasTemperature.h> //libreria para formulas de temperatura

#define ONE_WIRE_BUS 6
#define Voltage 13
#define TRIGGER_PIN  7
#define ECHO_PIN     8
#define MAX_DISTANCE 300

int abc = 2;
int def = 3;
int ghi = 4;
int jkl = 5;
int o = 10;
int val = 0;
int VIENTO = A2;
int CAUDAL = A3;

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
  IR();
}

void temperatura(void){  
  sensors.requestTemperatures(); 
  Serial.print("Temperatura: ");
  Serial.print(sensors.getTempCByIndex(0)); 
 }

void ultrasonico(void){
  int uS = sonar.ping_median();
  Serial.println("");
  Serial.print("Distancia: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
} 

void velocidadViento(void){
  int v= analogRead(VIENTO);
  Serial.print("Velocidad del viento: ");
  Serial.println(v);
  }
  
 void velocidadCaudal(void){
  int v= analogRead(CAUDAL);
  Serial.print("Velocidad del rio: ");
  Serial.println(v);
  }

  void con(void){
  pinMode(o,HIGH);
  delay(500);
  pinMode(o,LOW);
  delay(250);
  pinMode(o,HIGH);
  delay(500);
  pinMode(o,LOW);
  delay(250);
  pinMode(o,HIGH);
  delay(500);
  pinMode(o,LOW);
  delay(250);
  pinMode(o,HIGH);
  delay(500);
  pinMode(o,LOW);
  delay(1000);
  }

void a(void){
   pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(1000);
  }
  
  void b(void){
   pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(250);
 pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(1000);
  }

  void c(void){
   pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(250);
    pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(250);
    pinMode(abc, HIGH);
    delay(500);
    pinMode(abc,LOW);
    delay(1000);    
  }

  void d(void){
   pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(1000);
  }
  
  void e(void){
   pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(250);
    pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(1000);
  }

  void f(void){
   pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(250);
    pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(250);
    pinMode(def, HIGH);
    delay(500);
    pinMode(def,LOW);
    delay(1000);    
  }

   void g(void){
   pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(1000);
  }
  
  void h(void){
   pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(250);
    pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(1000);
  }

  void i(void){
   pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(250);
    pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(250);
    pinMode(ghi, HIGH);
    delay(500);
    pinMode(ghi,LOW);
    delay(1000);    
  }

  void j(void){
   pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(1000);
  }
  
  void k(void){
   pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(250);
    pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(1000);
  }

  void l(void){
   pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(250);
    pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(250);
    pinMode(jkl, HIGH);
    delay(500);
    pinMode(jkl,LOW);
    delay(1000);    
  }
  
  void IR(void){
     val = analogRead(A1); // la variable val toma el valor del sensor que se conectará a la entrada analógica A1
    Serial.println(val);  // muestra por el puerto serie el valor de la variable val
    delay(500);  //
 }
