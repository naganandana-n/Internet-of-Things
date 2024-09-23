/* CODE TO MAKE YELLOW AND RED LIGHTS BLINK ALTERNATIVELY */

# define yellow D4
# define red D0

void setup() { // HERE YOU DEFINE YOUR OUTPUT PORTS
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() { // HERE YOU TELL WHAT YOU WANT IG
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  delay(1000);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(1000);
}
