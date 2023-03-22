#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const int buzzer = 9;
const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  Serial.begin(9600);
  digitalWrite(buzzer, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(buzzer, LOW);   // turn the LED off by making the voltage LOW
  delay(500);
}

void loop() {
  char text[32] = "";
  
  if (radio.available()) {
    //digitalWrite(buzzer, HIGH);  // turn the LED on (HIGH is the voltage level)
    //delay(20);                      // wait for a second
    //digitalWrite(buzzer, LOW);   // turn the LED off by making the voltage LOW
    //delay(20);
    radio.read(&text, sizeof(text));
    String transData = String(text);
    Serial.println(transData);
    if (transData == "nrftest") {
      digitalWrite(buzzer, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(20);                      // wait for a second
      digitalWrite(buzzer, LOW);   // turn the LED off by making the voltage LOW
      delay(20);
      }
  }
  //digitalWrite(buzzer, HIGH);  // turn the LED on (HIGH is the voltage level)
  //delay(20);                      // wait for a second
  //digitalWrite(buzzer, LOW);   // turn the LED off by making the voltage LOW
  //delay(20);
}