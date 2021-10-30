int pins[4] = {12, 11, 10, 9,};
char data[4] = {'a', 'b', 'c', 'd', };
int check[4] = {0, 0, 0, 0};
void setup() {
  for (int i = 12; i >= 9; i--) {
    pinMode(i, OUTPUT);
    Serial.begin(9600);
  }
}
void loop() {
  if (Serial.available()) {
    for (int i = 0; i < 4; i++) {
      char value = Serial.read();
      if (value == data[i]) {
        check[i] = 1-check[i];
        digitalWrite(pins[i], check[i]);
      }
    }
  }
}

