 #import <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int rowpins[4] = {7, 6, 5, 4};

String pwd = "4567", usrpwd = "" ;

int values[4][4] = {
  {7, 8, 9, 15},
  {4, 5, 6, 14},
  {1, 2, 3, 13},
  {16, 10, 11, 12},
};

int op={0,0,0,0};

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
  lcd.setCursor(0, 0);
}

char getKey() {
  for (int col = 0; col < 4; col++) {
    digitalWrite(col, 0);
    for (int row = 0; row < 4; row++) {
      if (digitalRead(rowpins[row]) == 0) {
        while (digitalRead(rowpins[row]) == 0);
        return values[row][col];
      }
    }
    digitalWrite(col, 1);
  }
  return 0;
}

void reset() {
  delay(100);
  lcd.clear();
  usrpwd = "";
}

void loop() {
  int k = getKey();
  if (k) {
    if (k < 10) {
      lcd.print(k);
    }
    else if (k == 10) {
      lcd.print(0);
    }
    
  }
}



