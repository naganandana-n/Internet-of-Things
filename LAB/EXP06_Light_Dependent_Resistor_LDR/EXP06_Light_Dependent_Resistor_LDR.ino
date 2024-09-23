void setup() {
   pinMode(A0,INPUT);
   Serial.begin(9600);
   pinMode(D2,OUTPUT);
}

void loop() {
   int data = analogRead(A0);
   Serial.println(data);
   if(data < 50){
      digitalWrite(D2,HIGH);
    }
   else{
      digitalWrite(D2,LOW);
    }
   delay(500);
}
