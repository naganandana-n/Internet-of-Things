// WEBSERVER TO CONTROL LED

#include<ESP8266WiFi.h>

char* ssid = "Naganandana"; // WIFI.BEGIN() FN NEEDS IT TO BE IN CHAR*
char* pass = ""; // these are in char* because thats how you store strings in C++

WiFiServer server(80); // WiFi server on port 80 (the default HTTP port)

void setup(){
  Serial.begin(9600);
  pinMode(D2, OUTPUT); // Led to be controlled

  Serial.println("Connecting to my network...");
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(50);
  }
  
  Serial.println("Wifi is connected!");
  server.begin(); // starts the server, allowing the ESP8266 to listen for incoming connections.
  Serial.println(WiFi.localIP()); // prints the local IP address of the ESP8266 to the Serial Monitor.
  // By printing the local IP address to the Serial Monitor, 
  // you can know which IP address to use to access the web server running on your ESP8266.
}

void loop(){
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  Serial.println("Request received from client!");

  String request = client.readStringUntil('\r'); //constructs a String until it encounters the 
  // specified delimiter character, which in this case is the carriage return (\r).
  Serial.println(request);

  if( request.indexOf("/on") != -1){
    Serial.println("LED ON");
    digitalWrite(D2, HIGH);
  }
  if( request.indexOf("/off") != -1){
    Serial.println("LED OFF");
    digitalWrite(D2, LOW);
  }

  client.println(
    "<html>"
    "<title>LED CONTROL</title><center>"
    "<h1>LED CONTROL</h1>"
    "<a href = '/on'><button>LED ON</button></a>"
    "<a href = '/off'><button>LED OFF</button></a>"
    "</center></html>"
  );
}