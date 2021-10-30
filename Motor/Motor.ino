void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  digitalWrite(13, 1);
  digitalWrite(12, 0);
  delay(2000);

  digitalWrite(13, 0);
  digitalWrite(12, 1);
  delay(2000);

  digitalWrite(13, 0);
  digitalWrite(12, 0);
  delay(2000);

}
