// Connections:
// - Longer wire of LED to the GPIO pin
// - Shorter wire to the ground (GND)
// - For multiple LEDs you can use the last line of breadboard
// as the ground (use wire to make it ground)

// Note:
// - incase you don't have another LED
// - ONBOARD LED ON NODEMCU:
// - PIN D4 !!
// - D4 -> FUNCTION'S ON ACTIVE LOW (HIGH = OFF, LOW = ON)

#define red D4 // port for red led
#define yellow D3 // port for yellow led

void setup() {
Serial.begin(9600);
Serial.println("Making 2 led's blink alternatively!");

pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
}

void loop() {
digitalWrite(red, LOW);
digitalWrite(yellow, LOW);

delay(1000);
