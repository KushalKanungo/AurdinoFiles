#include<SoftwareSerial.h>
SoftwareSerial esp(2, 3);  // pin 2 is Rx and pin 3 Tx

void setup() {
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  if (Serial.available()) {
    esp.write(Serial.read());
  }

  if (esp.available()) {
    Serial.write(esp.read());
  }

}
