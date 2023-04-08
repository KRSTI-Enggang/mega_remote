#include <Servo.h>
int servoCount = 25;
int servoPins[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
Servo servos[25];

void setup() {
  Serial.begin(115200);
  AttachServos();
}

void loop() {
}

void serialEvent() {
  int channel;
  int pos;
  
  channel = Serial.readStringUntil(':').toInt();
  //pos = Serial.readStringUntil('*').toInt();
  pos = Serial.readString().toInt();
  servos[channel].write(pos);
  Serial.print(channel  );
  Serial.println(pos);
}

void AttachServos() {
  for(int i = 0; i < servoCount; i++) 
  {
    servos[i].attach(servoPins[i]);
  }
 }