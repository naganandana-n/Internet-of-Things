// Pin Definitions
const int IR_SENSOR_PIN = D1;  // Pin where the IR sensor's output is connected
const int LED_PIN = D4;        // Optional LED to indicate detection (onboard LED)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Set the IR sensor pin as input
  pinMode(IR_SENSOR_PIN, INPUT);

  // Set the onboard LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Initially turn off the LED
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Read the IR sensor value
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  // Check if an object is detected
  if (sensorValue == LOW) {  // Usually, IR sensor outputs LOW when an object is detected
    Serial.println("Object detected! \n");
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
  } else {
    Serial.println("No object detected. \n");
    digitalWrite(LED_PIN, LOW);   // Turn off the LED
  }

  // Small delay to avoid overwhelming the serial output
  delay(200);
}