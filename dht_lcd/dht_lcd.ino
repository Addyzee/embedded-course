
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
#define DHTPIN 2   
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);



void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(3000);

  float h = dht.readHumidity();
  // Read temperature as Celsius 
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C Heat index "));
  Serial.print(hic);
  Serial.println(F("°C "));

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print(" C");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("H index: ");
  lcd.print(hic);
  lcd.print((char)223);
  lcd.print(" C");

}