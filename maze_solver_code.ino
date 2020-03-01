/* 
  Arduino code for maze solver bot using 6 IR sensors.
  * The first round is based on the left-hand wall algorithm.
  * In the second run (corresponding to the function 'replay( )', the bot traverses the maze in an optimized path.
*/


#define left_center 1
#define left_near 3
#define left_far 4
#define right_center 0
#define right_near 2
#define right_far 5

int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;
int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 200
#define leftMotor1 2
#define leftMotor2 3
#define rightMotor1 4
#define rightMotor2 5

char path[30] = {};
int pathLength;
int readLength;

void setup(){
  pinMode(left_center, INPUT);
  pinMode(left_near, INPUT);
  pinMode(left_far, INPUT);
  pinMode(right_center, INPUT);
  pinMode(right_near, INPUT);
  //pinMode(right_far, INPUT);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  Serial.begin(115200);

}

void loop(){
    readSensors();
    if(leftFarReading<200 && rightFarReading<200 && (leftCenterReading>200 || rightCenterReading>200))
    {
        straight();
    }
    else{
        left_hand();
    }
}

void readSensors(){
    leftCenterReading = analogRead(left_center);
    leftNearReading = analogRead(left_near);
    leftFarReading = analogRead(left_far);
    rightCenterReading = analogRead(right_center);
    rightNearReading = analogRead(right_near);
    rightFarReading = analogRead(right_far);

    Serial.print("leftCenterReading: ");
    Serial.println(leftCenterReading);
    Serial.print("leftNearReading: ");
    Serial.println(leftNearReading);
    Serial.print("leftFarReading: ");
    Serial.println(leftFarReading);
  
    Serial.print("rightCenterReading: ");
    Serial.println(rightCenterReading);
    Serial.print("rightNearReading: ");
    Serial.println(rightNearReading);
    Serial.print("rightFarReading: ");
    Serial.println(rightFarReading);
    delay(1000);
}

void left_hand(){
    if( leftFarReading>200 && rightFarReading>200){
        analogWrite(leftMotor1, 50); //move straight by a bit
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(leapTime);
        readSensors();
        if(leftFarReading>200 || rightFarReading>200){ //reached the destination
         done();
         }
        if(leftFarReading<200 && rightFarReading<200){
            turnLeft();
        }
    }

    if(leftFarReading>200){
        analogWrite(leftMotor1, 50);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(leapTime);
        readSensors();
    if(leftFarReading<200 && rightFarReading<200){
        turnLeft();
    }
    else{
        done();
    }
    }
    if(rightFarReading>200){
    analogWrite(leftMotor1, 50);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 50);
    analogWrite(rightMotor2, 0);
    delay(30);
    readSensors();
    if(leftFarReading>200){
        delay(leapTime-30);
        readSensors();
        if(rightFarReading>200 && leftFarReading>200){
            done();
        }
        else{
            turnLeft();
            return;
        }
    }
    delay(leapTime-30);
    readSensors();
    if(leftFarReading<200 && leftCenterReading<200 && rightCenterReading<200 && rightFarReading<200){
    turnRight();
    return;
    }
    path[pathLength]='S';
    pathLength++;
    if(path[pathLength-2]=='B'){
        shortPath();
    }
        straight();
    }
    readSensors();

    if(leftFarReading<200 && leftCenterReading<200 && rightCenterReading<200 && rightFarReading<200 && leftNearReading<200 && rightNearReading<200){
        turnAround();
    }
}

void done(){
    analogWrite(leftMotor1, 0); //reached goal
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 0);
    analogWrite(rightMotor2, 0);

    replaystage=1;
    path[pathLength]='D';
    pathLength++;

    delay(500);
    replay();
}

void turnLeft(){
    while(analogRead(right_center)>200||analogRead(left_center)>200){
        analogWrite(leftMotor1, 0); //turn left 
        analogWrite(leftMotor2, 50);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(20);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(10);
    }
    while(analogRead(right_center)<200){
        analogWrite(leftMotor1, 0); //turn left
        analogWrite(leftMotor2, 50);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(20);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(10);
    }
    if(replaystage==0){
        path[pathLength]='L';
        pathLength++;
        if(path[pathLength-2]=='B'){
            shortPath();
        }
    }
}

