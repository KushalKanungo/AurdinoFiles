 #import <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  //  String text[6] = {"K", "U", "S", "H", "A", "L"};
  String text = "KUSHAL";
  int text_length = text.length();s
  for (int i = 0; i < text_length; i++) {
    //    char c = text.charAt(i);
    //  String c=text[i];
    for (int j = 16; j > i - 1; j--) {
      lcd.setCursor(j, 0);
      lcd.print(text[i]);
      lcd.print(" ");
      delay(50);
    }
  }
  exit(0);
}
