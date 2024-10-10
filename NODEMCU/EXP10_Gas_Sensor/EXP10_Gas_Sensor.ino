// Define the analog pin
int gasSensorPin = A0; // AO pin of the Flying Fish sensor connected to A0 of NodeMCU

void setup() {
  Serial.begin(9600);
  delay(2000); 
}

void loop() {
  int gasValue = analogRead(gasSensorPin);  // Read the analog value from the sensor
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);  // Print the value to the Serial Monitor
  
  // Add a small delay before reading the value again
  delay(1000); // Delay of 1 second
}