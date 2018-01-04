#include <Servo.h>

#define ON HIGH
#define OFF LOW

byte receiverPin = 9;
unsigned long duration;
int pulseWidthPercentage = 0;
byte inputState = LOW;

Servo myServo;
int angle = 0;

void setup() {
  Serial.begin(9600);

  // Receives servo signal from transmitter->naze32->arduino
  pinMode(receiverPin, INPUT);

  myServo.attach(7);
  myServo.write(170); // Set servo to starting point initially
}

void loop() {
  // Reads a pulse (either HIGH or LOW) on a pin. Returns the length of
  // the pulse in microseconds or 0 if no complete pulse was received within the timeout.
  duration = pulseIn(receiverPin, HIGH); // Default timeout is 1 second
  // pulseIn should return a value somewhere between 1000 and 2000
  // In reality it can get slightly lower than 1000, in which case
  // the mapping can cause issues, so set the limits to 900 and 2100
  pulseWidthPercentage = map(duration, 900, 2100, 0, 100);

  if (pulseWidthPercentage > 50) {
    bombDrop(); 
  } else {
    bombLoad(); 
  }

  delay(100);
}

void bombDrop() {
  if (angle == 70) {
    // Scan from 70 to 170 degrees
    for (angle = 70; angle < 170; angle++) {             
      myServo.write(angle);               
      delay(15);                   
    }
  }
}

void bombLoad() { // aka grip
  if (angle != 70) {
    // Now scan back from 170 to 70 degrees
    for (angle = 170; angle > 70; angle--) {                 
      myServo.write(angle);           
      delay(15);       
    }
  }
}
