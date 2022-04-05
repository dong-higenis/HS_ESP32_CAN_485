#include "HS_ESP32_CAN485.h"

HS_ESP32_CAN_485::HS_ESP32_CAN_485(void)
{
}

HS_ESP32_CAN_485::~HS_ESP32_CAN_485()
{ 
}



void taskUpdate( void *pvParameters );

void taskUpdate(void *pvParameters) 
{
  HS_JOY_ESP32 *p_class =  (HS_ESP32_CAN_485 *)pvParameters;
  
  for (;;)
  {
    p_class->update();
    vTaskDelay(2);
  }
}

bool HS_ESP32_CAN_485::begin(int baud)
{
  driverInit();
  Serial.begin(baud);    

  xTaskCreatePinnedToCore(
    taskUpdate
    ,  "update"
    ,  4*1024   // Stack size
    ,  (void *)this
    ,  1        // Priority
    ,  NULL 
    ,  1);
    
  // disable brownout detector
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  return true;
}


bool HS_ESP32_CAN_485::update(void)
{
  return true;
}
