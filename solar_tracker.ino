#include <Servo.h>
//defining Servos
Servo servo_h;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servo_v;
int servov = 0;
int servovLimitHigh = 160;
int servovLimitLow = 20;
//Assigning LDRs
int topl = 2; //top left LDR green
int topr = 1; //top right LDR yellow
int botl = 3; // bottom left LDR blue
int botr = 0; // bottom right LDR orang

void setup ()
{
  Serial.begin(9600);
  servo_h.attach(9);
  servo_h.write(0);
  servo_v.attach(10);
  servo_v.write(0);
  delay(500);
}

void loop()
{
  servoh = servo_h.read();
  servov = servo_v.read();
  //capturing analog values of each LDR
  int top_l = analogRead(topl);
  delay(5);
  int top_r = analogRead(topr);
  delay(5);
  int bot_l = analogRead(botl);
  delay(5);
  int bot_r = analogRead(botr);
  delay(5);
  int read_f = analogRead(4);
  delay(5);
  int read_b = analogRead(5);
  delay(5);
  // calculating average
  int avgtop = (top_l + top_r) / 2; //average of top LDRs
  int avgbot = (bot_l + bot_r) / 2; //average of bottom LDRs
  int avgleft = (top_l + bot_l) / 2; //average of left LDRs
  int avgright = (top_r + bot_r) / 2; //average of right LDRs
  delay(1000);


 
 
  if (avgtop < avgbot)
  {
    servo_v.write(servov + 10);
    if (servov > servovLimitHigh)
    {
      servov = servovLimitHigh;
    }
  delay(100);
  }
  else if (avgbot < avgtop)
  {
    servo_v.write(servov - 10);
    if (servov < servovLimitLow)
    {
      servov = servovLimitLow;
    }
 delay(100);
  }
  else
  {
    servo_v.write(servov);
     delay(100);
  }

  if (avgleft > avgright)
  {
    servo_h.write(servoh + 10);
    if (servoh > servohLimitHigh)
    {
      servoh = servohLimitHigh;
    }
   delay(100);
  }
  else if (avgright > avgleft)
  {
    servo_h.write(servoh - 10);
    if (servoh < servohLimitLow)
    {
      servoh = servohLimitLow;
    }
   delay(100);
  }
  else
  {
    servo_h.write(servoh);
     delay(100);
  }



   if ((read_b > 35) )
  {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
        delay(10);
  }


  else if (read_f > 95)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
        delay(10);
  }
  

  else
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
        delay(10);
  }

}
