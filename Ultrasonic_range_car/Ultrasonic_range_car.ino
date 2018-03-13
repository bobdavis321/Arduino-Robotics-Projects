/*****************************************
Robotics-Ultrasonic Range Car
Demonstrates use of 16x2 LCD and HC-SR04 ultrasonic range
This sketch displays two ranges on the LCD
 
   The LCD circuit:
 * LCD RS to D 12, En to D 11
 * LCD D4-D7 to D 5-2
 * LCD R/W pin to ground
 * Variable resistor wiper to LCD VO pin (pin 3)
   The Ultrasonic Circuit
 * Echo on pin 14 (A0)
 * Trig on pin 15 (A1)
 * Echo2 on pin 16 (A2)
 * Trig2 on pin 17 (A3)
 
Adapted from code written by David A. Mellis
Modified by Limor Fried, Tom Igoe, Bob Davis
****************************************/
 
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with interface pin #'s
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define echoPin 14 // Echo Pin
#define trigPin 15 // Trigger Pin
#define echoPin2 16 // Echo Pin 2
#define trigPin2 17 // Trigger pin 2
int durationR;
int distanceR; // used to calculate right distance
int durationL;
int distanceL; // used to calculate left distance
int motor1A =7;
int motor1B =6;
int motor2A =9;
int motor2B =10;
int mspeed =0;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
// Send out ultrasonic sound  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
// Wait for response back
  durationR = pulseIn(echoPin, HIGH);
//Calculate the distance in inches.
  distanceR = durationR/148;
//  delay(100);
  
// Second Ultrasonic ping
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
// Wait for response back
  durationL = pulseIn(echoPin2, HIGH);
//Calculate the distance in inches.
  distanceL = durationL/148;
// Display the results
  lcd.clear();
// Right Range
  lcd.setCursor(0,0);
  lcd.print("R Range:");
  lcd.setCursor(10, 0);
  lcd.print(distanceR);
// Left range
  lcd.setCursor(0,1);
  lcd.print("L Range:");
  lcd.setCursor(10, 1);
  lcd.print(distanceL);
  
// Motor control
if (distanceL > 20){
// Run straight forward
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
else {
// Back up and turn
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
}
  delay(500);
}

