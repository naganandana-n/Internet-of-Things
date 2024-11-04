// Functions:
// - Wifi.scanNetworks();
// - Wifi.SSID(i)
// - Wifi.RSSI(i)
// NOTE: WiFi, not Wifi (F HAS TO BE CAPITAL !)

#include <ESP8266WiFi.h> // just follow the format of <>, don't fuck around with ""

void setup(){
delay(1000); // so that the serial monitor has time to initialize, and not print garbage
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("NodeMCU as a Wifi Scanner!");
}

void loop(){
Serial.println("Scanning for Wifi networks...");
int n = WiFi.scanNetworks();
if (n == 0){
Serial.println("No networks available!");
}
else{
for (int i = 0; i < n; i++){
Serial.print(i+1); Serial.print(". WiFi SSID: ");
Serial.print(WiFi.SSID(i));
Serial.print(" WiFi RSSI: ");
Serial.println(WiFi.RSSI(i));
}
}
Serial.println(""); // to give space between looping of program
delay(5000);
}