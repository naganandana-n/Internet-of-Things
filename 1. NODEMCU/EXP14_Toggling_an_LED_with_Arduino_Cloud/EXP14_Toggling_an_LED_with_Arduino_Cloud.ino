// MAKE THESE CHANGES TO THE PREWRITTEN CODE

// add this to void setup
void setup() {
pinMode (D2, OUTPUT);

/*
Since Led is READ_WRITE variable, onLedChange() is
executed every time a new value is received from IoT Cloud.
*/
void onLedChange() {
// Add your code here to act upon Led change
if (led == 1){
digitalWrite(D2, HIGH);
}
else{
digitalWrite(D2, LOW);
}
}