#include <Wire.h>
#include "I2C.h"

I2C::I2C(bool isMaster) {
	
}

I2C::~I2C() {

}

bool I2C::write(i2c_data_t data) {

	return true;
}

bool I2C::read(i2c_data_t* dst) {
	if (dst == NULL) return false;
	*dst = receivedData;
	return true;
}

