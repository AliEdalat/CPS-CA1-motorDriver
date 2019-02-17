int outputValue = 255;
int analogOutPin1 = 11;
int analogOutPin2 = 10;
int isOn = 1;
const int inPin1 = 2;
const int inPin2 = 4;
const int inPin3 = 7;
const int inPin4 = 8;

void setup() {
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pause_resumption_button = digitalRead(inPin1);
  int increase_speed_button = digitalRead(inPin2);
  int decrease_speed_button = digitalRead(inPin3);
  int change_direction_button = digitalRead(inPin4);
  Serial.println(pause_resumption_button);
  Serial.println(increase_speed_button);
  Serial.println(decrease_speed_button);
  Serial.println(change_direction_button);
  Serial.println(outputValue);
  if(pause_resumption_button == HIGH) {
    if(isOn) {
      analogWrite(analogOutPin1, 0);
      analogWrite(analogOutPin2, 0);
      isOn = 0;
    } else {
      analogWrite(analogOutPin1, outputValue);
      analogWrite(analogOutPin2, 0);
      isOn = 1;
    }
    while(digitalRead(inPin1) == HIGH){
      delay(10);
    }
  } else if(decrease_speed_button == HIGH  && isOn == 1) {
    if(outputValue > 9){
      analogWrite(analogOutPin1, (outputValue - 10));
      analogWrite(analogOutPin2, 0);
      outputValue = outputValue - 10;
      while(digitalRead(inPin3) == HIGH){
        delay(10);
      }
    }
  } else if(increase_speed_button == HIGH  && isOn == 1) {
    if(outputValue < 246){
      analogWrite(analogOutPin1, (outputValue + 10));
      analogWrite(analogOutPin2, 0);
      outputValue = outputValue + 10;
      while(digitalRead(inPin2) == HIGH){
        delay(10);
      }
    }
  } else if(change_direction_button == HIGH && isOn == 1) {
    int temp = analogOutPin1;
    analogOutPin1 = analogOutPin2;
    analogOutPin2 = temp;
    analogWrite(analogOutPin1, outputValue);
    analogWrite(analogOutPin2, 0);
    while(digitalRead(inPin4) == HIGH){
      delay(10);
    }
  } else if(isOn){
    analogWrite(analogOutPin1, outputValue);
    analogWrite(analogOutPin2, 0);
  }
}
