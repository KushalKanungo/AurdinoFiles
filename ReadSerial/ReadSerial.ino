void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 

}

void loop() {
 if(Serial.available()){
  int v=Serial.parseInt();
  digitalWrite(13,v);
  
//  char ch=Serial.read()
  }

}
