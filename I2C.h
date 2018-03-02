#ifndef I2C_H_
#define I2C_H_

typedef struct i2c_data_t {
	float absolute_direction;
	float angle;
};

class I2C {
private:
	i2c_data_t data;

public:
	I2C(i2c_data_t);
	~I2C();

	bool write();
	bool read();
};

#endif