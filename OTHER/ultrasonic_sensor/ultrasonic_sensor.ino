// Pin definition
const int trigPin = D5;
const int echoPin = D6;

// Variables to store duration and distance
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Set trigPin as an OUTPUT and echoPin as an INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the time (duration) in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;  // Speed of sound is 0.034 cm/microsecond

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Small delay to avoid flooding the serial output
  delay(500);
}