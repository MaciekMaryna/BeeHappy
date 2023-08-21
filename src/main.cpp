#include <Arduino.h>
#define MY_LED    // This pin (GPIO_PIN_COUNT) is forbidden cause deep sleep wakeup reason 
#define SEC_OF_SLEEP       300
#define MICROSEC_PER_SEC   1000000

#define led_toggle(pin_number)   do { digitalWrite(pin_number, !digitalRead(pin_number)); } while (0)

void setup()
{
   Serial.begin(115200);
   delay(1000);   
   //pinMode(MY_LED, OUTPUT);
   Serial.println("Hi! I'm BeHappy System. Now I'm starting fitst time!");
   for (int i = 0; i < 30; i++)
   {
      Serial.println("Hello from serup routine.");      
      delay(1000);
   }
}

void loop(void) 
{


   for (int i = 0; i < 30; i++)
   {
      Serial.println("And Now I'm running in Normal Mode. after wake up.");      
      //led_toggle(MY_LED);
      delay(1000);
   }

   Serial.println("But I'm going to Deep Sleep Mode to save the battery. Bye bye.");
   ESP.deepSleep(SEC_OF_SLEEP * MICROSEC_PER_SEC, WAKE_RF_DEFAULT);
   delay(100);

   Serial.println("You will not to see this message.");
}

