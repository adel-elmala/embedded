#include "application.h"
#include "LED_Driver/led.h"
#include "Button_Driver/button.h"
#include "Timer_Driver/delay.h"
#include "Interrupts_Driver/interrupts.h"

uint8_t count = 0;

void app_init()
{
    led_init(PORT_A, PIN0);
    led_init(PORT_A, PIN1);
    led_init(PORT_A, PIN2);
    enable_ext0();

    // button_init(PORT_A, PIN7);
}
void app_start()
{
    switch (count)
    {
    case 0:
    {
        led_off(PORT_A, PIN0);
        led_off(PORT_A, PIN1);
        led_off(PORT_A, PIN2);
        break;
    }
    case 1:
    {
        led_on(PORT_A, PIN0);

        break;
    }

    case 2:
    {
        /* code */
        led_on(PORT_A, PIN1);

        break;
    }
    case 3:
    {
        /* code */
        led_on(PORT_A, PIN2);

        break;
    }
    default:
        break;
    }
}

ISR(EXT_INT0)
{
    if (count >= 3)
        count = 0;
    else
        count++;
}
