#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h> // HEADER FILES REQUIRED FOR ADAFRUIT MQTT
#include<Adafruit_MQTT_Client.h>

#define ssid ""
#define pass ""
#define server "io.adafruit.com" // CLOUD SERVER
#define port 1883 // MQTT PORT NUMBER (FIXED)
 
#define user "" // GET FROM ADAFRUIT WEBSITE
#define key ""

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,server,port,user,key);
Adafruit_MQTT_Subscribe toggle = Adafruit_MQTT_Subscribe(&mqtt,user"/feeds/led"); // TWO TOPICS: 
Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt,user"/feeds/slider"); // TOGGLE AND SLIDER
void MQTT_Connect(){
     if(mqtt.connected()){
          return;
       }
     Serial.println("Connecting to MQTT...");
     int retries = 3,status; // WILL TRY TO CONNECT TO MQTT 3 TIMES.
     while((status = mqtt.connect()) != 0){
          Serial.println(mqtt.connectErrorString(status));
          Serial.println("Retrying after 5 secs....");
          delay(5000);
          retries--;
          if(retries == 0){
              while(1);   // IMP: RESET THE NODEMCU
            }
      }
      Serial.println("MQTT Connected");
  }
void setup() {
  Serial.begin(9600);
  pinMode(D4,OUTPUT);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!= WL_CONNECTED){ // CONNECTING TO WIFI
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected !");
  mqtt.subscribe(&toggle); // NODEMCU TRIES TO SUBSCRIBE TO TOGGLE AND SLIDER 
  mqtt.subscribe(&slider);
}

void loop() {
  MQTT_Connect();
  Adafruit_MQTT_Subscribe *subscription; // CHECK OUT WHY THIS IS A POINTER
  while(subscription = mqtt.readSubscription(5000)){

       if(subscription == &toggle){
          char* data = (char*)toggle.lastread;
          Serial.println(data);
          if(strcmp(data,"ON")==0){
              digitalWrite(D4,HIGH);
              Serial.println("LED IS ON");
            }
           if(strcmp(data,"OFF")==0){
              digitalWrite(D4,LOW);
              Serial.println("LED IS OFF");
            }
        }

        if(subscription == &sm
          int brightness = atoi((char*)slider.lastread); 
          Serial.println(brightness);
          analogWrite(D4,brightness);
         }
    }
}