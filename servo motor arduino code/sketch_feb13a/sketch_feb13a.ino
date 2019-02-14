/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int servo_pin = 9;
int servoInputRotateClockwise = 2;
int servoInputRotateCounterClockwise = 4;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 140;    // variable to store the servo position
int value = 0;

void setup() {
  pinMode(servoInputRotateClockwise, INPUT);
  pinMode(servoInputRotateClockwise, INPUT);
  pinMode(servo_pin, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  
  value = digitalRead(servoInputRotateClockwise);
  if (value == HIGH)
  {
    while ( digitalRead(servoInputRotateClockwise) == HIGH ) delay(10);
    pos -= 2;
  }

  value = digitalRead(servoInputRotateCounterClockwise);
  if (value == HIGH)
  {
    while ( digitalRead(servoInputRotateCounterClockwise) == HIGH ) delay(10);
    pos += 2;
  }


  Serial.print(pos);
  Serial.println();
  myservo.write(pos);
}
