#include <Servo.h>
#include "constants.h"

Servo hipL;
Servo hipR;
Servo kneeL;
Servo kneeR;
Servo ankleL;
Servo ankleR;

void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
  // put your main code here, to run repeatedly:
}
