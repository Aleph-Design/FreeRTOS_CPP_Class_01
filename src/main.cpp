#include <Arduino.h>
#include <ledApp.h>

// This, is working great
//
Led ledOne(1024, 1, "Blink Led", LED_PIN, 750);


void setup() 
{
  // Led (uint16_t stackSize,        // class BaseTasks's arguments
  //      UBaseType_t priority, 
  //      const char *taskName,
  //      uint8_t ledPin,            // class Led's arguments
  //      uint32_t ticks)
  //
  // MARK
  // Led ledOne(1024, 1, "Blink Led", LED_PIN, 750);
  // ledOne.ledMain();
}

void loop() 
{
  // put your main code here, to run repeatedly:
}