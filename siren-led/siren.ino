int ledp = 8;
int ledn = 9;
int ledp2= 4;
int ledn2 = 5;
void setup()
{
   pinMode(ledp,OUTPUT);
   pinMode(ledn,OUTPUT);
   pinMode(ledp2,OUTPUT);
   pinMode(ledn2,OUTPUT);
}
 void loop()
{  
   digitalWrite(ledp,HIGH);
   digitalWrite(ledn,LOW);
   delay(100);
   digitalWrite(ledp,LOW);
   digitalWrite(ledn,LOW);
   digitalWrite(ledp2,HIGH);
   digitalWrite(ledn2,LOW);
   delay(100);
   digitalWrite(ledp2,LOW); 
}
