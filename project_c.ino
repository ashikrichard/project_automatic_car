

#include<Servo.h>

int echo=0;
int trig=2;
int t,d;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  Serial.begin(115200);
  servo.attach(15);
  servo.write(115);
}

void loop() {
  // put your main code here, to run repeatedly:
  int starts=sensor();
 delay(40);
 
 if(starts<=15)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  int distanceleft=lookLeft();
  delay(200);
  int distanceright=lookRight();
  delay(200);

  if(distanceright>=distanceleft)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
}
void moveForward(){
  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  
  }
  void moveBackward(){
    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);
    }
    int sensor(){
       digitalWrite(trig,LOW);
       delayMicroseconds(5);
       digitalWrite(trig,HIGH);
       delayMicroseconds(10);
       t=pulseIn(echo,HIGH);
       d=(0.038*t)/2;
       delay(50);
       Serial.println(d);
       return d;
    }
    int lookRight()
{
    servo.write(50); 
    delay(500);
    int lr=sensor();
    delay(100);
    servo.write(115); 
    return lr;
}
int lookLeft()
{
    servo.write(170); 
    delay(500);
    int ll=sensor();  
    delay(100);
    servo.write(115);
    return ll; 
}
void turnRight()
{
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);
  
}
void turnLeft(){
      digitalWrite(D0,HIGH);
      digitalWrite(D1,HIGH);
      digitalWrite(D2,LOW);
      digitalWrite(D5,HIGH);
      digitalWrite(D6,LOW);
      digitalWrite(D7,HIGH);
  
}
void moveStop(){
     digitalWrite(D0,HIGH);
     digitalWrite(D1,LOW);
     digitalWrite(D2,LOW);
     digitalWrite(D5,HIGH);
     digitalWrite(D6,LOW);
     digitalWrite(D7,LOW);
}
