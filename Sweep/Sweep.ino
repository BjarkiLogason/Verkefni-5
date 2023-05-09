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

