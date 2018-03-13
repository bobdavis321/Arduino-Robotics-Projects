// Robo-Raptor walk to walk via motors 2 and 4

#include <AFMotor.h>
// motorw is motor wiggle, head and tail move together
AF_DCMotor motorr(2, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorl(4, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorw(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorh(3, MOTOR12_64KHZ); // create motor #1, 64KHz pwm

void setup() {
  motorr.setSpeed(255);     // set the speed to 200/255
  motorl.setSpeed(255);     // set the speed to 200/255
  motorw.setSpeed(255);     // set the speed to 200/255
  motorh.setSpeed(255);     // set the speed to 200/255
}

void loop() {
  motorr.run(FORWARD);      // right foot forward
  delay(300);

  // pause
  motorr.run(RELEASE);      // stopped
  delay(1000);

  motorl.run(FORWARD);     // move left foot forward
  delay(300);
  
  // pause
  motorl.run(RELEASE);      // stopped
  delay(1000);
}


