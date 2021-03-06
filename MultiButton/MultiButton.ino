 #import <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int rowpins[4] = {7, 6, 5, 4};

char values[4][4] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'},  
};

void setup() {
  lcd.begin(16, 2);
  for (int j = 4; j < 8; j++) {
    pinMode(j, INPUT);  //Rows
    digitalWrite(j, 1);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(i, OUTPUT); //Columns
    digitalWrite(i, 1);
  }
}

void loop() {
  for (int col = 0; col < 4; col++) {
    digitalWrite(col, 0);
    for (int row = 0; row < 4; row++) {
      if (digitalRead(rowpins[row]) == 0) {
        while (digitalRead(rowpins[row]) == 0);
        lcd.setCursor(0, 0);
        lcd.print(values[row][col]);
      }
    }
    digitalWrite(col, 1);
  }
}
