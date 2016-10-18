/* Define the Pins for each motor */
#define RB 12 //IA1
#define RA 11 //IA2
#define LB 10 //IB2
#define LA 9  //IB1

#define trig 4
#define echo 3

void setup() {
  //Declare all the output pins as outputs...
  for (int i = trig; i < RB + 1; i++) {
    pinMode(i, OUTPUT);
  }
  //Declare all input pins as inputs...
  pinMode(echo, INPUT);
}
void loop() {
  while (getDistance() >= 20) {
    Forward(200);
  }
Right(200);
}

long getDistance(){ //Retuns the distance to the object in cm
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(5);
digitalWrite(trig, LOW);
return pulseIn(echo, HIGH) / 29 / 2;
}

void Forward(int period) {
  digitalWrite(RB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(LA, HIGH);
  delay(period);
  Stop(100);
}

void Right(int period) {
  digitalWrite(RB, HIGH);
  digitalWrite(RA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LA, HIGH);
  delay(period);
  Stop(100);
}

void Stop(int period) { //Function and time to perform for
  digitalWrite(RB, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LB, HIGH);
  digitalWrite(LA, HIGH);
  delay(period);
}