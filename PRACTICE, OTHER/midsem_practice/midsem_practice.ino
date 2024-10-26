// Function:
// - WiFiClient client
// - Adafruit_MQTT_Client mqtt(&client, server, port, user, key);
// - Adafruit_MQTT_Subscribe toggle = Adafruit_MQTT_Subscribe(&mqtt, user "/feeds/newled");
// - Serial.println(mqtt.connectErrorString(status));
// - while(WiFi.status() != WL_CONNECTED)
// - mqtt.subscribe(&toggle)
// - just refer to the rest from the code, no use seeing here!

// header files:
#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

// defining network and MQTT server details:
#define ssid "Naganandana"
#define pass ""
#define server "io.adafruit.com" // cloud server (FIXED)
#define port 1883 // port number (FIXED)
#define user "naganandana" // get from adafruit website (KEY)
#define key "aio_iWFJ61WRfgRQWbdJvo6Cl8xqrSkM" 

// MQTT setup:
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, server, port, user, key);

// MQTT TOPICS: (IMP - UNDERSTAND TOPICS)
Adafruit_MQTT_Subscribe toggle = Adafruit_MQTT_Subscribe(&mqtt, user "/feeds/newled");

// MQTT connection function:
void MQTT_Connect(){
  if (mqtt.connected()){
    return;
  }
  Serial.println("Connecting to MQTT...");
  int retries = 3; // 3 chances to connect
  int status;
  while((status = mqtt.connect()) != 0){ // equal to zero -> connected
    Serial.println(mqtt.connectErrorString(status));
    delay(5000);
    retries--;
    if (retries == 0){
      while(1); // STOPS THE CODE, IF ITS UNABLE TO CONNECT (IMP)
    }
  } 
  Serial.println("MQTT Connected!");
}

void setup(){
  delay(1000);
  Serial.begin(9600);
  delay(1000);
  Serial.println("");
  Serial.println("Toggling an LED with Adafruit IO!");

  pinMode(D4, OUTPUT);
  
  // connecting to WiFi:
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected!");

  // SUBSCRIBE TO Toggle (IMP):
  // NOTE: If you have mutliple toggles, you can do:
  // mqtt.subscribe(&toggle1);
  // mqtt.subscribe(&toggle2);
  // mqtt.subscribe(&toggle3);
  mqtt.subscribe(&toggle);
}

void loop(){
  MQTT_Connect();
  Adafruit_MQTT_Subscribe *subscription; // its a pointer bcz, mqtt.readSubscription(5000) returns a pointer to it
                                         // and thus pointer of pointer, gives a normal object.

  while(subscription = mqtt.readSubscription(5000)){
    if (subscription == &toggle){
      char* data = (char*)toggle.lastread;
      Serial.println(data);
      if (strcmp(data, "ON") == 0){ // if data = "ON" -> return 0, if not same return 1
        digitalWrite(D4, HIGH);
        Serial.println("LED is ON!");
      }
      if (strcmp(data, "OFF") == 0){
        digitalWrite(D4, LOW);
        Serial.println("LED is OFF!");
      }
    }
  }
}
