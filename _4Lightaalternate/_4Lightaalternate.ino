void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {

  for (int i = 9; i <= 12; i++) {
    digitalWrite(i, 1);
    delay(200);
    digitalWrite(i, 0);

  }
  
  for (int j = 12; j >= 9; j--) {
    digitalWrite(j, 1);
    delay(200);
    digitalWrite(j, 0);
  }
}
