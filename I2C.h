#ifndef I2C_H_
#define I2C_H_

class I2C {
private:
	i2c_data_t receivedData;
public:
	I2C();
	~I2C();

  const int VISIONBOARD_ADDRESS = 8;
  const int CENSORBOARD_ADDRESS = 7;
  const int ACCURACY = 100000;
	bool write(float * floatptr); // floatptr[0] is absolute_direction, floatptr[1] is angle.
	bool read(int numReq, float * floatptr);
	
	// void setReceivedData(i2c_data_t);
};

#endif
