#include "I2C.h"
#include <Wire.h>
#include <Arduino.h>


I2C::I2C()
{
  
}

I2C::~I2C()
{
}

bool I2C::write(float * floatptr)
{
	Wire.beginTransmission(CENSORBOARD_ADDRESS);
  
  // Wire.write((byte *) &i2c, sizeof(i2c));
  
  // byte * floatPtr1, floatPtr2;
	// floatPtr1 = (byte *) &i2c.absolute_direction;
  // floatPtr2 = (byte *) &i2c.angle;
	// Wire.write(floatPtr1, 8);
	// Wire.write(floatPtr2, 8);
  int angle, absolute_direction;
  angle = floatptr[1] * ACCURACY;
  absolute_direction = floatptr[0] * ACCURACY;
  Wire.write(absolute_direction);
  Wire.write(angle);
  if (Wire.endTransmission())
    return true;
	return false;
}

bool I2C::read(int numReq, float * floatptr)
{
  Wire.requestFrom(CENSORBOARD_ADDRESS, numReq * sizeof(int));
  int i = 0;
  while (1 < Wire.available() && i < numReq) {
    int x = Wire.read();
    floatptr[i] = x / 100;
    i++;
  }
  if (i != numReq || Wire.available() > 1)
    return false;
  return true;
  /*
  int angle, absolute_direction;
	absolute_direction = Wire.read();
	angle = Wire.read();
  i2c_data->absolute_direction = -1;
  i2c_data->angle = -1;
  i2c_data->absolute_direction = absolute_direction / 100.0;
  i2c_data->angle = angle / 100.0;
  Serial.println(i2c_data->absolute_direction);
  Serial.println(i2c_data->angle);
	if (i2c_data->absolute_direction == -1 || i2c_data->angle == -1)
		return false;
	return true;
  */
}



