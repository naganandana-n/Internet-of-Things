void setup(){
Serial.begin(9600);
delay(1000);
Serial.println("");
Serial.println("Gas sensor!");
Serial.println("");

pinMode(A0, INPUT); // check whether you have to do this or not!!
}

void loop(){
int gas_sensor = analogRead(A0);
Serial.print("Gas sensor reading: ");
Serial.println(gas_sensor);

delay(1000);
}