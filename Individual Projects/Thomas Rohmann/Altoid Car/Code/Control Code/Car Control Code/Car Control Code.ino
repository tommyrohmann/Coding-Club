#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const int buzzer = 10;
const int headLights = A3;
const int tailLightR = A4;
const int tailLightL = A5;
const int steering = A6;
const int forward = 2;
const int reverse = 3;
const byte address[6] = "00001";
int clock = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(headLights, OUTPUT);
  pinMode(tailLightR, OUTPUT);
  pinMode(tailLightL, OUTPUT);
  pinMode(steering, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(reverse, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  Serial.begin(9600);
  digitalWrite(buzzer, LOW);
  digitalWrite(headLights, HIGH);
}

void loop() {
  clock = clock + 1;
  delay(1);
  if (clock > 49){
    clock = 0;
  }



  
  Serial.println(clock);
  char text[32] = "";
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    String transData = String(text);
    Serial.println(transData);
    if (transData == "nrftest") {
      if (clock > 24){
      analogWrite(tailLightR, 130);
      analogWrite(tailLightL, 255);                      // wait for a second
      }
    else{
      analogWrite(tailLightR, 0);
      analogWrite(tailLightL, 0);
    }
      }
  }

}