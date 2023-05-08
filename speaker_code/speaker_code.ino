#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "tdelay.h"

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;
void playSound();
TDelay spilun(10000);

void setup() {
mySoftwareSerial.begin(9600);  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  
    while(true);
  }
myDFPlayer.volume(30);
}

void loop() {
 playSound();
}  

void playSound() {
  if (spilun.timiLidinn() == true) {
    myDFPlayer.play(1); 
  }
}
