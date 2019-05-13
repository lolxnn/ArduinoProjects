#include <Arduino.h>
#include <Servo.h> 
#define CALL1 7
#define CALL2 8
#define CALL3 9
#define PUL1 4
#define PUL2 5
#define PUL3 6
#define MOTUP 3
#define MOTDOWN 2
#define INT1 22
#define INT2 23
#define INT3 24
#define INT5 25
Servo porta1;
Servo porta2;
Servo porta3;
int pos = 1;
int arrived;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  porta1.attach(10);
  porta2.attach(11);
  porta3.attach(12);
  
}

void loop() {
  if(CALL1 || INT1) moveTo(1);
  if(CALL2 || INT2) moveTo(2);
  if(CALL3 || INT3) moveTo(3);
  checkDoors();
}

void moveTo(int floor;){
  delay(1000);
  if(floor = pos) break;
  if(pos = 1 && floor = 2){
    doorMan(1, 1);
    do{
      arrived = digitalRead(24);
      digitalWrite(MOTUP, HIGH);
    }while(!arrived)
    digitalWrite(MOTUP, LOW);
    pos = floor;
    break;
  }
  if(pos = 1 && floor = 3){
    doorMan(1, 1);
    do{
      arrived = digitalRead(25);
      digitalWrite(MOTUP, HIGH);
    }while(!arrived)
    digitalWrite(MOTUP, LOW);
    pos = floor;
    break;
  }
  if(pos = 2 && floor = 1){
    doorMan(2, 1);
    do{
      arrived = digitalRead(22);
      digitalWrite(MOTDOWN, HIGH);
    }while(!arrived)
    digitalWrite(MOTDOWN, LOW);
    pos = floor;
    break;
  }
  if(pos = 2 && floor = 3){
    doorMan(2, 1);
    do{
      arrived = digitalRead(25);
      digitalWrite(MOTUP, HIGH);
    }while(!arrived)
    digitalWrite(MOTUP, LOW);
    pos = floor;
    break;
  }
  if(pos = 3 && floor = 2){
    doorMan(3, 1);
    do{
      arrived = digitalRead(23);
      digitalWrite(MOTDOWN, HIGH);
    }while(!arrived)
    digitalWrite(MOTDOWN, LOW);
    pos = floor;
    break;
  }
  if(pos = 3 && floor = 1){
    doorMan(3, 1);
    do{
      arrived = digitalRead(22);
      digitalWrite(MOTDOWN, HIGH);
    }while(!arrived)
    digitalWrite(MOTDOWN, LOW);
    pos = floor;
    break;
  }

}

void checkDoors(){
  if(pos = 1) {
    doorMan(1, 1);
    doorMan(2, 0);
    doorMan(3, 0);
  }
  if(pos = 2) {
    doorMan(1, 0);
    doorMan(2, 1);
    doorMan(3, 0);
  }
  if(pos = 3) {
    doorMan(1, 0);
    doorMan(2, 0);
    doorMan(3, 1);
  }
}

void doorMan(int port, bool oec){
  if(port = 1) {
    if(oec) porta1.write(180);
    else porta2.write(0);
  }
  if(port = 1) {
    if(oec) porta2.write(180);
    else porta2.write(0);
  }
  if(port = 1) {
    if(oec) porta3.write(180);
    else porta2.write(0);
  }
}

