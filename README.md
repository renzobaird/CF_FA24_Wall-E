// CF_FA24_Wall-E
// Ren Baird and Alan Zhou for Wall-E project.

#include <Servo.h>

Servo servo1;  // create servo1 variable
Servo servo2;  // create servo2 variable
Servo servo3;  // create servo3 variable
Servo servo4;  // create servo4 variable
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 7;
const int buttonPin4 = 8;

void setup() {
  servo1.attach(3);  // attaches the servo on pin 3 
  servo2.attach(5);  // attaches the servo on pin 5
  servo3.attach(6);  // attaches the servo on pin 6
  servo4.attach(9);  // attaches the servo on pin 9
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

void loop() {
  if (digitalRead(buttonPin1) == HIGH){
    servo1.write(180); // tells servo what angle to turn 
  } else {
    servo1.write(0);
  }
  if (digitalRead(buttonPin2) == HIGH){
    servo2.write(180); // tells servo what angle to turn 
  } else {
    servo2.write(0);
  }
  if (digitalRead(buttonPin3) == HIGH){
    servo3.write(180); // tells servo what angle to turn 
  } else {
    servo3.write(0);
  }
  if (digitalRead(buttonPin4) == HIGH){
    servo4.write(180); // tells servo what angle to turn 
  } else {
    servo4.write(0);
  }
}
