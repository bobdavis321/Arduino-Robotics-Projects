/*****************************************
Robotics-Roomba IR Remote control of 2 wheel robot
Demonstrates the Roomba under IR wireless
Written by Bob Davis January 2014
****************************************/

// IR setup 
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

//char INBYTE;
int motor1A =6;
int motor1B =7;
int motor2A =9;
int motor2B =10;

void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Start the receiver
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value==16738455) Serial.println("1 key");
    if (results.value==16750695) Serial.println("2 key");
    if (results.value==16756815) Serial.println("3 key");
    if (results.value==16724175) Serial.println("4 key");
    if (results.value==16718055) Serial.println("5 key");
    if (results.value==16743045) Serial.println("6 key");
    if (results.value==16716015) Serial.println("7 key");    
    if (results.value==16726215) Serial.println("8 key");    
    if (results.value==16734885) Serial.println("9 key");    
    if (results.value==16730805) Serial.println("0 key");
    if (results.value==16728765) Serial.println("star key");
    if (results.value==16732845) Serial.println("pound key");
    if (results.value==16712445) Serial.println("OK key");
    if (results.value==16736925) {
      Serial.println("forward key");
      // Go forward
      digitalWrite(motor1A, HIGH);
      digitalWrite (motor1B, LOW);
      digitalWrite(motor2A, HIGH);
      digitalWrite (motor2B, LOW);
      delay(2000);
    }
    if (results.value==16761405) {
      Serial.println("right key");
      // Turn right
      digitalWrite(motor1A, HIGH);
      digitalWrite (motor1B, LOW);
      digitalWrite(motor2A, LOW);
      digitalWrite (motor2B, HIGH);
      delay(1000);
    }  
    if (results.value==16754775) {
      Serial.println("back key");
      // Go Backwards 
      digitalWrite(motor1A, LOW);
      digitalWrite (motor1B, HIGH);
      digitalWrite(motor2A, LOW);
      digitalWrite (motor2B, HIGH);
      delay(2000);
    }
    if (results.value==16720605) {
      Serial.println("left key");
      // Turn left
      digitalWrite(motor1A, LOW);
      digitalWrite (motor1B, HIGH);
      digitalWrite(motor2A, HIGH);
      digitalWrite (motor2B, LOW);
      delay(1000);
    } 
    // Stop all motors
    digitalWrite(motor1A, HIGH);
    digitalWrite (motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite (motor2B, HIGH);

// Next two lines are for troubleshooting so you can see the codes
//    Serial.println(results.value);
//    dump(&results);
  irrecv.resume(); // Receive the next value
  }  
}
