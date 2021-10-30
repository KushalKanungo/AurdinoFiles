void setup() {
 Serial.begin(9600);

}

void loop() {
int a= analogRead(A0);
Serial.println(a);
delay(100);
if(a>900){
 digitalWrite(13,1);
 
}
else{
  digitalWrite(13,0);
}
}
