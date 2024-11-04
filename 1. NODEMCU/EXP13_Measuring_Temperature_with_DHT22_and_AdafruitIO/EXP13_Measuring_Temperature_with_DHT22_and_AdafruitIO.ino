#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>

DHT dht(D4, DHT22);

// Network and MQTT server credentials
#define ssid "" // WiFi SSID
#define pass "" // WiFi password
#define server "io.adafruit.com" // MQTT server (Adafruit IO)
#define port 1883 // MQTT port (default for Adafruit IO)
#define user "" // MQTT username (Adafruit IO username)
#define key "" // MQTT key (Adafruit IO Key)

// Initializing WiFi and MQTT clients
WiFiClient client; // ESP8266 WiFi client for MQTT connection
Adafruit_MQTT_Client mqtt(&client, server, port, user, key); // MQTT client setup

// MQTT topic for publishing temperature data
Adafruit_MQTT_Publish guage = Adafruit_MQTT_Publish(&mqtt, user "/feeds/temp");

// Global variable to store temperature data
float data;

// Function to connect to MQTT server
void MQTT_Connect() {
if (mqtt.connected()) {
return; // Exit if already connected to MQTT
}

Serial.println("Connecting to MQTT...");
int retries = 3, status; // Retry count for MQTT connection

// Attempting to connect to MQTT with retries
while ((status = mqtt.connect()) != 0) {
Serial.println(mqtt.connectErrorString(status)); // Print connection error
Serial.println("Retrying after 5 secs...");
delay(5000); // Wait 5 seconds before retrying
retries--;

if (retries == 0) {
while (1); // Infinite loop to stop if connection fails
}
}

Serial.println("MQTT Connected"); // Confirm successful connection
}

// Setup function to initialize serial, WiFi, and DHT sensor
void setup() {
Serial.begin(9600); // Start serial communication at 9600 baud rate
dht.begin(); // Initialize DHT sensor
Serial.println("Connecting to WiFi...");

WiFi.begin(ssid, pass); // Connect to WiFi
while (WiFi.status() != WL_CONNECTED) {
Serial.print("."); // Print dots while connecting
delay(500); // Delay for visual feedback
}
Serial.println("WiFi Connected!"); // WiFi connection successful
}

// Main loop to handle MQTT connection and data publishing
void loop() {
MQTT_Connect(); // Ensure MQTT connection

data = dht.readTemperature(); // Read temperature from DHT sensor

// Publish temperature data to Adafruit IO
if (guage.publish(data)) {
Serial.print("Data Published:"); Serial.println(data); // Confirm publish success
} else {
Serial.println("Data Failed"); // Print failure message if publish fails
}
delay(3000); // Delay for 3 seconds before the next loop iteration
}