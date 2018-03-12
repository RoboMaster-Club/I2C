#include <Wire.h>
#include "I2C.h"

int newData = 0;
i2c_data_t data;
I2C<i2c_data_t> i2c(0x04);

void setup() {
	Serial.begin(9600);
	Wire.onRequest(requestHandler);
  Wire.onReceive(receiveHandler);
}

void loop() {
  if(newData) {
    Serial.println(data.encoder_front_left);
    Serial.println(data.encoder_rear_left);
    Serial.println(data.encoder_front_right);
    Serial.println(data.encoder_rear_right);
    data.encoder_front_left = 200;
    data.encoder_rear_left = 200;
    data.encoder_front_right = -200;
    data.encoder_rear_right = -200;
    newData = 0;
  }
}

void receiveHandler(int count) {
  i2c.read(data);
  newData = 1;
}

void requestHandler() {
  i2c.write(data);
}
