int redp = 12;
int redn = 11;
int yellowp = 8;
int yellown = 9;
int greenp = 4;
int greenn = 3;
void setup()
{
   pinMode(redp,OUTPUT);
   pinMode(redn,OUTPUT);
   pinMode(yellowp,OUTPUT);
   pinMode(yellown,OUTPUT);
   pinMode(greenp,OUTPUT);
   pinMode(greenn,OUTPUT);
}
 void loop()
{  
   digitalWrite(redp,HIGH);
   digitalWrite(redn,LOW);
   delay(5000);
   digitalWrite(redp,LOW);
   digitalWrite(redn,LOW);
   
   digitalWrite(yellowp,HIGH);
   digitalWrite(yellown,LOW);
   delay(1000);
   digitalWrite(yellowp,LOW);
   digitalWrite(yellown,LOW);
   
   digitalWrite(greenp,HIGH);
   digitalWrite(greenn,LOW);
   delay(7000);
   digitalWrite(greenp,LOW);
   digitalWrite(greenn,LOW);
   
   digitalWrite(yellowp,HIGH);
   digitalWrite(yellown,LOW);
   delay(1000);
   digitalWrite(yellowp,LOW);
   digitalWrite(yellown,LOW);
}
