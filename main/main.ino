#include <Servo.h>
Servo myservo; 
int pos = 0;
const int tri = 6;
const int echo = 5;
const int bz = 10;
long dur;
int dist;   
int s=0,c=0;
void setup()
{
  myservo.attach(9);  
  pinMode(tri, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(bz, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  /*digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);
  dur = pulseIn(echo, HIGH);
  dist= dur*0.034/2;
  Serial.print("Distance: ");
  Serial.println(dist);*/
  if(s!=1)
  {
  for (pos = 50; pos <=200; pos += 1)
  {
   c=pos;
   myservo.write(pos);              
   delay(2);
   if(pos%4==0)
   {
    digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);
  dur = pulseIn(echo, HIGH);
  dist = dur*0.034/2;
  Serial.print("Distance: ");
  Serial.println(dist);
  if(dist>10 && dist<30)
  {Serial.println("SOMETHING");
  digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);
  dur = pulseIn(echo, HIGH);
  dist= dur*0.034/2;
  if(dist>10 && dist<30)
  {
    Serial.println("SOMETHING");
  digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);
  dur = pulseIn(echo, HIGH);
  dist= dur*0.034/2;
  if(dist>10 && dist<30)
  {
    Serial.println("caught");
    s=1;
    break;
  }
  }
  }        
  }
  }
  for (pos = 200; pos >= 50; pos -= 1)
  { 
    myservo.write(pos);              
   delay(2);
   /*digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);
  dur = pulseIn(echo, HIGH);
  dist= dur*0.034/2;
  Serial.print("Distance: ");
  Serial.println(dist); */                    
  }
  }
  if(s==1)
  {
    digitalWrite(bz,HIGH);
    delay(100);
    digitalWrite(bz,LOW);
    delay(100);
    Serial.println("here");
    Serial.println(c);
  }
  
}
