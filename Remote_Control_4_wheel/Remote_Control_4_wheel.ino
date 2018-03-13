/*****************************************
Robotics-Remote control 4 wheel robot
Demonstrates the use of serial control

The serial commands:
 f=forward
 b=back up
 r=right
 l=left
 s=stop

Written by Bob Davis
****************************************/
#include <AFMotor.h>
// motors are connected in a circle like a clock
// motor 1 is right front
// motor 2 is right back
// motor 3 is left back
// motor 4 is left front
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
  motor3.setSpeed(255); 
  motor4.setSpeed(255); 
}

void loop() {
// read next available byte  
  int INBYTE = Serial.read();        
// Motor control
  if (INBYTE == 'f'){
// Run straight forward
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  }
  if (INBYTE == 'b'){
// Back up 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  }
  if (INBYTE == 's'){
// stop all motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
  if (INBYTE == 'l'){
// turn left
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(300);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
  if (INBYTE == 'r'){
// turn right
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(300);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}

