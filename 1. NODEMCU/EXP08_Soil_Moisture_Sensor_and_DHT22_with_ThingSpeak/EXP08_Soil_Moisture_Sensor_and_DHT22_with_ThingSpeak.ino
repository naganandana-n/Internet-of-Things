#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

DHT dht(D4, DHT22);

const int soil_sensor = A0; // soil sensor - analog pin
float hum, temp_c, temp_f; // dht22 sensor

char* ssid = "Naganandana";
char* pass = "";

WiFiClient client;

// ThingSpeak details
long id = 2725078;
char* api = "RTAZ4FCELUHZB8OR"; // Write API keys
char ip[] = "184.106.153.149"; // always the same - can also write: char* ip = "api.thingspeak.com" TRY!!

void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("DHT22 and Soil Moisture sensor on ThingSpeak!");

dht.begin();

Serial.print("Connecting to Wifi...");
WiFi.begin(ssid, pass);
while(WiFi.status() != WL_CONNECTED){
Serial.print(".");
delay(500);
}
Serial.println("");
Serial.println("Wifi connected!");

ThingSpeak.begin(client);
}

void loop(){
if(client.connect(ip, 80)){
hum = dht.readHumidity();
temp_c = dht.readTemperature();
temp_f = dht.readTemperature(true);

float moisture_percentage;
// moisture percentage formula:
moisture_percentage = (100 - ((analogRead(soil_sensor) / 1023.00) * 100));

Serial.print("Humidity:");Serial.print(hum);Serial.print(",");
Serial.print("Temperature:");Serial.print(temp_c);Serial.print("*C,");
Serial.print(temp_f);Serial.println("*F");Serial.print(",");
Serial.print("Soil Moisture:");Serial.print(moisture_percentage); Serial.println("%");

// Sending Data to ThingSpeak:
ThingSpeak.setField(1, temp_c);
ThingSpeak.setField(2, temp_f);
ThingSpeak.setField(3, hum);
ThingSpeak.setField(4, moisture_percentage);
ThingSpeak.writeFields(id, api); // IMP!!
}

delay(15000); // Adds a 15-second delay between each reading.
// This matches ThingSpeak's rate limit, which is one update every 15 seconds.
}