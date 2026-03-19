int ledp = 8;
int ledn = 9;
int sensor = 5;
void setup()
{
  pinMode(ledp,OUTPUT);
  pinMode(ledn,OUTPUT);
  pinMode(sensor,INPUT);  
}
void loop()
{
  if(digitalRead(sensor) == LOW){
    digitalWrite(ledp,HIGH);
    digitalWrite(ledn,LOW);
  }
  else{
    digitalWrite(ledp,LOW);
    digitalWrite(ledn,LOW);    
  }
}
