#if !defined(LED_APP_H)
#define LED_APP_H

#include <Arduino.h>

#define LED_PIN 14


class BaseTask
{
    public:
        BaseTask (uint16_t stackSize, UBaseType_t priority, 
                                      const char *taskName = "")
        {
            xTaskCreatePinnedToCore (blinkLed, taskName, stackSize, this, 
                                     priority, &this->taskHandle, 1);
        }

        // MARK
        // virtual void ledMain() = 0;
        virtual void main() = 0;

    protected:
        static void blinkLed (void *pvParam)
        {
            BaseTask *pBaseTask = static_cast<BaseTask*>(pvParam);

            // MARK
            // pBaseTask->ledMain();
            pBaseTask->main();

        }

        TaskHandle_t taskHandle;

};  // end class BaseTask() --------------------------------------------------



class Led : public BaseTask
{
    private:
        uint8_t  _ledPin;
        uint32_t _ticks;

    public:
        Led (uint16_t stackSize,        // class BaseTasks's arguments
             UBaseType_t priority, 
             const char *taskName,
             uint8_t ledPin,            // class Led's arguments
             uint32_t ticks) :
             BaseTask{ stackSize, priority, taskName },
             _ledPin{ ledPin },
             _ticks{ ticks }
             {
                 pinMode(this->_ledPin, OUTPUT);
             }

        // MARK
        // void ledMain() override
        void main() override
        {
            for (;;)
            {
                digitalWrite(this->_ledPin, digitalRead(this->_ledPin) ^ 1);

                vTaskDelay( this->_ticks);
            }
        }

};  // end class Led() -------------------------------------------------------


#endif // LED_APP_H
