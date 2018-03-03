#ifndef I2C_H_
#define I2C_H_

typedef struct i2c_data_t {
	float absolute_direction;
	float angle;
};

class I2C {
private:
	i2c_data_t receivedData;
public:
	I2C(bool isMaster); // 0 - master, 1 - slave
	~I2C();

	bool write(i2c_data_t);
	bool read(i2c_data_t*);
	
	void setReceivedData(i2c_data_t);
};

#endif