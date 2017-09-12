/*
 Name:		arduinoLavaRc.ino
 Created:	5/28/2017 9:50:44 PM
 Author:	LarsWH
*/
#include <Arduino.h>
#include <boarddefs.h>
#include <IRremote.h>

int OPEN = 8;
int CLOSE = 7;

IRsend irsend;

bool serial = false;


void setup() {
	if (serial) {
		Serial.begin(115200);
	}

	pinMode(OPEN, INPUT); 
	digitalWrite(OPEN, HIGH);

	pinMode(CLOSE, INPUT); 
	digitalWrite(CLOSE, HIGH);
	
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);

	if (serial) {
		Serial.println("Hello!");
	}
}

void loop() {
	bool toggle = false;
	digitalWrite(LED_BUILTIN, HIGH);

	if (!digitalRead(OPEN)) {
		irsend.sendRC5ext(0x1B, 0x5F, toggle); // Open outwards
		if (serial) {
			Serial.println("Out");
		}
	}
	else if (!digitalRead(CLOSE)) {
		irsend.sendRC5ext(0x1B, 0x5E, toggle); // Close inwards
		if (serial) {
			Serial.println("In");
		}
	}
	else {
		irsend.sendRC5(0x00C, 12); // AUTO
		if (serial) {
			Serial.println("Auto");
		}
	}
	digitalWrite(LED_BUILTIN, LOW);
	
}
