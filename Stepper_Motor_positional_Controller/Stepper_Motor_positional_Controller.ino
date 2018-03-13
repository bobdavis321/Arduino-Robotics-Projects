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
// Process positive numbers by rotating clockwise  
  if (cposit > 0) {   
    for (phase=1; phase <5; phase++) {
      digitalWrite(phase+pinoffset, HIGH);
      if (phase < 4) digitalWrite(phase+1+pinoffset, HIGH);
      if (phase == 4) digitalWrite(1+pinoffset, HIGH);
// a delay of < 5 is too fast for the stepper motor  
      delay(10);
      digitalWrite(phase+pinoffset, LOW);
    }
    cposit--;
  }
// Process neagtive numbers by rotating counter clockwise  
  if (cposit < 0) {   
    for (phase=4; phase >0; phase--) {
      digitalWrite(phase+pinoffset, HIGH);
      if (phase > 1) digitalWrite(phase-1+pinoffset, HIGH);
      if (phase == 1) digitalWrite(4+pinoffset, HIGH);
// a delay of < 5 is too fast for the stepper motor  
      delay(10);
      digitalWrite(phase+pinoffset, LOW);
    }
    cposit++;
  }
}  
}
