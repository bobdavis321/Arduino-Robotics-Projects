/*****************************************
Robotics-Roomba Roamer controls 2 wheel robot
Demonstrates the Roomba and ultrasonic distance sensing

The sequence of commands:
  Check for collision?
  if not: forward
  else: back up, 
    turn right, stop, check distance
    turn left, stop, check distance
    if right distance was better turn right

echo is on pin 16 (A2)
trigger is on pin 17 (A3)

Written by Bob Davis January 2014
****************************************/
 
int motor1A =6;
int motor1B =7;
int motor2A =9;
int motor2B =10;
#define echoPin 16
#define trigPin 17
int distance=10;
int distanceR=10;
int distanceL=10;

void setup() {
//  Serial.begin(9600); 
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
// Wait for the switch to start demo
// Used for debugging the sketch
// while (analogRead(A0) > 10){}
  
// Stop all motors
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, HIGH);
// send out ultrasonic ping
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Wait for response back
  distance=pulseIn(echoPin, HIGH);
  
  if (distance > 2000){
// Run straight forward
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite (motor2B, LOW);
    delay(1000);
    }
  else {
// Back up a little 
    digitalWrite(motor1A, LOW);
    digitalWrite (motor1B, HIGH);
    digitalWrite(motor2A, LOW);
    digitalWrite (motor2B, HIGH);
    delay(200);
// Turn right
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite (motor2B, HIGH);
    delay(800);
// Stop all motors
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite (motor2B, HIGH);
// send out ultrasonic ping to check distance
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
// Wait for response back
    distanceR=pulseIn(echoPin, HIGH);
// Turn left
    digitalWrite(motor1A, LOW);
    digitalWrite (motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite (motor2B, LOW);
    delay(1600);
// Stop all motors
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite (motor2B, HIGH);
// send out ultrasonic ping to check distance
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
// Wait for response back
    distanceL=pulseIn(echoPin, HIGH);
    if (distanceL < distanceR){
// Go back to the right
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite (motor2B, HIGH);
    delay(1600);
    }
  }
}

