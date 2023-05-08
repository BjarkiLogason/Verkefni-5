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

