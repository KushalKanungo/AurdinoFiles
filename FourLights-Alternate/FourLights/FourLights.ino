void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(12, 1);
  digitalWrite(10, 1);
  digitalWrite(9, 0);
  digitalWrite(11, 0);
  delay(500);
  digitalWrite(12, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 1);
  digitalWrite(11, 1);
  delay(500);
  // put your main code here, to run repeatedly:

}
