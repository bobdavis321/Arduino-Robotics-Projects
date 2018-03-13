/*********************************
// Servo motor demonstartion program 2
// By Bob Davis
// July 10, 2013
// Servo Connected to Gnd, Vin, and D9
// Variable resistor on AO, high=5V and low end=Gnd
// This demo does not use servo.h as the timing is included
/**********************************/

// The variable resistor is on A0
int vrpin = 0;  
int pos;    
 
void setup() 
{ 
// The servo is on pin 9  
  pinMode (9, OUTPUT);
} 
 
void loop() 
{ 
// Read the variable resistor, 1024*2 = 2048 = 2 milliseconds 
// add 500 as .5 is the minimum milliseconds
  pos = (analogRead(vrpin)*2)+500;  
// send the position to the servo  
  digitalWrite (9, HIGH);
  delayMicroseconds(pos);                           
  digitalWrite (9, LOW);
  delay(20);                           
} 
