#include "motor.h"

#include <SoftwareSerial.h>
SoftwareSerial bluetooth_serial(A5,A4); // RX, TX

#define BT_Serial bluetooth_serial
#include <Trackduino_bluetooth.h>
Bluetooth bluetooth;

//#define TEST_SERIAL bluetooth//Serial
#define MAX_SPEED 100


void joystick_to_motor(int PSS_LX=0, int PSS_LY=0, int PSS_RX=0, int PSS_RY=0) {
    int valLX = map(PSS_LX, -100, 100, -MAX_SPEED, MAX_SPEED);
    int valLY = map(PSS_LY, -100, 100, -MAX_SPEED, MAX_SPEED); // инвертируем
    int valRX = map(PSS_RX, -100, 100, -MAX_SPEED, MAX_SPEED);
    int valRY = map(PSS_RY, -100, 100, -MAX_SPEED, MAX_SPEED); // инвертируем

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

void setup(){
  Serial.begin(9600);
  bluetooth_serial.begin(9600);
  bluetooth.setup();
}

void loop(){
  /*if (TEST_SERIAL.available()) {
    char t = TEST_SERIAL.read();
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
  }*/
  
  bluetooth.update();
  joystick_to_motor(bluetooth.x,bluetooth.y,bluetooth.z,bluetooth.w);
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
