
#ifndef _I2C_H_
#define _I2C_H_

typedef struct i2c_data_t {
	long encoder_front_left;
	long encoder_rear_left;
	long encoder_front_right;
	long encoder_rear_right;
} i2c_data_t;

template <class T>
class I2C {
public:
  I2C(int);
	bool write(const T&);
	bool read(T&);
};

template <class T> I2C<T>::I2C(int address) {
  Wire.begin(address);
  
}

template <class T> bool I2C<T>::write(const T& data)
{
  const unsigned char * p = (const unsigned char*)&data;
  size_t size = sizeof data;
  unsigned int i = 0;
  for (; i < size; i++)
    Wire.write(*p++);
  return i == size;
}

template <class T> bool I2C<T>::read(T& data)
{
  unsigned char * p = (unsigned char*)&data;
  size_t size = sizeof data;
  unsigned int i = 0;
  for (; i < size; i++)
    *p++ = Wire.read();
  return i == size;
}

#endif	