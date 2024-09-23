// 5th September 2024

/* PROGRAMMING A WIFI NETWORK DETECTOR USING NODEMCU */

#include<ESP8266WiFi.h>

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println("Scanning WiFi:");
  int n = WiFi.scanNetworks(); // finds the number of wifi networks around the nodemcu and saves it in 'n'
  if ( n==0 ){
    Serial.println("No networks available :(");
  }
  else{
    for (int i = 0; i < n; i++){
      Serial.print(i + 1); Serial.print(". ");
      Serial.print(WiFi.SSID(i)); // WiFi.SSID -> Wifi network name
      Serial.print("(");
      Serial.print(WiFi.RSSI(i)); // WiFi.RSSI -> Received Signal Strength Indicator
      Serial.println(")");
    }
  }

  Serial.println(" ");
  delay(5000); // delay before the program loops again
}