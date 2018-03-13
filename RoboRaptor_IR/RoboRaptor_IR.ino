/*****************************************
Robotics-RoboRaptor IR Remote control 
Demonstrates the RoboRaptor under IR control
Written by Bob Davis February 2014
  // Motor control commands
  // ^ = walk forward
  // v = walk backwards
  // > = walk to the right
  // < = walk to the left
  // 1,4 left leg front, back
  // 3,6 right leg front, back
  // 2 = raise head
  // 5 = wiggle neck
  // 7 = wiggle tail left
  // 8 = lower head
  // 9 = wiggle tail right
  // OK = roaring sound
****************************************/

#include <AFMotor.h>
// motorr #2 moves right foot
AF_DCMotor motorr(2, MOTOR12_64KHZ); 
// motorl #4 moves left foot
AF_DCMotor motorl(4, MOTOR34_64KHZ); 
// motorw #1 wiggle, head and tail move together
AF_DCMotor motorw(1, MOTOR12_64KHZ); 
// motorh #3 moves the head up and down
AF_DCMotor motorh(3, MOTOR34_64KHZ); 
// set A6 as an output pin for speaker
int SpkrPin = 19;
// set A5 as neck motor output
int motorn = 18;
int roar;
// set up to overide motor enables
int D3 = 3;
int D5 = 5;
int D6 = 6;
int D11 = 11;
// IR setup must load this AFTER AFMotor!
#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); 
  motorr.setSpeed(255);  // set the speed to 255/255
  motorl.setSpeed(255);  // set the speed to 255/255
  motorw.setSpeed(255);  // set the speed to 150/255
  motorh.setSpeed(255);  // set the speed to 255/255
  // IRremote causes motors to turn off so I will force them on
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D11, OUTPUT);
  
  pinMode(SpkrPin, OUTPUT);
  pinMode(motorn, OUTPUT);
  irrecv.enableIRIn();   // Start the receiver
}

void loop() {
  digitalWrite(D3, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D11, HIGH);
  if (irrecv.decode(&results)) {
    if (results.value==16738455) {
      Serial.println("1 key");
  // left foot forward
  motorl.run(FORWARD);     
  delay(100);  // pause
  motorl.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16750695) {
      Serial.println("2 key");
  // raise head
  motorh.run(FORWARD);      // raise head
  delay(300);  // pause
  motorh.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16756815) {
      Serial.println("3 key");
  // right foot forward
  motorr.run(FORWARD);     
  delay(100);  // pause
  motorr.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16724175) {
      Serial.println("4 key");
  // left foot back
  motorl.run(BACKWARD);     
  delay(100);  // pause
  motorl.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16718055) {
      Serial.println("5 key");
  // wiggle neck motor
  digitalWrite(motorn, HIGH);
  delay(300);
  digitalWrite(motorn, LOW);
  delay(100);
    }      
    if (results.value==16743045) {
      Serial.println("6 key");
  // right leg back
  motorr.run(BACKWARD);   
  delay(100);  // pause
  motorr.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16716015) {
      Serial.println("7 key");    
  // wiggle tail left
  motorw.run(BACKWARD);      // wiggle left
  delay(300);  // pause
  motorw.run(RELEASE);      // stopped
  delay(100);
    }
    if (results.value==16726215) {
      Serial.println("8 key");    
  // lower head
  motorh.run(BACKWARD);      // lower head
  delay(300);  // pause
  motorh.run(RELEASE);      // stopped
  delay(100);
    }      
    if (results.value==16734885) {
      Serial.println("9 key");    
  // wiggle tail right
  motorw.run(FORWARD);      // wiggle right
  delay(300);   // pause
  motorw.run(RELEASE);      // stopped
  delay(100);
    }      
    if (results.value==16730805) {
      Serial.println("0 key");
    }
    if (results.value==16728765) {
      Serial.println("star key");
    }
    if (results.value==16732845) {
      Serial.println("pound key");
    }
    if (results.value==16712445) {
      Serial.println("OK key");
    // roaring sound
    for (roar=200; roar > 0; roar--) {
      digitalWrite(SpkrPin, HIGH);   // sets the speaker on
      delay(random(10));        // waits for a fraction of a second
      digitalWrite(SpkrPin, LOW);    // sets the speaker off
      delay(random(10));        // waits for a fraction of a second
      }
    }      
    if (results.value==16736925) {
      Serial.println("forward key");
      // Go forward
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);  // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorw.run(RELEASE);     // stopped
  delay(300);
    }
    if (results.value==16761405) {
      Serial.println("right key");
      // Turn right
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(400);  // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorw.run(RELEASE);     // stop wiggle
    }  
    if (results.value==16754775) {
      Serial.println("back key");
      // Go Backwards 
  motorw.run(BACKWARD);    // wiggle left
  delay(300);  // pause
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);  // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorw.run(RELEASE);     // stopped
  delay(300);
    }
    if (results.value==16720605) {
      Serial.println("left key");
      // Turn left
  motorr.run(FORWARD);     // right foot forward
  delay(100);  // pause
  motorw.run(BACKWARD);    // wiggle left
  delay(400);   // pause
  motorr.run(BACKWARD);    // right foot backward
  delay(100);  // pause
  motorr.run(RELEASE);     // stop right foot
  motorl.run(FORWARD);     // left foot forward
  delay(100);  // pause
  motorw.run(FORWARD);     // wiggle right
  delay(100);   // pause
  motorl.run(BACKWARD);    // left foot backward
  delay(100);  // pause
  motorl.run(RELEASE);     // stop left foot
  motorw.run(RELEASE);     // stop wiggle
     } 

// Next two lines are for troubleshooting so you can see the codes
    Serial.println(results.value);
//    dump(&results);
  irrecv.resume(); // Receive the next value
  }  
}


