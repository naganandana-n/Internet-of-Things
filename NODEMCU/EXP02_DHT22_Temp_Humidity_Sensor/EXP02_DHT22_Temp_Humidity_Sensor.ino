#include "DHT.h"

// Define the pin where the DHT22 is connected
#define DHTPIN D4

// Define the type of DHT sensor used (DHT11, DHT22, DHT21)
#define DHTTYPE DHT22

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  Serial.println("DHT22 sensor test!");

  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);

  // Reading temperature and humidity values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius by default

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  
  


}
