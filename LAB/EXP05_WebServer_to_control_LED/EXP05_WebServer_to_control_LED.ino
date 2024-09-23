
#include<ESP8266WiFi.h>
char* ssid = "BITS-IOT";
char* pass = "mK7g1BB31dcz3";
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
  Serial.println("Connecting to my Network...");
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
    }
  Serial.println("WiFi is connected");
  server.begin();
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client){
  return;
  }
 Serial.println("Request receievd from the client"); 

String request = client.readStringUntil('\r');
Serial.println(request);

if(request.indexOf("/on") != -1) {
  Serial.println("LED ON");
  digitalWrite(D2,HIGH);
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
