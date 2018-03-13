/*****************************
Stepper Motor Controller demo
by Bob Davis
July 5, 2013
*****************************/
int motor1 = 1;
int motor2 = 2;
int motor3 = 3;
int motor4 = 4;
int mspeed = 0;
int phase = 0;
//  allow redefining of pins
int pinoffset = motor1-1;

void setup() {
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(motor3, OUTPUT);
pinMode(motor4, OUTPUT);
}

void loop() {
// analog read is 0 to 1024, that is very slow
mspeed=analogRead(A0);
for (phase=1; phase <5; phase++) {
  digitalWrite(phase+pinoffset, HIGH);
  if (phase < 4) digitalWrite(phase+1+pinoffset, HIGH);
  if (phase == 4) digitalWrite(1+pinoffset, HIGH);
// a delay of < 5 is too fast for the stepper motor  
  delay(mspeed + 5);
  digitalWrite(phase+pinoffset, LOW);
}
}
