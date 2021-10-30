void setup() {
 Serial.begin(9600);

}

void loop() {
float a= analogRead(A0);
float temp=(a*5000)/(1023*10);

delay(10);

}
