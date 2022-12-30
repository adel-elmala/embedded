#include "application.h"
#include "LED_Driver/led.h"
#include "Button_Driver/button.h"
#include "Timer_Driver/delay.h"
void app_init()
{
    led_init(PORT_A, PIN0);
    // button_init(PORT_A, PIN7);
}
void app_start()
{
    led_toggle(PORT_A, PIN0);
    delay_us(5000);
}
