
int flame_sensor_read;
void setup() {
  // put your setup code here, to run once:
pinMode(D4, INPUT);
pinMode(D2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
flame_sensor_read = digitalRead(D4);
Serial.print("Flame Status:");
Serial.println(flame_sensor_read);
if (flame_sensor_read == 0)
    {
    digitalWrite(D2, HIGH);
    }
  else
      {
      digitalWrite(D2, LOW);
      }
      
    
}
