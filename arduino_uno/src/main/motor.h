#pragma once
#include <Arduino.h>
#include "AFMotor.h"  //for v1.6

AF_DCMotor AF_DCMotor_motor_1(1);
AF_DCMotor AF_DCMotor_motor_2(2);
AF_DCMotor AF_DCMotor_motor_3(3);
AF_DCMotor AF_DCMotor_motor_4(4);

void motor(byte number, int speed) {
  speed = map(constrain(speed,-100,100),-100,100,-255,255);
  if (number==1) {
    if (speed==0)     AF_DCMotor_motor_1.run(RELEASE);
    else if (speed>0) AF_DCMotor_motor_1.run(FORWARD); 
    else              AF_DCMotor_motor_1.run(BACKWARD);
    AF_DCMotor_motor_1.setSpeed(abs(speed));
  }
  else if (number==2) {
    if (speed==0)     AF_DCMotor_motor_2.run(RELEASE);
    else if (speed>0) AF_DCMotor_motor_2.run(FORWARD); 
    else              AF_DCMotor_motor_2.run(BACKWARD);
    AF_DCMotor_motor_2.setSpeed(abs(speed));
  }
  else if (number==3) {
    if (speed==0)     AF_DCMotor_motor_3.run(RELEASE);
    else if (speed>0) AF_DCMotor_motor_3.run(FORWARD); 
    else              AF_DCMotor_motor_3.run(BACKWARD);
    AF_DCMotor_motor_3.setSpeed(abs(speed));
  }
  else if (number==4) {
    if (speed==0)     AF_DCMotor_motor_4.run(RELEASE);
    else if (speed>0) AF_DCMotor_motor_4.run(FORWARD); 
    else              AF_DCMotor_motor_4.run(BACKWARD);
    AF_DCMotor_motor_4.setSpeed(abs(speed));
  }
}
