/*****************************
Four wire stepper motor demo
by Bob Davis
February 5, 2014
*****************************/
int motor1A =6;
int motor1B =7;
int motor1C =9;
int motor1D =10;
int mspeed =0;

void setup() {
pinMode(motor1A, OUTPUT);
pinMode(motor1B, OUTPUT);
pinMode(motor1C, OUTPUT);
pinMode(motor1D, OUTPUT);
}

void loop() {
// analog read is from 0 to 1024
mspeed=(analogRead(A0)/5);
  digitalWrite (motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite (motor1C, HIGH);
  digitalWrite(motor1D, LOW);
delay(mspeed);
  digitalWrite (motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite (motor1C, LOW);
  digitalWrite(motor1D, HIGH);
delay(mspeed);
  digitalWrite (motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite (motor1C, LOW);
  digitalWrite(motor1D, HIGH);
delay(mspeed);
  digitalWrite (motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite (motor1C, HIGH);
  digitalWrite(motor1D, LOW);
delay(mspeed);
}
