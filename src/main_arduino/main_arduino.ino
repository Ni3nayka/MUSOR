#include "motor.h"

void setup(){
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()) {
    char t = Serial.read();
    if      (t=='F') forward(0,100);
    else if (t=='S') forward(0,0);
    else if (t=='B') forward(180,100);
    else if (t=='L') forward(-90,100);
    else if (t=='R') forward(90,100);
    //else if (t=='0') M = 0;
    //else if (t=='5') M = 50;
    //else if (t=='q') M = 100;
  }
}

/*
    int valLX = map(ps2x.Analog(PSS_LX), 0, 256, -MAX_SPEED, MAX_SPEED);
    int valLY = map(ps2x.Analog(PSS_LY), 256, 0, -MAX_SPEED, MAX_SPEED); // инвертируем
    int valRX = map(ps2x.Analog(PSS_RX), 0, 256, -MAX_SPEED, MAX_SPEED);
    int valRY = map(ps2x.Analog(PSS_RY), 256, 0, -MAX_SPEED, MAX_SPEED); // инвертируем

    int dutyFR = valLY + valLX;
    int dutyFL = valLY - valLX;
    int dutyBR = valLY - valLX;
    int dutyBL = valLY + valLX;

    dutyFR += valRY - valRX;
    dutyFL += valRY + valRX;
    dutyBR += valRY - valRX;
    dutyBL += valRY + valRX;

    // ПЛАВНЫЙ контроль скорости, защита от рывков
    motorFR.smoothTick(dutyFR);
    motorBR.smoothTick(dutyBR);
    motorFL.smoothTick(dutyFL);
    motorBL.smoothTick(dutyBL);
 */


void forward(int gradus, int speed) {
  float rad = radians(gradus);
  motor(1,speed*cos(rad-PI/4));
  motor(3,speed*cos(rad+PI/4));
}
