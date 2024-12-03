#include <Servo.h>
const int buttonPin = 2, buttonPin2 = 4, buttonPin3 = 6, buttonPin4 = 8;
const int ledPin = 11, ledPin2 = 12, ledPin3 = 13;

Servo servo1, servo2, servo3, servo4, plantServo;
bool grow1 = true, grow2 = true, grow3 = true, grow4 = true;

int servoAngle = 0;
float servoSpeed = 0.5;
float timer;
bool forward;
bool autoActive = false;

void setup() {
  grow1 = true, grow2 = true, grow3 = true, grow4 = true;  

  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(7);
  plantServo.attach(9);

  plantServo.write(0);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH){
    servo1.write(180); // tells servo what angle to turn 

    if (grow1) {
      grow1 = false;
      plantServo.write(45); 
    }
  } else { 
    servo1.write(0); 
  }
  if (digitalRead(buttonPin2) == HIGH){
    servo2.write(25);
    autoActive = true;

    if (grow2) {
      grow2 = false;
      plantServo.write(90); 
    }
  } else { 
    servo2.write(80); 
  }

  if (autoActive){
    SpinAuto();
  }

  if ((digitalRead(buttonPin3) == HIGH)) {
    autoActive = false;

    if (grow3) {
      grow3 = false;
      plantServo.write(135); 
    }

    digitalWrite(ledPin3, HIGH);
  }

  if (digitalRead(buttonPin4) == HIGH){
    if (grow4) {
      grow4 = false;
      plantServo.write(180); 
    }

    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin, HIGH);
  } 

  timer = millis();
}

void SpinAuto() {
  if (servoAngle == 120) {
    servo3.write(0);
    servoAngle = 0;
  }
  if (servoAngle == 0) {
    servo3.write(120);
    servoAngle = 120;
  }
}