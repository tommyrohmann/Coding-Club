#include <IRremote.h>      //must copy IRremote library to arduino libraries
#include <Servo.h>
#define plus 0xA3C8EDDB   //clockwise rotation button
#define minus 0xF076C13B  //counter clockwise rotation button

int RECV_PIN = 2;       //IR receiver pin
Servo servo;
int val;                //rotation angle
bool cwRotation, ccwRotation;  //the states of rotation

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  servo.attach(9);     //servo pin
}

void loop() 
{
    Serial.println(digitalRead(2));
    servo.write(90);
    delay(200);
  }
