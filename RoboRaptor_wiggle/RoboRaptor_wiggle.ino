// Robo-Raptor wiggle to swing head and tail via 1 motor

#include <AFMotor.h>
// motorr is right foot motor
// motorl is left foot motor
// motorw is motor wiggle, head and tail move together
// motorh is lift the head motor
AF_DCMotor motorr(2, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorl(4, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorw(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorh(3, MOTOR12_64KHZ); // create motor #1, 64KHz pwm

void setup() {
  motorr.setSpeed(255);     // set the speed to 255
  motorl.setSpeed(255);     // set the speed to 255
  motorw.setSpeed(255);     // set the speed to 255
  motorh.setSpeed(255);     // set the speed to 255
}

void loop() {
  motorw.run(FORWARD);      // turn motor on going forward
  delay(300);

  // pause
  motorw.run(RELEASE);      // stopped
  delay(1000);

  motorw.run(BACKWARD);     // turn motor on going the other way
  delay(300);
  
  // pause
  motorw.run(RELEASE);      // stopped
  delay(1000);
}


