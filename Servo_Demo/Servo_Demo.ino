/*********************************
// Servo motor demonstartion program
// By Bob Davis
// July 10, 2013
// Servo Connected to Gnd, Vin, and D9
// Variable resistor on AO, high=5V and low end=Gnd
/**********************************/

#include <Servo.h> 
Servo demoservo; 
// The variable resistor is on A0
int vrpin = 0;  
int pos;    
 
void setup() 
{ 
// The servo is on pin 9  
  demoservo.attach(9);   
} 
 
void loop() 
{ 
// Read the variable resistor, 1024/5=205 degrees rotation 
// Values over 180 are ignored
  pos = analogRead(vrpin)/5;  
// send the position to the servo  
  demoservo.write(pos);                  
  delay(25);                           
} 
