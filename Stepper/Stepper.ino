#include <Stepper.h> 
#define STEPS 18
#define GEAR_RATIO 1
const int digitalIn2 = 2;
const int digitalIn1 = 4;
const int digitalIn0 = 7;
int val;
Stepper stepper(STEPS, 6, 9, 10, 11);
int clockWiseButton, antiClockButton, stopButton;
void setup() {
   pinMode(digitalIn2, INPUT);
   pinMode(digitalIn1, INPUT);
   pinMode(digitalIn0, INPUT);
   stepper.setSpeed(20);
   val = 1;
   Serial.begin(9600);
}

void loop() {
  clockWiseButton = digitalRead(digitalIn2);
  antiClockButton = digitalRead(digitalIn1);
  stopButton = digitalRead(digitalIn0);
//  Serial.println(clockWiseButton);
//  Serial.println(antiClockButton);
//  Serial.println(stopButton);
  if (clockWiseButton == 1) {
//    Serial.println("A");
    if (val <= 0)
      val = 1;
    while(digitalRead(digitalIn2) == HIGH){
      delay(10);
    }
  } else if (antiClockButton == 1) {
//    Serial.println("B");
    if (val >= 0)
      val = -1;
    while(digitalRead(digitalIn1) == HIGH){
      delay(10);
    }
  } else if (stopButton == 1) {
//    Serial.println("C");
    val = 0;
    while(digitalRead(digitalIn0) == HIGH){
      delay(10);    
    }
  }
//  Serial.print(">>"); Serial.println(val);
  stepper.step(val);
}
