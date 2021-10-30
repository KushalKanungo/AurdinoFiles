#include<Servo.h>
Servo s;


void setup() {
  s.attach(4);     
}

void loop() {
  s.write(30);  // 30 is in Degree
  delay(500);
  s.write(130);  //130 is in Degree
  delay(1000);  
}
