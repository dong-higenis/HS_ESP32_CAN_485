/*
 * CAN_485.h 
 */

#ifndef HS_ESP32_CAN_485_H_
#define HS_ESP32_CAN_485_H_

#include <Arduino.h>


class HS_ESP32_CAN_485
{
  public:
    HS_ESP32_CAN_485();
    ~HS_ESP32_CAN_485();

    bool begin(int baud);
    bool update(void);
    
  private:
};

extern HS_ESP32_CAN_485 can485;

#endif  /* HS_ESP32_CAN_485_H_ */