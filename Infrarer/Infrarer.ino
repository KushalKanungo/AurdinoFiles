void setup() {
 Serial.begin(9600);
}

void loop() {
int a= analogRead(A0);
Serial.println(a);
delay(10);
if(a<750){
 digitalWrite(13,1); 
}
else{
  digitalWrite(13,0);
}
}
