void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("Ultrasonic Sensor!");

pinMode(D4, OUTPUT); // trig pin
pinMode(D5, INPUT); // echo pin
}

void loop(){
// clear the trig pin
digitalWrite(D4, LOW);
delayMicroseconds(2);

// set the trig pin high for 10 microseconds
digitalWrite(D4, HIGH);
delayMicroseconds(10);
digitalWrite(D4, LOW);

// read the echo pin, gives time duration in microseconds
long duration = pulseIn(D5, HIGH); // Stores the time (in microseconds) for the ultrasonic pulse to travel to the object and back
int distance = duration * 0.034 / 2; // Speed of sound is 0.034 cm/microsecond

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

delay(500);
}