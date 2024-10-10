#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h>
#include<Adafruit_MQTT_Client.h>
#include "DHT.h"
DHT dht(D4,DHT22);

#define ssid "Naganandana"
#define pass ""
#define server "io.adafruit.com"
#define port 1883
#define user "naganandana"
#define key "aio_ngJJ81Nfk1MriUbVo20TgjyJwpA4"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,server,port,user,key);
Adafruit_MQTT_Publish guage = Adafruit_MQTT_Publish(&mqtt,user"/feeds/temp");
float data;
void MQTT_Connect(){
     if(mqtt.connected()){
          return;
       }
     Serial.println("Connecting to MQTT...");
     int retries = 3,status;
     while((status = mqtt.connect()) != 0){
          Serial.println(mqtt.connectErrorString(status));
          Serial.println("Retrying after 5 secs....");
          delay(5000);
          retries--;
          if(retries == 0){
              while(1);   // reset the nodemcu
            }
      }
      Serial.println("MQTT Connected");
  }
void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected !");
}

void loop() {
  MQTT_Connect();
  data = dht.readTemperature();
  if(guage.publish(data)){
      Serial.print("Data Published:");Serial.println(data);
    }
   else{
      Serial.println("Data Failed");
    }
   delay(3000);
}