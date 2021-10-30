// COnnect VCC to 5V
// Ground to Ground
// A0 pin to  arduino analog pin 
void setup() {
  Serial.begin(9600);
}
void loop() {
 int a= analogRead(A0);
 Serial.println(a);
delay(300);
}
