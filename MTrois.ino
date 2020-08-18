// Humanoid 9 DOF demo
// Servos start at D2 as servo number 1
// Through D5 as servo number 4
// Then D8 as servo number 5
// Through D12 as servo number 9
// I skipped using D0, D1, D6 and D7

#include <Servo.h> 
Servo servo1;  // Left Ankle
Servo servo2;  // Left Hip
Servo servo3;  // Right Ankle
Servo servo4;  // Right Hip
Servo servo5;  // Left arm
Servo servo6;  // Left Shoulder
Servo servo7;  // Right arm
Servo servo8;  // Right Shoulder
Servo servo9;  // Head
int pos = 0;   // variable to store the servo position 
String comm = " ";

 
void setup() { 
  Serial.begin(38400);

  
  servo1.attach(2);  // Left Ankle - attaches the servo 
  servo2.attach(3);  // Left hip
  servo3.attach(4);  // Right Ankle
  servo4.attach(6);  // Right hip
  servo5.attach(9);  // Left arm
  servo6.attach(10);  // Left Shoulder
  servo7.attach(11);  // Right arm
  servo8.attach(12);  // Right Shoulder
  servo9.attach(13);  // Head
  
  servo1.write(90);  // Set zero positions
  servo2.write(90);  // 
  servo3.write(90);  // 
  servo4.write(90);  // 
  servo5.write(0);  // Set zero positions
  servo6.write(180);  // 
  servo7.write(180);  // 
  servo8.write(0);  // 
  servo9.write(90);
  delay(500);// Set zero positions


  
  
}


void StepForward() { 
  for(int i = 0; i < 5; i++){ 
    servo1.write(70);  //shift weight to left ankle
    servo3.write(70);  
    delay(200);
    
    servo2.write(105);
    servo4.write(105);//left hip
    //right hip
   
    
    delay(200);
    servo1.write(90);  //level ankle 
    servo3.write(90);  //right ankle
    delay(200); //Shift weight to right ankle
    servo1.write(110);
    servo3.write(110);  
    delay(200);
    
    servo2.write(75);  //left hip
    servo4.write(75);  //right hip
     delay(200);
    servo1.write(90);  //level ankle 
    servo3.write(90);  //right ankle
    delay(200);
  }
   
}

void StepBackward(){
  for(int i = 0; i < 5; i++){   
  servo1.write(70);  //shift weight to left ankle
  servo3.write(70);  
  delay(200);
  servo2.write(75);  //left hip
  servo4.write(75);  //right hip
  delay(200);
  servo1.write(90);  //level left ankle
  servo3.write(90);  //level right ankle
  delay(200);
  servo1.write(110);  //Shift weight to right ankle
  servo3.write(110);  
  delay(200);
  servo2.write(105);  //left hip
  servo4.write(105);  //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo3.write(90);  //right ankle
  delay(200);
  }
}
void Hi() {  
  
   servo6.write(180);
  delay(200);
  servo5.write(0);
  delay(200);
  servo9.write(90);
  delay(1000);
  servo9.write(60);
   delay(1000);
    servo9.write(90);
     delay(1000);
     servo9.write(120);
      delay(1000);
    servo9.write(90);
    delay(1000);
    servo6.write(0);
  delay(1000);
  servo5.write(45);
  delay(400);
  servo5.write(0);
  delay(400);
   servo5.write(45);
  delay(400);
  servo5.write(0);
  delay(400);
   servo5.write(45);
  delay(400); 

  servo5.write(0);
   servo6.write(0);
  delay(200);
  servo6.write(180);
  delay(1000);
  
  
}
void step1() {
  
  servo1.write(90);
  servo3.write(90);
  delay(200);
  servo2.write(90);
  servo4.write(90);
  delay(200);
  servo6.write(0);
  delay(300);
  servo8.write(0);
  delay(300);
  servo6.write(90);
  delay(300);
  servo8.write(90);
  delay(300);
  servo6.write(180);
  delay(300);
  servo8.write(180);
  delay(300);
  servo6.write(90);
  delay(300);
  servo8.write(90);
  delay(300);
  servo6.write(0);
  delay(300);
  servo8.write(0);
  delay(300);
  servo6.write(90);
  delay(300);
  servo8.write(90);
  delay(300);
  servo6.write(180);
  delay(300);
  servo8.write(180);
  delay(300);
  servo6.write(90);
  delay(300);
  servo8.write(90);
  delay(300);
  servo6.write(0);
  delay(300);
  servo8.write(0);
  
}

