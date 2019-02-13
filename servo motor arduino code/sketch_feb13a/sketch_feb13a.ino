/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>


int servo_input_1 = 2;
int servo_input_2 = 4;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 700;    // variable to store the servo position
int value = 0;

void setup() {
  pinMode(servo_input_1, INPUT);
  pinMode(servo_input_2, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(150);                       // waits 15ms for the servo to reach the position
//    Serial.print(pos);
//    Serial.println();
//    if (pos == 45)
//      delay(1000);
//     if (pos == 40)
//      delay(1000);
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(150);                       // waits 15ms for the servo to reach the position
//    Serial.print(pos);
//    Serial.println();
//  }
  value = digitalRead(servo_input_1);
  if ( value == HIGH )
  {
    pos -= 4; 
    Serial.print(pos);
    Serial.println();
    delay(40);
  }
  myservo.write(map(pos, 0, 1023, 0, 180));
}
