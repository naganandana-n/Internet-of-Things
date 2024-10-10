#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
DHT dht(D1,DHT22);
const int sensor_pin = A0;
float hum,temp_c,temp_f;

char* ssid = "Naganandana";
char* pass = "";
WiFiClient client;
long id = 2659266;
char* api = "U6MID7QL4MBOMB4N";
char ip[] = "184.106.153.149";
void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client);
}
void loop() {
  if(client.connect(ip,80)){
      hum = dht.readHumidity();
      temp_c = dht.readTemperature();
      temp_f = dht.readTemperature(true);
      float moisture_percentage;
      moisture_percentage = (100.00 - ((analogRead(sensor_pin)/1023.00)*100));
      Serial.print("Humidity:");Serial.print(hum);Serial.print(",");
      Serial.print("Temperature:");Serial.print(temp_c);Serial.print("*C,");
      Serial.print(temp_f);Serial.println("*F");Serial.print(",");
      Serial.print("Soil Moisture:");Serial.print(moisture_percentage); Serial.println("%");
      ThingSpeak.setField(1,temp_c);
      ThingSpeak.setField(2,hum);
      ThingSpeak.setField(3, moisture_percentage);
      ThingSpeak.writeFields(id,api);
    }
  delay(15000);
}