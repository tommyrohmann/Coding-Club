/*
---- Transmitter Code ----
Mert Arduino Tutorial & Projects (YouTube)
Please Subscribe for Support
*/

#include <SPI.h>                      //the communication interface with the modem
#include "RF24.h"                     //the library which helps us to control the radio modem

int msg[1];

RF24 radio(5,10);                     //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  radio.begin();                      //it activates the modem.
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
}

void loop(void){
  msg[0] =  analogRead(0); 
  radio.write(msg, 1);
}
