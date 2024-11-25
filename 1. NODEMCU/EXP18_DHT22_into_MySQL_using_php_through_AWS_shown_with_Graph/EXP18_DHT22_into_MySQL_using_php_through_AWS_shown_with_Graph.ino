#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

DHT dht(D1,DHT22);
float hum,temp_c,temp_f;

char* ssid = "Naganandana";
char* pass = "";

WiFiClient wifiClient;


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
}

void loop() {
  hum = dht.readHumidity();
  temp_c = dht.readTemperature();
  temp_f = dht.readTemperature(true);

  Serial.print("Humidity:");Serial.print(hum);Serial.print(",");
  Serial.print("Temperature:");Serial.print(temp_c);Serial.print("*C,");
  Serial.print(temp_f);Serial.println("*F");
 
  HTTPClient client;
  String api = "http://3.29.135.164/myinsert.php?h="+String(hum)+"&t="+String(temp_c);
  client.begin(wifiClient,api);
  int code = client.GET();   // Gets the Status code which gives the response     

  String response = client.getString(); // gets the corresponding response 

  Serial.print("Status Code: ");Serial.println(code);  // Pritnting the status code
  Serial.println(response);    // Print the response

  delay(5000);
}