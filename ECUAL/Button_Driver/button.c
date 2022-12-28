#include "button.h"

void button_init(uint8_t btnPort, uint8_t btnPin) // input
{
    dio_init(btnPort, btnPin, IN);
}
void button_read(uint8_t btnPort, uint8_t btnPin, uint8_t *dst) // input
{
    dio_read(btnPort, btnPin, dst);
}