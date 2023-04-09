#include <Servo.h>
Servo servo[25];

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(50);
  for (int i = 2; i <= 26; i++) {
    servo[i - 2].attach(i);
  }
}

void loop() {
  if (Serial.available() > 0) {
    serialEvent();
  }
}

void serialEvent() {
  int pin;
  int pos;
  pin = Serial.readStringUntil(':').toInt();
  //pos = Serial.readStringUntil('*').toInt();
  pos = Serial.readString().toInt();
  servo[pin - 2].write(pos);
  Serial.print("PIN Servo : ");
  Serial.println(pin);
  Serial.print("Derajat Servo : ");
  Serial.println(pos);
}
