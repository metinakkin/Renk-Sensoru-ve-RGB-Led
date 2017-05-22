#include<Servo.h>

Servo sg90;
int pos=0;


const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
int kirmiziLed = 2;
int yesilLed = 3; // RGB Ledlerin pinleri
int maviLed = 4;
int kirmizi = 0;
int yesil = 0;   // Renkleri baslangınc degerleri
int mavi = 0;

void setup()
{ sg90.write(0);
  sg90.attach(6);
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  pinMode(maviLed, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

}

void loop()
{
  renk();
 /*Serial.println("Kirmizi");
  Serial.println(kirmizi,DEC);
  
  Serial.println("Mavi");
  Serial.println(mavi,DEC);
  
  Serial.println("Yesil");
  Serial.println(yesil,DEC);
  delay(1000);*/
  if (kirmizi< mavi && kirmizi < yesil && kirmizi<150 )
  {
    sg90.write(0);
    digitalWrite(kirmiziLed,LOW );
    digitalWrite(yesilLed, HIGH);
    digitalWrite(maviLed, HIGH);
  }
  if (mavi < kirmizi && mavi <yesil && mavi<800 && 20<mavi)
  {
    sg90.write(90);
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(yesilLed, HIGH);
    digitalWrite(maviLed, LOW);

  }
  if (yesil < kirmizi && yesil < mavi && yesil<400)
  {
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(yesilLed, LOW);
    digitalWrite(maviLed, HIGH);
  }
  if(kirmizi<mavi && yesil<mavi && kirmizi<yesil && kirmizi<400  )
  {
    sg90.write(180);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(yesilLed, LOW);
    digitalWrite(maviLed, HIGH);
    
    
    }
   
  else
  {

    delay(300);
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(yesilLed, HIGH);
    digitalWrite(maviLed, HIGH);

  }
}

void renk()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  kirmizi = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  mavi = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  yesil = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);




}

