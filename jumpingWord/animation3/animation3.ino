 #import <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  String text = "KUSHAL";
  int len = text.length();
  lcd.setCursor(0, 0);
  lcd.print(text);
  delay(500);
  for (int i = 0; i < len; i++) {
//    char c = text.charAt(i);
    for (int j = i; j >= 0; j--) {
      lcd.setCursor(j - 1, 0);
      lcd.print(text[i]);
      lcd.print(" ");
      delay(100);
    }
    delay(100);
  }
}
