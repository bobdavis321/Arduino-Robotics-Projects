#include <AFMotor.h>

AF_DCMotor motor(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm

void setup() {
  motor.setSpeed(200);     // set the speed to 200/255
}

void loop() {
  Serial.print("tick");
  
  motor.run(FORWARD);      // turn it on going forward
  delay(1000);

  Serial.print("tock");
  motor.run(BACKWARD);     // the other way
  delay(1000);
  
  Serial.print("tack");
  motor.run(RELEASE);      // stopped
  delay(1000);
}


