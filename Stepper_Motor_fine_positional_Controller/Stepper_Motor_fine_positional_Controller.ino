/*****************************
Stepper Motor positional Controller demo
by Bob Davis
July 5, 2013
*****************************/
int motor1 = 1;
int motor2 = 2;
int motor3 = 3;
int motor4 = 4;
int mposit = 0;
int oldposit = 0;
int cposit = 0;
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
// analog read / 20.48, leaves 50 x 4 phases
// = 200 steps or 1 complete revolution
mposit = analogRead(A0)/20.48;
cposit = mposit-oldposit;
oldposit = mposit;

while (cposit != 0) {
  if (cposit > 0) phase = 4;
  if (cposit < 0) phase = 1;
  while (phase != 0) {  
    digitalWrite(phase+pinoffset, HIGH);
//    if (phase == 1) digitalWrite(4+pinoffset, HIGH);
//    if (phase == 2) digitalWrite(3+pinoffset, HIGH);
//    if (phase == 3) digitalWrite(4+pinoffset, HIGH);
//    if (phase == 4) digitalWrite(1+pinoffset, HIGH);
// a delay of < 5 is too fast for the stepper motor  
    delay(10);
    digitalWrite(phase+pinoffset, LOW);
//    digitalWrite(1+pinoffset, LOW);
//    digitalWrite(2+pinoffset, LOW);
//    digitalWrite(3+pinoffset, LOW);
//    digitalWrite(4+pinoffset, LOW);
    if (cposit > 0) { cposit--; phase--; }
    if (cposit < 0) { cposit++; phase++; }
    if (phase == 4) phase=0;
  }
}  
}
