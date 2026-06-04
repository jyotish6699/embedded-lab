#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define BAUDRATE 9600

//DHT11      Arduino

//VCC    -> 5V
//GND    -> GND
//DATA   -> Pin 2

// create DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(BAUDRATE);
  dht.begin();

  Serial.println("DHT11 Weather Station");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {

    Serial.println("Failed to read from DHT11!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C");

  Serial.print(" | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}

