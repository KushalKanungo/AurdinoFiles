#include<Servo.h>
 #import <LiquidCrystal.h>
Servo s;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int check[2] = {0, 0};
int app[2] = {5, 6};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  s.attach(7);
  Serial.println("Enter Password");

}

void loop() {
  if (Serial.available()) {
    if (Serial.parseInt() == 1234) {
      if (servoMotor() == 1) {
Auto:
        while (1) {
          fan();
          lamp();
          if (Serial.parseInt() == 2) {
            goto Manual;
          }
        }

Manual:
        while (1) {
          if (Serial.parseInt() == 1) {
            goto Auto;
          }
          Serial.println("man");
          digitalWrite(app[0], check[0]);
          digitalWrite(app[1], check[1]);
          if (digitalRead(2) == 1) {
            check[0] = 1 - check[0];
          }
          if (digitalRead(3) == 1) {
            check[1] = 1 - check[1];
          }

        }

      }
    }
  }
}

int servoMotor() { // Start servo motor and check and return 1 or 0
  s.write(0);  // 30 is in Degree
  for (int i = 0; i < 1000; i++) {
    delay(1);
    if (digitalRead(3) == 1) {
      Serial.println("Person Entered");
      return 1;
    }
  }
  s.write(90);  //130 is in Degree
  for (int i = 0; i < 200; i++) {
    delay(1);
    if (digitalRead(3) == 1) {
      Serial.println("Person Entered");
      return 1;
    }
  }
  lcd_message("Door Closed");
  return 0;
}

void fan() {   // Check temperature and Operate fan

  float raw_temp = analogRead(A5);
  float temp = (raw_temp * 5000) / (1023 * 10);
  if (temp > 25) {
    digitalWrite(5, 1);
    lcd.setCursor(0, 1);
    lcd.print("Fan ON ");
  }
  else if (temp < 25) {
    digitalWrite(5, 0);
    lcd.setCursor(0, 1);
    lcd.print("Fan OFF");
  }
}

void lamp() {  // Check ldr and opearte light
  int ldr_value = analogRead(A0);
  if (ldr_value > 50) {
    lcd.setCursor(0, 0);
    lcd.print("Lamp OFF");
    digitalWrite(6, 0);
  }
  else if (ldr_value < 25) {
    digitalWrite(6, 1);
    lcd.setCursor(0, 0);
    lcd.print("Lamp ON ");
  }
}

void lcd_message(String s) { // Clear LCD and print Message
  lcd.clear();
  lcd.print(s);
}

void switch_Off() {  // Turn Off Fan And Lamp
  digitalWrite(6, 0);
  digitalWrite(5, 0);
}
