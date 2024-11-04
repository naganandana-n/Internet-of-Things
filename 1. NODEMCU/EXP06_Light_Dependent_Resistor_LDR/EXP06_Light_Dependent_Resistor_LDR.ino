// I THINK THIS CONNECTION USES RESISTOR (CHECK)!!!

void setup(){
delay(1000);
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("LDR - Light Dependent Resistor!");
Serial.println("");

pinMode(A0, INPUT); // LDR
pinMode(D2, OUTPUT); // LED
}

void loop(){
int data = analogRead(A0);
Serial.print("LDR sensor reading: ");
Serial.println(data);

if (data < 50){
digitalWrite(D2, HIGH); // turn on LED if reading less than 50 (very dark)
}
else{
digitalWrite(D2, LOW);
}

delay(500);
}