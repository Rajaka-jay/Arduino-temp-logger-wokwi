#include <SPI.h>
#include <SD.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Check your I2C address (usually 0x27 or 0x3F)

const int chipSelect = 4;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  if (!SD.begin(chipSelect)) {
    lcd.print("SD Fail!");
    return;
  }
  lcd.print("Logging Start...");
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(hum);
  lcd.print("%");

  // Log to SD Card
  File dataFile = SD.open("log.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Temp: ");
    dataFile.print(temp);
    dataFile.print(" C, Hum: ");
    dataFile.print(hum);
    dataFile.println(" %");
    dataFile.close();
  }

  delay(5000); // Wait 5 seconds between logs
}