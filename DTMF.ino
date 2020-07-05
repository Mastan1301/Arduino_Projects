/* Arduino-Bluetooth based remote-controlled car */

#define m11 2
#define m12 3
#define m21 4
#define m22 5

#define D0 19
#define D1 18
#define D2 17
#define D3 16

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}

void right()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}

void left()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void setup() 
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{

  int temp1=digitalRead(A5);
  int temp2=digitalRead(A4);
  int temp3=digitalRead(A3);
  int temp4=digitalRead(A2);

  
  if(temp1==0 && temp2==1 && temp3==0 && temp4==0)
  forward();

  else if(temp1==0 && temp2==0 && temp3==1 && temp4==0)
  left();

  else if(temp1==0 && temp2==1 && temp3==1 && temp4==0)
  right();

  else if(temp1==0 && temp2==0 && temp3==0 && temp4==1)
  backward();

   else if(temp1==1 && temp2==0 && temp3==1 && temp4==0)
  Stop();
}
