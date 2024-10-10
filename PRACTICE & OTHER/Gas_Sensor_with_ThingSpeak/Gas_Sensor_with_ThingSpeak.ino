#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak credentials
unsigned long myChannelNumber = 2666095; // Replace with your ThingSpeak Channel ID
const char* myWriteAPIKey = "FGPNF1458Z7PA52F"; // Replace with your Write API Key

WiFiClient client;

int gasSensorPin = A0;  // AO pin of the gas sensor connected to A0 on NodeMCU

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  WiFi.begin(ssid, password);  // Connect to Wi-Fi
  
  // Wait for Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  int gasValue = analogRead(gasSensorPin);  // Read the analog value from the sensor
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);  // Print the value to the Serial Monitor

  // Write value to ThingSpeak
  ThingSpeak.setField(1, gasValue);  // Set Field 1 with the gas sensor value
  
  int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (responseCode == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.print("Error sending data to ThingSpeak. HTTP error code: ");
    Serial.println(responseCode);
  }

  delay(20000);  // ThingSpeak allows updates every 15 seconds, so use a delay of at least 20 seconds
}