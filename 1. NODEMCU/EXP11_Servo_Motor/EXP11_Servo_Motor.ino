#include <Servo.h>

Servo myServo; // Create a Servo object

int servoPin = D4; // Define the servo control pin

void setup() {
Serial.begin(9600); // Initialize serial communication for debugging
myServo.attach(servoPin); // Attach the servo on the selected pin
}

void loop() {
// Rotate the servo from 0 to 180 degrees
for (int pos = 0; pos <= 180; pos += 1) {
myServo.write(pos); // Set the servo position
delay(15); // Wait for the servo to reach the position
}

// Rotate the servo from 180 to 0 degrees
for (int pos = 180; pos >= 0; pos -= 1) {
myServo.write(pos); // Set the servo position
delay(15); // Wait for the servo to reach the position
}
}