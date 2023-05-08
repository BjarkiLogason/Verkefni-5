const int ECHO = 2;
const int TRIG = 3;
int distance = 0;  
int fjarlaegd();


void setup() {
Serial.begin(9600);
pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);
}


void loop() {
distance = fjarlaegd();  
Serial.print("fjarlaegd: ");
Serial.println(fjarlaegd());


 if(distance < 0) {
  distance = 0;
}
if(distance < 50 && distance != 0){
}


}
int fjarlaegd() {
digitalWrite(TRIG,LOW);
delayMicroseconds(2);
digitalWrite(TRIG,HIGH);
delayMicroseconds(10);
digitalWrite(TRIG,LOW);


return (int)pulseIn(ECHO,HIGH)/58.0;
}

