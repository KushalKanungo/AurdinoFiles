int ssd[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
int pin[7] = {12, 11, 10, 9, 8, 7, 6};
int select[2] = {0, 1};
int st = 1;
void setup() {

  for (int i = 6; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}
void loop() {

  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int t = 0; t < 5; t++) {
        for (int j = 0; j < 7; j++) {
          digitalWrite(pin[j], ssd[i][j]);
        }
        delay(100);
        digitalWrite(select[0], 0);
        digitalWrite(select[1], 1);

        for (int j = 0; j < 7; j++) {
          digitalWrite(pin[j], ssd[k][j]);
        }
         delay(100);
        digitalWrite(select[0], 1);
        digitalWrite(select[1], 0);
        
      }
    }
  }
}
