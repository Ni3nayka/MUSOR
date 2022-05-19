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

void forward(int gradus, int speed) {
  float rad = radians(gradus);
  motor(1,speed*cos(rad-PI/4));
  motor(3,speed*cos(rad+PI/4));
}
