// Trigger Pin as Output  
// Echo Pin as  Input
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(13, 0);
  delayMicroseconds(2);
  digitalWrite(13, 1);
  delayMicroseconds(10);
  digitalWrite(13, 0);

   long duration=pulseIn(12,1);
   long distance=((duration/2.0)*0.0343);
    Serial.println(distance);
   delay(100);
}
