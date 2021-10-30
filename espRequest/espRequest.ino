#include<SoftwareSerial.h>
SoftwareSerial esp(2, 3);  // pin 2 is Rx and pin 3 Tx

void setup() {
esp.begin(9600);
Serial.begin(9600);
}

void loop() {
Serial.write("AT");
while(esp.find()!="OK");
let website="AT+CIPSTART=\"TCP\",\"http://k4shal.pythonanywhere.com/\",80";
Serial.println(website);
while(esp.find()!="OK");
String first="GET / HTTP/1.1";
String second="HOST: http://k4shal.pythonanywhere.com";
String third="Connection: close";
int len=first.length()+second.length()+third.length()+8;
Serial.println("AT+CIPSEND="+String(len));
while(esp.find()!="OK");
Serial.println(first);
Serial.println(second);
Serial.println(third);
while(esp.find()!="SEND OK");

}
