#include<ESP8266WiFi.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Scanning Wifi....");
  int n = WiFi.scanNetworks();
  if(n==0){
      Serial.println("No Networks Available");
    }
  else{
      for(int i=0;i<n; i++){
          Serial.print(i+1); Serial.print(". ");
          Serial.print(WiFi.SSID(i));
          Serial.print("(");
          Serial.print(WiFi.RSSI(i));
          Serial.println(")");
        }
    }
    Serial.println(" ");
    delay(5000);
}
