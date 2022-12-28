#ifndef LED_H
#define LED_H

#include "DIO_Driver/dio.h"

void led_init(uint8_t ledPort, uint8_t ledPin); // output
void led_on(uint8_t ledPort, uint8_t ledPin);
void led_off(uint8_t ledPort, uint8_t ledPin);
void led_toggle(uint8_t ledPort, uint8_t ledPin);

#endif