#include <LiquidCrystal.h>
#include <EEPROM.h>
#define RED_LIGHT 2
#define MOTORE 3
#define SENS_IN 4
#define SENS_OUT 5
#define MAX_NUMBER_OF_CARS 10
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int macchine;
int passed;
void setup(){
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(MOTORE, OUTPUT);
  pinMode(SENS_IN, INPUT);
  pinMode(SENS_OUT, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  macchine = EEPROM.read(0);
  if(macchine == 255){ 
    macchine = 0;
    EEPROM.write(0, macchine);
  }
}

void loop(){
  if(macchine >= MAX_NUMBER_OF_CARS) digitalWrite(RED_LIGHT, HIGH);
  else digitalWrite(RED_LIGHT, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Parchggio Auto");
  lcd.setCursor(0, 1);
  lcd.print("N. Macchine:");
  lcd.print(macchine);
  if(digitalRead(SENS_IN)) addCar();
  if(digitalRead(SENS_OUT)) removeCar();
  EEPROM.write(0, macchine);
  delay(1);
}

void addCar(){
 if(macchine < MAX_NUMBER_OF_CARS && macchine >= 0){
    digitalWrite(MOTORE, HIGH);
    do{
     passed = digitalRead(SENS_OUT);
     Serial.println(passed);
     }while(!passed);
    digitalWrite(MOTORE, LOW); 
    macchine++;
    delay(200);
    lcd.clear();
    return;
  }
  lcd.clear();
  return;
}

void removeCar(){
 if(macchine <= MAX_NUMBER_OF_CARS && macchine > 0){
    digitalWrite(MOTORE, HIGH);
    do{
     passed = digitalRead(SENS_IN);
     }while(!passed);
    digitalWrite(MOTORE, LOW);  
    macchine--;
    delay(200);
    lcd.clear();
    return;
  }
  lcd.clear();
  return;
}
