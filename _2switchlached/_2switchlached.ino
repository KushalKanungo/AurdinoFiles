void setup() {
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
  pinMode(8, INPUT);
  digitalWrite(10, 1);
  digitalWrite(8, 1);

}

void loop() {
  if (digitalRead(8) == 0) {
    while (digitalRead(8) == 0) {}
    digitalWrite(13, 0);
  }

  if ((digitalRead(10) == 0)) {
    while (digitalRead(10) == 0) {}
    digitalWrite(13, 1);
  }

}
