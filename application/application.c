#include "application.h"
#include "LED_Driver/led.h"
#include "Button_Driver/button.h"

void app_init()
{
    led_init(PORT_A, PIN0);
    button_init(PORT_A, PIN7);
}
void app_start()
{
    uint8_t btnState = LOW;
    button_read(PORT_A, PIN7, &btnState);
    if (btnState == LOW)
        led_off(PORT_A, PIN0);
    else if (btnState == HIGH)
        led_on(PORT_A, PIN0);
}
