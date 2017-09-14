/*
 Name:		arduinoLavaRc.ino
 Created:	5/28/2017 9:50:44 PM
 Author:	LarsWH
*/
#include <boarddefs.h>
#include <IRremote.h>

int OPEN = 8;
int CLOSE = 7;
#define SILENCE 80

IRsend irsend;

void setup() {
	pinMode(OPEN, INPUT); 
	digitalWrite(OPEN, HIGH); // activate pull-up

	pinMode(CLOSE, INPUT); 
	digitalWrite(CLOSE, HIGH); // activate pull-up
}

void loop() {
	bool toggle = false; // Notice: toggle is never used. This is not in accordance with the spec.

	if (!digitalRead(OPEN)) {
		irsend.sendRC5ext(0x1B, 0x5F, toggle); // Open outwards
	}
	else if (!digitalRead(CLOSE)) {
		irsend.sendRC5ext(0x1B, 0x5E, toggle); // Close inwards
	}
	else {
		irsend.sendRC5(0x00C, 12); // AUTO
	}
	delay(SILENCE);
}
