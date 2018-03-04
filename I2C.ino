#include "I2C.h"
I2C* i2c;
i2c_data_t * i2c_data;


void setup() {
  i2c_data->angle = 53;
  i2c_data->absolute_direction = 89;
	Wire.begin(IRC::);                // join i2c bus with address #8
	Wire.onRequest(writeHandle); // register event
	i2c = new I2C();
}

void loop() {
  //Wire.requestFrom();
}

void writeHandle(int count) {
  int numReq = 32;
  float * floatptr = (float *) malloc (numReq * sizeof(float));
  i2c->read(numReq, floatptr);
}
