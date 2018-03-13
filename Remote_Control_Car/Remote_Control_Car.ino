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
char INBYTE;
int  LED = 13; // LED on pin 13
int motor1A =7;
int motor1B =6;
int motor2A =9;
int motor2B =10;
int hpos = 0;
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600); 
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  lcd.clear();
}

void loop() {
//  Serial.println("Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:");
// stay here so long while COM port is empty
//  while (!Serial.available());  
// read next available byte  
  INBYTE = Serial.read();        

// Show Data
  lcd.setCursor(0,0);
  lcd.print("Data");
if (INBYTE != ' ') {
  lcd.setCursor(6+hpos, 0);
  hpos=hpos++;
  if (hpos > 10) hpos=0;
  lcd.print(INBYTE);
}
// Motor control
if (INBYTE == 'f'){
// Run straight forward
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
if (INBYTE == 'b'){
// Back up and turn
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite (motor2B, HIGH);
}
if (INBYTE == 's'){
// Back up and turn
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, HIGH);
}
if (INBYTE == 'r'){
// Back up and turn
  digitalWrite(motor1A, HIGH);
  digitalWrite (motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
if (INBYTE == 'l'){
// Back up and turn
  digitalWrite(motor1A, LOW);
  digitalWrite (motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite (motor2B, LOW);
}
  delay(500);
}

