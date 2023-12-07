#include "motor.h"

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(A5,A4); // RX, TX

#define TEST_SERIAL bluetooth//Serial
#define MAX_SPEED 100


void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop(){
  if (TEST_SERIAL.available()) {
    char t = TEST_SERIAL.read();
//    if      (t=='F') forward(0,100);
//    else if (t=='S') forward(0,0);
//    else if (t=='B') forward(180,100);
//    else if (t=='L') forward(-90,100);
//    else if (t=='R') forward(90,100);
    if (t=='F') {
      motor(1,MAX_SPEED);
      motor(2,MAX_SPEED);
      motor(3,MAX_SPEED);
      motor(4,MAX_SPEED);
    }
    else if (t=='S') {
      motor(1,0);
      motor(2,0);
      motor(3,0);
      motor(4,0);
    }
    else if (t=='B') {
      motor(1,-MAX_SPEED);
      motor(2,-MAX_SPEED);
      motor(3,-MAX_SPEED);
      motor(4,-MAX_SPEED);
    }
    else if (t=='L') {
      motor(1,MAX_SPEED);
      motor(2,-MAX_SPEED);
      motor(3,MAX_SPEED);
      motor(4,-MAX_SPEED);
    }
    else if (t=='R') {
      motor(1,-MAX_SPEED);
      motor(2,MAX_SPEED);
      motor(3,-MAX_SPEED);
      motor(4,MAX_SPEED);
    }
  }
}

void joystick_to_motor(int PSS_LX=0, int PSS_LY=0, int PSS_RX=0, int PSS_RY=0) {
    int valLX = map(PSS_LX, 0, 256, -MAX_SPEED, MAX_SPEED);
    int valLY = map(PSS_LY, 256, 0, -MAX_SPEED, MAX_SPEED); // инвертируем
    int valRX = map(PSS_RX, 0, 256, -MAX_SPEED, MAX_SPEED);
    int valRY = map(PSS_RY, 256, 0, -MAX_SPEED, MAX_SPEED); // инвертируем

    int dutyFR = valLY + valLX;
    int dutyFL = valLY - valLX;
    int dutyBR = valLY - valLX;
    int dutyBL = valLY + valLX;

    dutyFR += valRY - valRX;
    dutyFL += valRY + valRX;
    dutyBR += valRY - valRX;
    dutyBL += valRY + valRX;

    // ПЛАВНЫЙ контроль скорости, защита от рывков
    motor(4,dutyFR);
    motor(3,dutyBR);
    motor(1,dutyFL);
    motor(2,dutyBL);
}


void forward(int gradus, int speed) {
//  float rad = radians(gradus);
//  motor(1,speed*cos(rad-PI/4));
//  motor(3,speed*cos(rad+PI/4));0
  motor(1,speed);
  motor(2,speed);
  motor(3,speed);
  motor(4,speed);
}
