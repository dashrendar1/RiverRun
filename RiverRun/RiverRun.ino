#include <NewPing.h> // libreria para sonar ultrasonico
#include <OneWire.h> // libreria para comunicacion serial
#include <DallasTemperature.h> //libreria para formulas de temperatura

#define ONE_WIRE_BUS 6
#define Voltage 13
#define TRIGGER_PIN  7
#define ECHO_PIN     8
#define MAX_DISTANCE 200
#define valpass 5

int abc = 22; //Marcado
int def = 23;
int ghi = 24;
int jkl = 25;
int confi = 26;
int val = 0;
int VIENTO = A2;
int CAUDAL = A3;
char cadena[50];
int pass = 0;
int temp = 0;
int us = 0;
int viento = 0;
int caudal = 0;

OneWire oneWire(ONE_WIRE_BUS); // creacion objeto one wire
DallasTemperature sensors(&oneWire); // enlace para lecturas a objeto dallas temperature
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//creacion objeto sonar

void setup(void)
{
  pinMode(confi,OUTPUT);
  Serial.begin(9600);
  sensors.begin();
  pinMode(Voltage,OUTPUT);
  digitalWrite(Voltage, HIGH); 
}
 
 
void loop(void)
{
  delay(1000);
  temperatura();
  velocidadCaudal();
  velocidadViento();
  ultrasonico();
  if (pass == valpass){
    Serial.print("Prueba ");
    Serial.println(cadena);
     con();
     recorrido();
     env();
    pass=0; 
    Serial.println(pass);
  }
  pass++;
  memset(cadena, 0, sizeof(cadena));
}

void recorrido (void){
  
 
  for (int p =0; p <= strlen(cadena); p++){
    if(cadena[p] == '0'){
      a();
    }
      if(cadena[p] == '1'){
      b();
    }
      if(cadena[p] == '2'){
      c();
    }
      if(cadena[p] == '3'){
      d();
    }
      if(cadena[p] == '4'){
      e();
    }
      if(cadena[p] == '5'){
      f();
    }
    
      if(cadena[p] == '6'){
      g();
    }
    
     if(cadena[p] ==  '7'){
      h();
    }
    
      if(cadena[p] == '8'){
      i();
    }
    
      if(cadena[p] == '9'){
      j();
    }
    
      if(cadena[p] == '.'){
      k();
    }
    
      if(cadena[p] == ' '){
      l();
    }
  }
}

void temperatura(void){  
  sensors.requestTemperatures(); 
  Serial.print("Temperatura: ");
  Serial.println(sensors.getTempCByIndex(0)); 
  temp = sensors.getTempCByIndex(0);
  if (pass==valpass){
    char ct[5];
    sprintf(ct,"%d ",temp);
    strcat(cadena, ct);
    temp = 0;
  }
}

void ultrasonico(void){
  us += sonar.ping_median();
  Serial.print("Distancia: ");
  Serial.print(us / US_ROUNDTRIP_CM);
  Serial.println("cm");
  if (pass==valpass){
    int division = (us / US_ROUNDTRIP_CM/valpass);
    char cu[5];
    sprintf(cu,"%d ",division);
    strcat(cadena, cu);
    us= 0;
  }
} 

void velocidadViento(void){
  int val = analogRead(VIENTO);
    viento += val-60;
  Serial.print("Velocidad del viento: ");
  Serial.println(viento);
  if (pass==valpass){
    int division = viento/valpass;
    division = division/10; 
    char cvv[5];
    sprintf(cvv,"%d ",division);
    strcat(cadena, cvv);
    viento = 0;
  }
}
  
void velocidadCaudal(void){
  caudal+= analogRead(CAUDAL);
  Serial.print("Velocidad del rio: ");
  Serial.println(caudal);
  if (pass==valpass){
    int division = caudal/valpass;
    division = division/10; 
    char cvc[5];
    sprintf(cvc,"%d ",division);
    strcat(cadena, cvc);
    caudal = 0;
  }
}

  void con(void){ // Escritura
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(1000);
  }

void env(void){
   digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
  delay(250);
  digitalWrite(confi,HIGH);
  delay(500);
  digitalWrite(confi,LOW);
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

