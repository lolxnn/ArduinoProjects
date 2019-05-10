#include <Servo.h> 
#define CALL1 7
#define CALL2 8
#define CALL3 9
#define PUL1 4
#define PUL2 5
#define PUL3 6
Servo porta1;
Servo porta2;
Servo porta3;
Servo motore;
int pos;

void setup() {
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  porta1.attach(10);
  porta2.attach(11);
  porta3.attach(12);
}

void loop() {
  if(CALL1 && pos != 1) moveTo(1);
  if(CALL2 && pos != 2) moveTo(2);
  if(CALL3 && pos != 3) moveTo(3);
}
