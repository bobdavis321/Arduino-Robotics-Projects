// Robo-Raptor serial 
// responds to serial commands via USB or Bluetooth
// Written December 2013 by Bob Davis
  // Motor control commands
  // b = walk backwards
  // f = walk forward
  // h = raise head
  // l = lower head
  // w = wiggle tail
  // r = roar sound
  // m = open mouth
  // n = wiggle neck
  // D9 is servo 1 
  // labeled as servo 2 on circuit board.

#include <AFMotor.h>
#include <Servo.h> 
// create servo object to control a servo  
Servo myservo;  
// motorr moves right foot
// create motor #2, 64KHz pwm
AF_DCMotor motorr(2, MOTOR12_64KHZ); 
// motorl moves left foot
// create motor #4, 64KHz pwm
AF_DCMotor motorl(4, MOTOR34_64KHZ); 
// motorw is motor wiggle, head and tail move together
// create motor #1, 64KHz pwm
AF_DCMotor motorw(1, MOTOR12_64KHZ); 
// motorh moves the head
// create motor #3, 64KHz pwm
AF_DCMotor motorh(3, MOTOR34_1KHZ); 
char INBYTE;
// set A6 as an output pin for speaker
int SpkrPin = 19;
// set A5 as neck motor output
int motorn = 18;
int roar;

void setup() {
  motorr.setSpeed(255);     // set the speed to 255/255
  motorl.setSpeed(255);     // set the speed to 255/255
  motorw.setSpeed(255);     // set the speed to 150/255
  motorh.setSpeed(255);     // set the speed to 255/255
  Serial.begin(9600); 
  pinMode(SpkrPin, OUTPUT);
  pinMode(motorn, OUTPUT);
  // The servo is on pin 9  
  myservo.attach(9);  

}

void loop() {
  // read next available byte  
  INBYTE = Serial.read();        

  if (INBYTE == 'n'){
  // wiggle neck motor
  digitalWrite(motorn, HIGH);
  delay(300);
  digitalWrite(motorn, LOW);
  delay(300);
  }
  
  if (INBYTE == 'm'){
  // open mouth
  myservo.write(0);  
  delay(300);
  myservo.write(90);  
  delay(300);
  }

  if (INBYTE == 'b'){
  // walk straight backward
  motorw.run(BACKWARD);    // wiggle left
  delay(300);  // pause
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
//  delay(300);  // pause
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
//  delay(300);  // pause 
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);  // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
//  delay(300);  // pause
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
//  delay(300);  // pause 
  motorw.run(RELEASE);     // stopped
  delay(300);
  }

  if (INBYTE == 'f'){
  // walk straight forward
//  motorw.run(FORWARD);     // wiggle right
//  delay(300);  // pause
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
//  delay(300);  // pause
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
//  delay(300);  // pause 
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);  // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
//  delay(300);  // pause
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
//  delay(300);  // pause 
  motorw.run(RELEASE);     // stopped
  delay(300);
  }
  
  if (INBYTE == 'h'){
  // raise head
  motorh.run(FORWARD);      // raise head
  delay(800);  // pause
  motorh.run(RELEASE);      // stopped
  delay(300);
  }

  if (INBYTE == 'l'){
  // lower head
  motorh.run(BACKWARD);      // lower head
  delay(300);  // pause
  motorh.run(RELEASE);      // stopped
  delay(300);
  }

  if (INBYTE == 'w'){
  // wiggle tail
  motorw.run(FORWARD);      // wiggle right
  delay(300);   // pause
  motorw.run(RELEASE);      // stopped
  delay(300);
  motorw.run(BACKWARD);      // wiggle left
  delay(300);  // pause
  motorw.run(RELEASE);      // stopped
  delay(300);
  }

  if (INBYTE == 'r'){     // roar
  for (roar=200; roar > 0; roar--) {
    digitalWrite(SpkrPin, HIGH);   // sets the speaker on
    delay(random(10));        // waits for a fraction of a second
    digitalWrite(SpkrPin, LOW);    // sets the speaker off
    delay(random(10));        // waits for a fraction of a second
  }
  }
}


