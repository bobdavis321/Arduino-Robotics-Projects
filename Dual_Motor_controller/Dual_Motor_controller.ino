/*****************************
Motor controller demo
by Bob Davis
July 5, 2013
*****************************/
int motor1A =5;
int motor1B =6;
int motor2A =9;
int motor2B =10;
int mspeed =0;

void setup() {
pinMode(motor1A, OUTPUT);
pinMode(motor1B, OUTPUT);
pinMode(motor2A, OUTPUT);
pinMode(motor2B, OUTPUT);
}

void loop() {
// analog read is 0 to 1024, analog write is 0 to 255
mspeed=analogRead(A0)/2;
if (mspeed < 256) {
// vary the ground via PWM
  analogWrite (motor1A, mspeed);
// turn on power output
  digitalWrite(motor1B, HIGH);
}
if (mspeed > 256) {
// vary the ground via PWM
  analogWrite (motor1B, 255-mspeed);
// turn on power output
  digitalWrite(motor1A, HIGH);
}
// Motor 2
mspeed=analogRead(A1)/2;
if (mspeed < 256) {
// vary the ground via PWM
  analogWrite (motor2A, mspeed);
// turn on power output
  digitalWrite(motor2B, HIGH);
}
if (mspeed > 256) {
// vary the ground via PWM
  analogWrite (motor2B, 255-mspeed);
// turn on power output
  digitalWrite(motor2A, HIGH);
}
}