void dance1(){
  for(int i = 0; i < 2; i++){ 
  servo6.write(0);
  delay(400);
  servo8.write(180);
  delay(400);
  servo5.write(0);
  servo7.write(180);
  delay(200);
  
  servo7.write(120);
  servo5.write(60);
  delay(400);
  
  servo5.write(0);
  servo7.write(180);
  delay(400);
  
  servo7.write(120);
  servo5.write(60);
  delay(400);
  
  servo5.write(0);
   servo7.write(180);
  delay(400);
  servo7.write(120);
  servo5.write(60);
  delay(400);
  servo5.write(0);
   servo7.write(180);
   delay(400);
   servo6.write(180);
  delay(400);
  servo8.write(0);
  delay(400);
  
 }
}
 void dance2(){
  for(int i = 0; i < 5; i++){
  servo6.write(180);
  delay(300);
  servo6.write(90);
  delay(300);
  servo6.write(0);
  delay(300);
  servo5.write(45);
  delay(200);
  servo2.write(60);
  delay(200);
  servo5.write(0);
  delay(200);
  servo2.write(90);
  delay(200);
  servo5.write(45);
  delay(200);
  servo2.write(60);
  delay(200);
  servo5.write(0);
  delay(200);
  servo2.write(90);
  delay(200);
  servo5.write(45);
  delay(200);
  servo2.write(60);
  delay(200);
  servo5.write(0);
  delay(200);
  servo2.write(90);
  delay(300);
  servo6.write(0);
  delay(300);
  servo6.write(90);
  delay(300);
  servo6.write(180);
  }
 }
 void dance3(){
  for(int i = 0; i < 5; i++){ 
  servo8.write(0);
  delay(300);
  servo8.write(90);
  delay(300);
  servo8.write(180);
  delay(300);
  servo7.write(135);
  delay(200);
  servo4.write(120);
  delay(200);
  servo7.write(180);
  delay(200);
  servo4.write(90);
  delay(200);
  servo7.write(135);
  delay(200);
  servo4.write(120);
  delay(200);
  servo7.write(180);
  delay(200);
  servo4.write(90);
  delay(200);
  servo7.write(135);
  delay(200);
  servo4.write(120);
  delay(200);
  servo7.write(180);
  delay(200);
  servo4.write(90);
  delay(300);
  servo8.write(180);
  delay(300);
  servo8.write(90);
  delay(500);
  servo8.write(0);
  delay(500);
 }
 }
 void dance4() {
  for(int i = 0; i < 5; i++){ 
  servo2.write(90);
  servo4.write(90);
  delay(200);
  servo2.write(80);
  servo4.write(150);
  delay(200);
  servo2.write(90);
  servo4.write(90);
  }
 }
  
void attention1() {
  servo1.write(90);
  servo3.write(90);
  delay(200);
  servo2.write(90);
  servo4.write(90);
  delay(200);
  servo6.write(0);
  delay(1000);
  servo8.write(180);
  delay(1000);
  servo5.write(180);
  delay(400);
  servo7.write(0);
  delay(400);
  }
void attention2() {
  servo1.write(90);
  servo3.write(90);
  delay(200);
  servo2.write(90);
  servo4.write(90);
  delay(200);
  servo6.write(180);
  delay(1000);
  servo8.write(0);
  delay(1000);
  servo5.write(0);
  delay(400);
  servo7.write(180);
  delay(400);
  }

//Main Control loop
void loop(){
   if(Serial.available()>0)
   {
    comm = Serial.readString(); 
 
    Serial.println(comm);

    if(comm == "forward")
      StepForward();

    else if(comm == "backward")
      StepBackward();

    else if(comm == "Say Hi")
      Hi();

    else if(comm ==  "Wave your hands")
      step1();

    else if(comm == "dance1")
      dance1();

    else if(comm == "dance2")
      dance2();

    else if(comm == "dance3")
      dance3();

    else if(comm == "dance4")
      dance4();

    else if(comm == "attention1")
      attention1();

    else if((comm == "attention2") || (comm == "stop"))
      attention2();
        
  }
}

  

  

 


  
   
   

// end of program
