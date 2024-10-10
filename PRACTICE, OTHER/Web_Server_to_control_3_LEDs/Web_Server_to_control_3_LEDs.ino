#include<ESP8266WiFi.h>

char* ssid = "Naganandana";  // Your WiFi SSID
char* pass = "";             // Your WiFi password

WiFiServer server(80);

// Define LED pins
int led1 = D0;
int led2 = D2;
int led3 = D3;

void setup() {
  Serial.begin(9600);

  // Set LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Initialize all LEDs as OFF
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  Serial.println("Connecting to my Network...");
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
  }
  
  Serial.println("\nWiFi is connected");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (!client) {
    return;
  }

  Serial.println("Request received from the client");

  // Read the request from the client
  String request = client.readStringUntil('\r');
  Serial.println(request);

  // Control LED 1
  if (request.indexOf("/led1on") != -1) {
    Serial.println("LED 1 ON");
    digitalWrite(led1, HIGH);
  }
  if (request.indexOf("/led1off") != -1) {
    Serial.println("LED 1 OFF");
    digitalWrite(led1, LOW);
  }

  // Control LED 2
  if (request.indexOf("/led2on") != -1) {
    Serial.println("LED 2 ON");
    digitalWrite(led2, HIGH);
  }
  if (request.indexOf("/led2off") != -1) {
    Serial.println("LED 2 OFF");
    digitalWrite(led2, LOW);
  }

  // Control LED 3
  if (request.indexOf("/led3on") != -1) {
    Serial.println("LED 3 ON");
    digitalWrite(led3, HIGH);
  }
  if (request.indexOf("/led3off") != -1) {
    Serial.println("LED 3 OFF");
    digitalWrite(led3, LOW);
  }

  // Send an HTML response to the client
  client.println("<html><title>3 LED Control</title><center>");
  client.println("<h1>LED Control</h1>");
  
  client.println("<h2>LED 1</h2>");
  client.println("<a href='/led1on'><button>LED 1 ON</button></a>");
  client.println("<a href='/led1off'><button>LED 1 OFF</button></a>");

  client.println("<h2>LED 2</h2>");
  client.println("<a href='/led2on'><button>LED 2 ON</button></a>");
  client.println("<a href='/led2off'><button>LED 2 OFF</button></a>");

  client.println("<h2>LED 3</h2>");
  client.println("<a href='/led3on'><button>LED 3 ON</button></a>");
  client.println("<a href='/led3off'><button>LED 3 OFF</button></a>");

  client.println("</center></html>");

  // Close the connection
  client.stop();
}