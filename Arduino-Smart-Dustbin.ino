#include <Servo.h>

Servo myServo;
const int servoPin = 9;
int servoPos;

const int closedPos =  70;
const int openPos = 5;

const int trigPin = 10;
const int echoPin = 11;
int travelTime;
float distance;

void setup() {
  // put your setup code here, to run once:
  
  myServo.attach(servoPin);

  //Close Dustbin by default
  servoPos = closedPos;
  myServo.write(servoPos);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sendSoundWave();                       //Send a sound Wave
  travelTime = pulseIn(echoPin, HIGH);   //Get Travel Time
  distance = travelTime * 0.034/2;       //Calculate Distance in cm 

  //Open and Close Logic
  if(distance < 20){
    openTrash();
    delay(5000);
  }else{
    closeTrash();
  }
   
}

void sendSoundWave(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

void openTrash(){
    while(servoPos > openPos){
      myServo.write(servoPos);
      servoPos-=1;
      delay(30);
  } 
}

void closeTrash(){
    while(servoPos < closedPos){
      myServo.write(servoPos);
      servoPos+=1;
      delay(30);
  } 
}
