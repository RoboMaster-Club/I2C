#include "I2C.h"
I2C* i2c;

void setup() {
	Wire.begin(8);                // join i2c bus with address #8
	Wire.onReceive(readHandle); // register event
	i2c = new I2C(false);
}

void loop() {

}

void readHandle(int count) {
	while (1 < Wire.available()) { // loop through all but the last
		char c = Wire.read(); // receive byte as a character
		Serial.print(c);         // print the character
	}
	int x = Wire.read();    // receive byte as an integer
	Serial.println(x);         // print the integer
}