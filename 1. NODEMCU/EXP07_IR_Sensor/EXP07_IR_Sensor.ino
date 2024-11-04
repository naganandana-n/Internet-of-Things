void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("IR Sensor!");
Serial.println("");

pinMode(D1, INPUT); // IR sensor
pinMode(D7, OUTPUT); // LED

digitalWrite(D7, LOW); // Initially LED has to be OFF
}

void loop(){
int ir_sensor = digitalRead(D1);

if (ir_sensor == LOW){ // Usually, IR sensor outputs LOW when an object is detected
digitalWrite(D7, HIGH);
Serial.println("Object DETECTED!!!");
}
else{
digitalWrite(D7, LOW);
Serial.println("Object not detected");
}

delay(500);
}