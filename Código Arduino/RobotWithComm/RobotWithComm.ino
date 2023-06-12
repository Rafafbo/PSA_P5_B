#include <Servo.h>
#include "constants.h"
#include <Wire.h>

int Move = 0;
int Passo = 0;
int Speed = 0;
int Velocidade;

Servo hipL;
Servo hipR;
Servo kneeL;
Servo kneeR;
Servo ankleL;
Servo ankleR;

void updateServoPos(int target1, int target2, int target3, char leg){
  if (leg == 'l'){
    hipL.write(hipLOffset + target1 + 35 + 10);
    kneeL.write(kneeLOffset + target2 - 5);
   // ankleL.write(2*ankleLOffset - target3);
  }
  else if (leg == 'r'){
    hipR.write(hipROffset - target1 - 35 - 10);
    kneeR.write(kneeROffset - target2 + 5 );
    //ankleR.write(target3);
  }
}

void pos(float x, float z, char leg){
  float hipRad2 = atan(x/z);
  float hipDeg2 = hipRad2 * (180/PI);

  float z2 = z/cos(hipRad2);

  float hipRad1 = acos((sq(l1) + sq(z2) - sq(l2))/(2*l1*z2));
  float hipDeg1 = hipRad1 * (180/PI);
  
  float kneeRad = PI - acos((sq(l1) + sq(l2) - sq(z2))/(2*l1*l2));

  float ankleRad = PI/2 + hipRad2 - acos((sq(l2) + sq(z2) - sq(l1))/(2*l2*z2));
  
  float hipDeg = hipDeg1 + hipDeg2;
  float kneeDeg = kneeRad * (180/PI);
  float ankleDeg = ankleRad * (180/PI);

//  Serial.print(hipDeg);
//  Serial.print("\t");
//  Serial.print(kneeDeg);
//  Serial.print("\t");
//  Serial.println(ankleDeg);

  updateServoPos(hipDeg, kneeDeg, ankleDeg, leg);  
}

void takeStep(float stepLength, int stepVelocity){
  for (float i = stepLength; i >= -stepLength; i-=0.5){
    pos(i, stepHeight, 'r');
    pos(-i, stepHeight - stepClearance, 'l');
    delay(stepVelocity);
  }

  for (float i = stepLength; i >= -stepLength; i-=0.5){
    pos(-i, stepHeight - stepClearance, 'r');
    pos(i, stepHeight, 'l');
    delay(stepVelocity);
  }
}

void initialize(){
  for (float i = 10.7; i >= stepHeight; i-=0.1){
    pos(0, i, 'l');
    pos(0, i, 'r');
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hipL.attach(9);
  hipR.attach(8);
  kneeL.attach(7);
  kneeR.attach(6);
  ankleL.attach(5);
  ankleR.attach(4);

  hipL.write(hipLOffset);
  kneeL.write(kneeLOffset);
  ankleL.write(ankleLOffset);
  
  hipR.write(hipROffset);
  kneeR.write(kneeROffset);
  ankleR.write(ankleROffset);

  delay(5000);
  
  initialize();
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  Move = Wire.read();
  Passo = Wire.read();
  Speed = Wire.read();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Move\t");
  Serial.print(Move);
  Serial.print("\t");
  Serial.print("Speed\t");
  Serial.print(Speed);
  Serial.print("\t");
  Serial.print("Passo\t");
  Serial.println(Passo);
  
  if(Speed == 1){
    Velocidade = 100;
  }else if(Speed == 2){
    Velocidade = 150;
  }else if(Speed == 3){
    Velocidade = 200;
  }
  if (Move == 1){
    takeStep(Passo, Velocidade);
  }else{
    return;
  }

  
  
  delay(500);
}
