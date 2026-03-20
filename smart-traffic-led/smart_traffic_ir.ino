int redp = 12;
int redn = 11;
int yellowp = 8;
int yellown = 9;
int greenp = 4;
int greenn = 3;
int sensor = 5;
void setup()
{
  pinMode(redp,OUTPUT);
  pinMode(redn,OUTPUT);
  pinMode(yellowp,OUTPUT);
  pinMode(yellown,OUTPUT);
  pinMode(greenp,OUTPUT);
  pinMode(greenn,OUTPUT);
  pinMode(sensor,INPUT);  
}
void loop()
{
  if(digitalRead(sensor) == LOW){
   digitalWrite(redp,HIGH);
   digitalWrite(redn,LOW);
   delay(100);
   digitalWrite(redp,LOW);
   digitalWrite(redn,LOW);
   digitalWrite(yellowp,HIGH);
   digitalWrite(yellown,LOW);
   delay(100);
   digitalWrite(yellowp,LOW); 
   digitalWrite(yellown,LOW); 
   
  }
  else{
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
}
