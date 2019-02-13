#include <Stepper.h> 
#define STEPS 36
#define GEAR_RATIO 64
const int analogIn2 = A2;
const int analogIn1 = A1;
const int analogIn0 = A0;
int val;
Stepper stepper(STEPS, 8, 10, 9, 11);
int clockWise, antiClock, stoppage;
void setup() {
   stepper.setSpeed(200);
   val = GEAR_RATIO;
}

void loop() {
  clockWise = analogRead(analogIn2);
  antiClock = analogRead(analogIn1);
  stoppage = analogRead(analogIn0);
  if (clockWise != 512) {
    if (val < 0)
      val = -GEAR_RATIO;
  } else if (antiClock != 512) {
    if (val > 0)
      val = -GEAR_RATIO;
  } else if (stoppage != 512) {
      val = 0;
  }
  stepper.step(val);
}
