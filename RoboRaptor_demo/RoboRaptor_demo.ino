// Robo-Raptor Demo
// demonstrates several actions the robo raptor can take.
// Written December 2013 by Bob Davis

#include <AFMotor.h>
// motorw is motor wiggle, head and tail move together
AF_DCMotor motorr(2, MOTOR12_64KHZ); 
// create motor #2, 64KHz pwm
AF_DCMotor motorl(4, MOTOR12_64KHZ); 
// create motor #4, 64KHz pwm
AF_DCMotor motorw(1, MOTOR12_64KHZ); 
// create motor #1, 64KHz pwm
AF_DCMotor motorh(3, MOTOR12_64KHZ); 
// create motor #3, 64KHz pwm
char INBYTE;
// Set A6 as an output pin for speaker
int SpkrPin = 19;
int roar;

void setup() {
  motorr.setSpeed(255);     // set the speed to 255/255
  motorl.setSpeed(255);     // set the speed to 255/255
  motorw.setSpeed(255);     // set the speed to 255/255
  motorh.setSpeed(255);     // set the speed to 255/255
  pinMode(SpkrPin, OUTPUT);
}

void loop() {
  
  // Sequence of Motor control comands
  // wiggle tail
  // lower head
  // walk forward
  // make a roaring sound  
 
  // Wait for tail switch to start demo
  while (analogRead(A0) != '0'){}
    
  // wiggle tail
  motorw.run(BACKWARD);    // wiggle right
  delay(300);  // pause
  motorw.run(RELEASE);     // stopped
  delay(500);
  motorw.run(FORWARD);     // wiggle left
  delay(300);  // pause
  motorw.run(RELEASE);     // stopped
  delay(500);

  // lower head
  motorh.run(BACKWARD);     // raise head
  delay(500);  // pause
  motorh.run(RELEASE);     // stopped
  delay(500);
    
  // walk straight forward
  motorr.run(FORWARD);     // right foot forward
  delay(300);  // pause
  motorr.run(RELEASE);     // stopped
  delay(500);
  motorl.run(FORWARD);     // move left foot forward
  delay(300);  // pause
  motorl.run(RELEASE);     // stopped
  delay(500);
  motorr.run(FORWARD);     // right foot forward
  delay(300);  // pause
  motorr.run(RELEASE);     // stopped
  delay(500);
  motorl.run(FORWARD);     // move left foot forward
  delay(300);  // pause
  motorl.run(RELEASE);     // stopped
  delay(500);

  // roar
  for (roar=0; roar < 100; roar++) {
    digitalWrite(SpkrPin, HIGH);   // sets the speaker on
    delay(5);        // waits for a fraction of a second
    digitalWrite(SpkrPin, LOW);    // sets the speaker off
    delay(5);        // waits for a fraction of a second
  }
}


