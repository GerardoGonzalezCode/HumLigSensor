#include <DHT.h>
 
#define DHTPIN 32
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   Serial.begin(115200);
   dht.begin();
}
 
void loop() {
   delay(1000);

   float h = dht.readHumidity();
   float t = dht.readTemperature();
   if (isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
   }
   float hic = dht.computeHeatIndex(t,h,false);
   readValues(h,t,hic);
}

float readValues(float h, float t, float hic){
  float tempMax = 28;
  float tempMin = 18;
  float hum = 60;
  if(t >= tempMax){
    print("Planta temperatura no Optima, Temperatura Alta: ");
    print(t);
  }
  if(t <= tempMin){
    print("Planta temperatura no Optima, Temperatura Baja: ");
    print(t);
  }
  if(h <= hum){
    print("Planta Humedad no Optima: ");
    print(h);
  }
}
