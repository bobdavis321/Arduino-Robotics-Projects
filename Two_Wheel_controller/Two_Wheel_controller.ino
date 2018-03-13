/*****************************
Two wheel controller demo
by Bob Davis
July 5, 2013
*****************************/
int motor1A = 5;
int motor1B = 6;
int motor2A = 9;
int motor2B = 10;
int prox1 = 0;
int prox2 = 0;

void freerun() {
  analogWrite (motor1B, LOW);
  digitalWrite(motor1A, HIGH);
  analogWrite (motor2B, LOW);
  digitalWrite(motor2A, HIGH);
}

void turnleft() {
  analogWrite (motor1A, LOW);
  digitalWrite(motor1B, HIGH); 
  delay(100);
}

void turnright() {
  analogWrite (motor2A, LOW);
  digitalWrite(motor2B, HIGH); 
  delay(100);
}

void setup() {
pinMode(motor1A, OUTPUT);
pinMode(motor1B, OUTPUT);
pinMode(motor2A, OUTPUT);
pinMode(motor2B, OUTPUT);
}

void loop() {
// analog read of prox sensors
prox1 = analogRead(A0);
prox2 = analogRead(A1);
// collision likely
if (prox1 < 100) turnleft();
if (prox2 < 100) turnright();
freerun();
}
