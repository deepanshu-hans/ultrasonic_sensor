const int echo = 7;
const int trig = 8;
const int led = 13;

int maxr = 380;
int minr = 0;
int dur, dist;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);
  
  dur = pulseIn(echo, HIGH);

  dist = dur / 58.2;

  if(dist >= maxr || dist <= minr)
  {
    lcd.clear();
    Serial.println("Man its too far!");
    digitalWrite(led, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Man its too far!");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dist in cms: ");
    lcd.print(dist);
    Serial.print(dist);
    Serial.println("cms");
    lcd.setCursor(0, 1);
    lcd.print("S.T.A.R Tech.");
    digitalWrite(led, LOW); 
  }
  delay(500);
}  

