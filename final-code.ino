#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "tdelay.h"
#include <Servo.h>

const int LED1 = 6; 
const int LED2 = 7; //led 

int lagmarks_bidtimi = 250;
int hamarks_bidtimi = 750; //LED

bool LED1_on = true; // stöðubreytur, halda utan um hvort kveikt eða slökkt er á perunum
bool LED2_on = true; //LED

TDelay led1_delay; // "delay" breytur fyrir hverja peru
TDelay led2_delay; //LED

const int HRADI = 5;     
const int STEFNA_A = 1;     
const int STEFNA_B = 4; //HREYFING

const int ECHO = 2; 
const int TRIG = 3; 
int distance = 0;  
int fjarlaegd(); //SCANNER

Servo motor; // bý til tilvik af Servo klasanum
int motor_pinni = 12;
TDelay motor_bid(10000);
int motor_stefnur[] = {90, 120, 150, 120}; 
int motor_stefnu_fjoldi = 4; // breytan geymir hversu margar stefnur eru í listanum
int motor_stefnu_teljari = 0; //HREYFING 

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;
void playSound();
TDelay spilun(10000); //SPEAKER

void setup() {
  pinMode(HRADI, OUTPUT);
  pinMode(STEFNA_A, OUTPUT);
  pinMode(STEFNA_B, OUTPUT);
 
  motor.attach(motor_pinni); // segi servo tilvikinu hvaða pinna á að nota
  motor.write(motor_stefnur[motor_stefnu_teljari]); // í þessu tilfelli á mótorinn að byrja í 0°

Serial.begin(9600);
pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT); //SCANNER

pinMode(LED1, OUTPUT); // skilgreina hvernig pinninn virkar sem peran er tengd í
pinMode(LED2, OUTPUT);

led1_delay.setBidtimi(lagmarks_bidtimi); // setja upphafsbiðtíma fyrir hverja peru
led2_delay.setBidtimi(lagmarks_bidtimi); //LED

mySoftwareSerial.begin(9600);  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  
    while(true);
  }
myDFPlayer.volume(25); //SPEAKER

}
void loop() {
  // put your main code here, to run repeatedly:
distance = fjarlaegd();  
Serial.print("fjarlaegd: ");
Serial.println(fjarlaegd());


 if(distance < 0) {
  distance = 0;
}

if(distance > 50) {
  stop(200);
}

if(distance < 50){

playSound(); //speaker

  if (led1_delay.timiLidinn()) { // ef biðtiminn er liðinn
    LED1_on = !LED1_on; // víxla (e. toggle) stöðubreytu perunnar
    led1_delay.setBidtimi(hamarks_bidtimi); // setja biðtíma til að halda perunni í sömu stöðu
  }

  if (led2_delay.timiLidinn()) {
    LED2_on = !LED2_on;
    led2_delay.setBidtimi(hamarks_bidtimi);
  }

  digitalWrite(LED1, LED1_on); // kveikir eða slekkur á perunni true jafngildir HIGH (5V)
  digitalWrite(LED2, LED2_on); // false jafngildir LOW (0V)

  haegri(200);
  
  // servo
  if(motor_bid.timiLidinn()) {
     motor_stefnu_teljari = (motor_stefnu_teljari + 2) % motor_stefnu_fjoldi;
    motor.write(motor_stefnur[motor_stefnu_teljari]);
  } 

 

}

}

int fjarlaegd() {
digitalWrite(TRIG,LOW);
delayMicroseconds(2);
digitalWrite(TRIG,HIGH);
delayMicroseconds(10);
digitalWrite(TRIG,LOW);
return (int)pulseIn(ECHO,HIGH)/58.0;
} //SCANNER

void haegri(int hradi) {
    digitalWrite(STEFNA_A, HIGH);
    digitalWrite(STEFNA_B, LOW);
    analogWrite(HRADI, hradi);
} //HREYFING


void stop(int hradi) {
    digitalWrite(STEFNA_A, LOW);
    digitalWrite(STEFNA_B, LOW);
    analogWrite(HRADI, 0);
} //HREYFING


void playSound() {
  if (spilun.timiLidinn() == true) {
    myDFPlayer.play(1); 
  }
} //SPEAKER