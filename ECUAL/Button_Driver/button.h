#ifndef BUTTON_H
#define BUTTON_H
#include "DIO_Driver/dio.h"
void button_init(uint8_t btnPort, uint8_t btnPin);               // input
void button_read(uint8_t btnPort, uint8_t btnPin, uint8_t *dst); // input
#endif