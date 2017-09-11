/*
 Name:		Sony2Lava.ino
 Created:	5/28/2017 9:50:44 PM
 Author:	lars
*/
#include <Arduino.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>


int IN_KEY1 = 8;
int IN_KEY2 = 7;

IRsend irsend;

//decode_results results;
bool serial = false;


void setup() {
	if (serial) {
		Serial.begin(115200);
	}

	pinMode(IN_KEY1, INPUT); 
	digitalWrite(IN_KEY1, HIGH);

	pinMode(IN_KEY2, INPUT); 
	digitalWrite(IN_KEY2, HIGH);
	
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);

	if (serial) {
		Serial.println("Hello!");
	}
}

void loop() {
	bool toggle = false;
	digitalWrite(LED_BUILTIN, HIGH);

	if (!digitalRead(IN_KEY1)) {
		irsend.sendRC5ext(0x1B, 0x5F, toggle); // OUT
		if (serial) {
			Serial.println("Out");
		}
	}
	else if (!digitalRead(IN_KEY2)) {
		irsend.sendRC5ext(0x1B, 0x5E, toggle); // IN
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
