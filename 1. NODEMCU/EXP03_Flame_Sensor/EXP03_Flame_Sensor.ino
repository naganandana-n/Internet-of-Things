void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("Flame sensor!");
Serial.println("");

pinMode(D4, INPUT); // flame sensor
pinMode(D2, OUTPUT); // LED
}

void loop(){
int flame_sensor = digitalRead(D4);

Serial.print("Flame sensor reading: ");
Serial.println(flame_sensor);

if (flame_sensor == 0){ // if 0, then flame is there
digitalWrite(D2, HIGH);
}
else{
digitalWrite(D2, LOW);
}
}