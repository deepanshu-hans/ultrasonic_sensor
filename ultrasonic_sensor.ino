const int trig = 0, echo = 1;
long duration, distcm, distin;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  distcm = duration / 58;
  distin = duration / 148;
  Serial.println("Distance in cm = "  );
  Serial.print(distcm);
  Serial.println("Distance in inch = "  );
  Serial.print(distin);
  delay(500);
}
