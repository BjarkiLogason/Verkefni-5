# Verkefni-5

Verkefnið sem að við strákarnir ákváðum að gera er "grave grabber" vegna þess að þegar við vorum að fara yfir verkefni sem okkur var sýnt þá leist okkur best á þetta. Í þessu verkefni skiptum við niður verkum, Andri og Bjarki unnu að búknum, og unnu að Servo-unum til að fá "grave grabber" hreyfinguna, Bjarki vann svo í skýrslunni. Tómas kóðaði hreyfingu í kjálka og ljós í augun þegar er búið að virkja verkefnið. Eiður vann að hljóðinu sem "grave grabber" gefur frá sér og að skannaranum sem virkir það þegar einhver kemur nálægt. Andri og Eiður settu svo alla kóðana saman til að búa til einn kóða fyrir allt verkefnið









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


#include "tdelay.h" // sambærilegt og import í python

const int LED1 = 2; // breytur fyrir led perurnar
const int LED2 = 3;

bool LED1_on = true; // stöðubreytur, halda utan um hvort kveikt eða slökkt er á perunum
bool LED2_on = true;

TDelay led1_delay; // "delay" breytur fyrir hverja peru
TDelay led2_delay;

int lagmarks_bidtimi = 250;
int hamarks_bidtimi = 750;

void setup() {
  pinMode(LED1, OUTPUT); // skilgreina hvernig pinninn virkar sem peran er tengd í
  pinMode(LED2, OUTPUT);

  led1_delay.setBidtimi(lagmarks_bidtimi); // setja upphafsbiðtíma fyrir hverja peru
  led2_delay.setBidtimi(lagmarks_bidtimi);
}

void loop() {
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
}
