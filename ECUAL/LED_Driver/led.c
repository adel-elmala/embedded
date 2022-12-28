#include "led.h"

void led_init(uint8_t ledPort, uint8_t ledPin) // output
{
    dio_init(ledPort, ledPin, OUT);
}
void led_on(uint8_t ledPort, uint8_t ledPin)
{
    dio_write(ledPort, ledPin, HIGH);
}
void led_off(uint8_t ledPort, uint8_t ledPin)
{
    dio_write(ledPort, ledPin, LOW);
}
void led_toggle(uint8_t ledPort, uint8_t ledPin)
{
    dio_toggle(ledPort, ledPin);
}