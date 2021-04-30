#include <LiquidCrystal.h>
#define trigOut 8
#define echoInput 9
int duration = 0;
int distance = 0;

int pot1 = A0;
int pot2 = A1;
int pot3 = A2;

int buzzer = 13;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
int dt = 250;

void setup(){

  Serial.begin(9600);
  pinMode(trigOut,OUTPUT);
  pinMode(echoInput,INPUT);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(pot3,INPUT);
  lcd.begin(16, 2);
   pinMode(buzzer,OUTPUT);
  
}

void loop(){
  String note;
  digitalWrite(trigOut,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigOut,HIGH);
  delayMicroseconds(10);//(if the delay is less than 10 precision takes a huge hit)
  digitalWrite(trigOut,LOW);
  duration = pulseIn(echoInput,HIGH);
  
  
  distance = (duration)*(0.034)/2;
  int val1 = analogRead(pot1);
  int val2 = analogRead(pot2);
  int val3 = analogRead(pot3);

   if(Serial.available() >0 && distance <= 30)
  {
  	note = Serial.readString();
  
  Serial.println(note);
 for(int i = 0;i<note.length();i++)
 {
    val1 = analogRead(pot1);
   val2 = analogRead(pot2);
   val3 = analogRead(pot3);
  if(note.charAt(i) == 'c')
  {
    tone(buzzer,300+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
  
  if(note.charAt(i) == 'd' || note.charAt(i) == 'D')
  {
    tone(buzzer,400+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
  if(note.charAt(i) == 'e' || note.charAt(i)== 'E')
  {
    tone(buzzer,500+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
  if(note.charAt(i) == 'f' || note.charAt(i) == 'F')
  {
    tone(buzzer,600+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
  if(note.charAt(i) == 'g' || note.charAt(i) == 'G')
  {
    tone(buzzer,700+val2,100);
  		delay(dt+val1);
  }
  if(note.charAt(i) == 'a')
  {
    tone(buzzer,800+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
  if(note.charAt(i) == 'A')
  {
    tone(buzzer,850+val2,100);
    lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
    if(note.charAt(i) == 'C')
  {
    tone(buzzer,900+val2,100);
      lcd.setCursor(0,0);
    lcd.print(note);
  		delay(dt+val1);
  }
     if(note.charAt(i) == ' ')
  {
  		delay(dt+250);
  }
 }
  }
  
}
// Acceptable characters are :- c,C,d,e,f,g,a,A
// To play the happy birthDay song
// Enter these notes exactly as given here
// ccdcfe
// ccdcgf
// ccCafed
// AAafgf