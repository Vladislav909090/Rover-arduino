#include "DHT.h"
#include <Wire.h> 
#include <BMP085.h>
#include "LiquidCrystal.h"

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

BMP085 dps = BMP085();    
long Temperature = 0, Pressure = 0;

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Wire.begin(); 
  delay(1000);
  dps.init(); 
  lcd.begin(16,2);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
  
  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print("  Pressure(mmHg): "); 
  Serial.print(Pressure/133.3);
  Serial.print("  Temp: "); 
  Serial.print(Temperature*0.1);
  Serial.println(" *C");
  
  lcd.setCursor(0,0);
  lcd.print("Pr: ");
  lcd.print(Pressure/133.3, 2);
  lcd.print("mmHg");
  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.print(h,1);
  lcd.print("% T:");
  lcd.print(Temperature*0.1, 1);
  lcd.print("*C");
}
