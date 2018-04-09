// ===========================================================
//
// Lab7_Serial.ino
// Description: Arduino outputting text to the serial monitor
// Name: Peter Fabinski
//       Ayush Rout
// Date: 2017-10-19
// Class: CMPE-110
// Section: 3, Thurs. 11AM
//
// ===========================================================

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(led, OUTPUT);
  Serial.begin(19200);
  Serial.println("Hello Serial 0");
}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on
  Serial.println("HIGH");
  delay(2000);               // wait for 2 seconds
  digitalWrite(led, LOW);    // turn the LED off
  Serial.println("LOW");
  delay(2000);               // wait for 2 seconds
}