void turnRight(){
    while(analogRead(right_center)>200){
        analogWrite(leftMotor1, 50);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 50);
        delay(20);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(10);
    }

    while(analogRead(right_center)<200){
        analogWrite(leftMotor1, 50);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 50);
        delay(20);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(10);
    }

    while(analogRead(left_center)<200){
        analogWrite(leftMotor1, 50);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 50);
        delay(20);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(10);
    }

    if(replaystage==0){
        path[pathLength]='R';
        //Serial.println("r");
        pathLength++;
        /*Serial.print("Path length: ");
        Serial.println(pathLength);*/

        if(path[pathLength-2]=='B'){
            //Serial.println("shortening path");
            shortPath();
        }
    }
}

void straight(){
    if( analogRead(left_center)<200){
        analogWrite(leftMotor1, 50); //turning left
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(1);
        analogWrite(leftMotor1, 50);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(2);
        return;
    }
    if(analogRead(right_center)<200){
        analogWrite(leftMotor1, 50); //turning right
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(1);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(2);
        return;
    }

    analogWrite(leftMotor1, 50); //go forward by a bit and stop
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 50);
    analogWrite(rightMotor2, 0);
    delay(2);
    
    analogWrite(leftMotor1, 0);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 0);
    analogWrite(rightMotor2, 0);
    delay(1);
}

void turnAround(){
    analogWrite(leftMotor1, 50); //turning by 180 degrees
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 50);
    analogWrite(rightMotor2, 0);
    delay(150);

    while(analogRead(left_center)<200){
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 50);
        analogWrite(rightMotor1, 50);
        analogWrite(rightMotor2, 0);
        delay(2);
        analogWrite(leftMotor1, 0);
        analogWrite(leftMotor2, 0);
        analogWrite(rightMotor1, 0);
        analogWrite(rightMotor2, 0);
        delay(1);
    }
    path[pathLength]='B';
    pathLength++;
    straight();
}

void shortPath(){
    int shortDone=0;

    if(path[pathLength-3]=='L' && path[pathLength-1]=='R'){
        pathLength-=3;
        path[pathLength]='B';
        shortDone=1;
    }

    if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone>200){
        pathLength-=3;
        path[pathLength]='R';
        shortDone=1;
    }

    if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone>200){
        pathLength-=3;
        path[pathLength]='B';
        shortDone=1;
    }

    if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone>200){
        pathLength-=3;
        path[pathLength]='R';
        shortDone=1;
    }

    if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone>200){
        pathLength-=3;
        path[pathLength]='B';
        shortDone=1;
    }

    if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone>200){
        pathLength-=3;
        path[pathLength]='S';
        shortDone=1;
    }

    path[pathLength+1]='D';
    path[pathLength+2]='D';
    pathLength++;
}


void replay(){
    readSensors();

    if(leftFarReading<200 && rightFarReading<200){
        straight();
    }
    else{
        if(path[readLength]=='D'){
            analogWrite(leftMotor1, 50);
            analogWrite(leftMotor2, 0);
            analogWrite(rightMotor1, 50);
            analogWrite(rightMotor2, 0);
            delay(100);
            analogWrite(leftMotor1, 0);
            analogWrite(leftMotor2, 0);
            analogWrite(rightMotor1, 0);
            analogWrite(rightMotor2, 0);
            //endMotion();
        }
        if(path[readLength]=='L'){
            analogWrite(leftMotor1, 50); //go straight and turn left
            analogWrite(leftMotor2, 0);
            analogWrite(rightMotor1, 50);
            analogWrite(rightMotor2, 0);
            delay(leapTime);
            turnLeft();
        }
        if(path[readLength]=='R'){
            analogWrite(leftMotor1, 50); //go straight and turn right
            analogWrite(leftMotor2, 0);
            analogWrite(rightMotor1, 50);
            analogWrite(rightMotor2, 0);
            delay(leapTime);
            turnRight();
        }
        if(path[readLength]=='S'){
            analogWrite(leftMotor1, 50);
            analogWrite(leftMotor2, 0);
            analogWrite(rightMotor1, 50);
            analogWrite(rightMotor2, 0);
            delay(leapTime);
            straight();
        }

        readLength++;
    }

    replay();
}
