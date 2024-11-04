#include<DHT.h>

#define dhtpin D4
#define dhttype DHT22

DHT dht(dhtpin, dhttype);

void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.print("");
Serial.println("DHT22 temperature and humidity sensor!");

dht.begin();
}

void loop(){

delay(2000); // wait before looping

float humidity = dht.readHumidity();
float temperature = dht.readTemperature(); // Celcius by default -> learn the conversion from celcius to farenheit

// check if the sensor works properly
if (isnan(humidity) || isnan(temperature)){
Serial.println("Failed to read from DHT sensor!");
return; // starts the loop() again -> This return only exits the current loop() iteration, not the entire program.
}

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print(" % | ");
Serial.print(" Temperature: ");
Serial.print(temperature);
Serial.println(" *C");
}