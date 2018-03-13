/*****************************************
Robotics-Roomba Roamer controls 2 wheel robot
Demonstrates the Roomba doing a demo

The sequence of commands:
 f=forward
 b=back up
 r=right
 l=left
 s=stop

Written by Bob Davis January 2014
****************************************/
 
char INBYTE;
int motor1A =6;
int motor1B =7;
int motor2A =9;
int motor2B =10;

void setup() {
  Serial.begin(9600); 
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
// read next available byte  
//  INBYTE = Serial.read();        

// Wait for tail switch to start demo
  while (analogRead(A0) > 10){}

// Run straight forward
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
  delay(2000);
// Run Backwards 
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
  delay(2000);
// Turn right
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
  delay(2000);
// Turn left
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
  delay(2000);
// Stop all motors
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, HIGH);
}

