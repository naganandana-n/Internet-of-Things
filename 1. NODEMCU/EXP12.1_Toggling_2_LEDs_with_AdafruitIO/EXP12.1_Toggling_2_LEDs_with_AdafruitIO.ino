#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define ssid "Naganandana"
#define pass ""
#define server "io.adafruit.com"
#define port 1883
#define user "naganandana"
#define key "aio_cLcw86UGvtao5BzGrxbLxgIBQvoZ"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, server, port, user, key);

Adafruit_MQTT_Subscribe toggle1 = Adafruit_MQTT_Subscribe(&mqtt, user"/feeds/led1"); // get this from 'Feed Info'
Adafruit_MQTT_Subscribe toggle2 = Adafruit_MQTT_Subscribe(&mqtt, user"/feeds/led2"); // its "/feeds" - the / is IMP!

void MQTT_Connect(){
if (mqtt.connected()){
return;
}
Serial.println("Connecting to MQTT...");
int retries = 3;
int status;
while((status = mqtt.connect()) != 0){
Serial.println(mqtt.connectErrorString(status));
delay(5000);
retries--;
if(retries == 0){
while(1);
}
}
Serial.println("MQTT Connected!");
}

void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("Toggling 2 LED's with Adafruit IO!");

pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);

Serial.println("Connecting to WiFi...");
WiFi.begin(ssid, pass);
while(WiFi.status() != WL_CONNECTED){
Serial.print(".");
delay(500);
}
Serial.println("");
Serial.println("WiFi Connected!");

mqtt.subscribe(&toggle1);
mqtt.subscribe(&toggle2);
}

void loop(){
MQTT_Connect();
Adafruit_MQTT_Subscribe *subscription;

while(subscription = mqtt.readSubscription(5000)){

if (subscription == &toggle1){
char* data = (char*)toggle1.lastread;
Serial.println(data);
if (strcmp(data, "ON") == 0){
digitalWrite(D3, HIGH);
Serial.println("LED 1 IS ON!");
}
if (strcmp(data, "OFF") == 0){
digitalWrite(D3, LOW);
Serial.println("LED 1 IS OFF!");
}
}

if (subscription == &toggle2){
char* data = (char*)toggle2.lastread;
Serial.println(data);
if (strcmp(data, "ON") == 0){
digitalWrite(D4, LOW);
Serial.println("LED 2 IS ON!");
}
if (strcmp(data, "OFF") == 0){
digitalWrite(D4, HIGH);
Serial.println("LED 2 IS OFF!");
}
}
}
}