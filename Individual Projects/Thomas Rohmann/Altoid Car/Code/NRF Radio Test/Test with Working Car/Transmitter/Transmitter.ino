#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const int buzzer = 10;
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(1);
  digitalWrite(buzzer, LOW);
  const char text[] = "nrftest";
  radio.write(&text, sizeof(text));
}