#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// WiFi credentials
const char* ssid = "Naganandana"; // Replace with your WiFi SSID
const char* password = ""; // Replace with your WiFi password

// Pin configuration
#define LED_PIN D1 // LED connected to GPIO5

WiFiClient wifiClient;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient client;

  // API to fetch the LED status
  String api = "http://3.29.135.164/EXP17_AWS_server_controlled_LED.php?get_status=true";

  // Send GET request to fetch current LED status
  Serial.println("Sending GET request...");
  client.begin(wifiClient, api);
  int httpCode = client.GET(); // Get HTTP response code

  if (httpCode > 0) { // Check for valid HTTP response
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);

    String response = client.getString(); // Get the server's response
    Serial.print("Server Response: ");
    Serial.println(response);

    response.trim(); // Remove any extra whitespace

    if (response == "on") {
      digitalWrite(LED_PIN, HIGH); // Turn LED ON
      Serial.println("LED is ON");
    } else if (response == "off") {
      digitalWrite(LED_PIN, LOW); // Turn LED OFF
      Serial.println("LED is OFF");
    } else {
      Serial.println("Invalid Response! Unable to determine LED status.");
    }
  } else {
    Serial.print("HTTP Error: ");
    Serial.println(client.errorToString(httpCode)); // Print HTTP error description
  }

  client.end(); // Close the connection
  delay(5000); // Wait 5 seconds before sending the next request
}