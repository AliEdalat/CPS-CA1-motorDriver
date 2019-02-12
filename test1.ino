int outputValue = 255;
int analogOutPin1 = 11;
int analogOutPin2 = 10;
const int analogInPin1 = A3;
const int analogInPin2 = A2;
const int analogInPin3 = A1;
const int analogInPin4 = A0;

void setup() {
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
}

void loop() {
  int key1 = analogRead(analogInPin1);
  int key2 = analogRead(analogInPin2);
  int key3 = analogRead(analogInPin3);
  int key4 = analogRead(analogInPin4);

  if(key1 != 0) {
    analogWrite(analogOutPin1, 0);
    analogWrite(analogOutPin2, 0);
  } else if(key2 != 0) {
    if(outputValue > 9){
      analogWrite(analogOutPin1, (outputValue - 10));
      analogWrite(analogOutPin2, 0);
      outputValue = outputValue - 10;
    }
  } else if(key3 != 0) {
    if(outputValue < 246){
      analogWrite(analogOutPin1, (outputValue + 10));
      analogWrite(analogOutPin2, 0);
      outputValue = outputValue + 10;
    }
  } else if(key4 != 0) {
    int temp = analogOutPin1;
    analogOutPin1 = analogOutPin2;
    analogOutPin2 = temp;
    analogWrite(analogOutPin1, outputValue);
    analogWrite(analogOutPin2, 0);
  } else {
    analogWrite(analogOutPin1, outputValue);
    analogWrite(analogOutPin2, 0);
  }
}
