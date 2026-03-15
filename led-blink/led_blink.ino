int ledp = 8;
int ledn = 9;

void setup()
{
   pinMode(ledp,OUTPUT);
   pinMode(ledn,OUTPUT);
}

void loop()
{
   digitalWrite(ledp,HIGH);
   digitalWrite(ledn,LOW);
   delay(1000);

   digitalWrite(ledp,LOW);
   digitalWrite(ledn,LOW);
   delay(1000);
}
