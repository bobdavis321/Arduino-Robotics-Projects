/*****************************
Motor controller demo
by Bob Davis
July 5, 2013
*****************************/
int motor1 =9;
int motor2 =10;
int mspeed =0;

void setup() {
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
}

void loop() {
// analog read is 0 to 1024, analog write is 0 to 255
mspeed=analogRead(A0)/2;
if (mspeed < 256) {
// vary the ground via PWM
  analogWrite (motor1, mspeed);
// turn on power output
  digitalWrite(motor2, HIGH);
}
if (mspeed > 256) {
// vary the ground via PWM
  analogWrite (motor2, 255-mspeed);
// turn on power output
  digitalWrite(motor1, HIGH);
}
}
