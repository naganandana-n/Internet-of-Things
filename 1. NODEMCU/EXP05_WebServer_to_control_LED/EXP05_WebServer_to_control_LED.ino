// MAKE SURE COMPUTER AND ESP8266 ARE ON THE SAME WIFI!!!!

#include<ESP8266WiFi.h>

char* ssid = "Naganandana";
char* pass = "";

WiFiServer server(80); // creates a server on port 80 (HTTP port) for handling web requests.

void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("Webserver to control LED!");

pinMode(D2, OUTPUT);

// Connecting to WiFi:
Serial.print("Connecting to WiFi...");
WiFi.begin(ssid, pass);
while(WiFi.status() != WL_CONNECTED){
Serial.print(".");
delay(500);
}
Serial.println("");
Serial.println("WiFi Connected!");

server.begin(); // starts the server
Serial.println(WiFi.localIP()); // retrieves and prints the local IP address of the ESP8266,
// which is useful for accessing the web server.
}

void loop(){
WiFiClient client = server.available(); // checks for incoming client connections
if (!client){
return; // If no client is available, it exits loop() using return;
}

Serial.println("Request received from client!");
String request = client.readStringUntil('\r'); // Reads the client's request until the carriage return character (\r)
Serial.println(request);

if(request.indexOf("/on") != -1){
Serial.println("LED ON");
digitalWrite(D2, HIGH);
}
if(request.indexOf("/off") != -1) {
Serial.println("LED OFF");
digitalWrite(D2,LOW);
}

client.println("<html><title>LED Control</title><center>");
client.println("<h1>LED Control</h1>");
client.println("<a href = '/on'><button>LED ON</button></a>");
client.println("<a href = '/off'><button>LED OFF</button></a>");
client.println("</center></html>");
}