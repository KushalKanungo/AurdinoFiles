 #import <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int rowpins[4] = {7, 6, 5, 4};

String pwd = "4567", usrpwd = "" ;

int bal=12000;
int with=0;
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
  int len = usrpwd.length();
  char c = getKey();

  if (c) {
    if (c == '=' && len == 4) {
      if (usrpwd == pwd ) {
        lcd.clear();
        lcd.print("Welcome");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("1 For Balance");
        lcd.setCursor(0, 1);
        lcd.print("2 For Withdraw");
        while (1) {
          char key = getKey();
          if (key) {

            if (key == '1') {
              lcd.clear();
              lcd.print("Balance is ");
              lcd.print(bal);
            }
            if (key == '2') {
              lcd.clear();
               lcd.print("Enter Withdraw Amt");
               delay(500);
               lcd.clear();
               while(1){
                 char amt=getKey();
                 int intamt=(int)amt-48;
                 if(intamt<=9){
                  lcd.print(amt);
                  with=with*10+(intamt);
                  }
                  else if(amt='='){
                     bal=bal-with;
                     lcd.clear();
                     lcd.print("New Bal");
                     lcd.print(bal);
                     return;
                    }
                
                }
               
              
            }

          }
        }
      }
    
    else {
      lcd.clear();
      lcd.print("Wrong Password");
      delay(200);
      reset();
    }
    }

  else if (c == 'C') {
    reset();
  }

  else if (len < 4 && (int)c >= 48 && (int)c < 58) {
    lcd.print(c);
    usrpwd += (String)c;
  }
  
}
}



