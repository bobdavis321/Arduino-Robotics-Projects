/*****************************************
Robotics-Remote control 2 wheel robot
Demonstrates thw use of serial control
This sketch displays two ranges on the LCD

The serial commands:
 f=forward
 b=back up
 r=right
 l=left
 s=stop

Written by Bob Davis
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
  INBYTE = Serial.read();        
// Motor control
if (INBYTE == 'f'){
// Run straight forward
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
if (INBYTE == 'b'){
// Back up 
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
}
if (INBYTE == 's'){
// stop all motors
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, HIGH);
}
if (INBYTE == 'r'){
// Back up and turn
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
}
if (INBYTE == 'l'){
// Back up and turn
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
  delay(500);
}

