# Verkefni-5


const int HRADI = 5;     
const int STEFNA_A = 2;     
const int STEFNA_B = 4;     
void setup() {

  pinMode(HRADI, OUTPUT);
  pinMode(STEFNA_A, OUTPUT);
  pinMode(STEFNA_B, OUTPUT);
  haegri(200);
 
}

void loop() {

   haegri(200);
}  

void haegri(int hradi) {
    digitalWrite(STEFNA_A, HIGH);
    digitalWrite(STEFNA_B, LOW);
    analogWrite(HRADI, hradi);
}




#include <Servo.h> // Sambærilegt og import í python
#include "tdelay.h"

Servo motor; // bý til tilvik af Servo klasanum
int motor_pinni = 9; // pinninn sem ég nota til að stjórna mótornum

int motor_stefnur[] = {90, 120, 150, 120}; 
int motor_stefnu_fjoldi = 4; // breytan geymir hversu margar stefnur eru í listanum
int motor_stefnu_teljari = 0; // breytan heldur utan um í hvaða stefnu mótorinn á að benda

TDelay motor_bid(100); // bíða í hálfa sekúndu á milli hreyfinga

void setup() {
  motor.attach(motor_pinni); // segi servo tilvikinu hvaða pinna á að nota
  motor.write(motor_stefnur[motor_stefnu_teljari]); // í þessu tilfelli á mótorinn að byrja í 0°
}

void loop() {
  if(motor_bid.timiLidinn()) {
    motor_stefnu_teljari = (motor_stefnu_teljari + 1) % motor_stefnu_fjoldi;
    motor.write(motor_stefnur[motor_stefnu_teljari]);
  }
}
