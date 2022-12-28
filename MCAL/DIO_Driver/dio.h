#ifndef DIO_H
#define DIO_H

#include "types.h"

// port name macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// pin macros
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// Direction macros
#define IN 0
#define OUT 1

// Value macros
#define LOW 0
#define HIGH 1

void dio_init(uint8_t portName, uint8_t pinNumber, uint8_t direction);
void dio_read(uint8_t portName, uint8_t pinNumber, uint8_t *dst);
void dio_write(uint8_t portName, uint8_t pinNumber, uint8_t value);
void dio_toggle(uint8_t portName, uint8_t pinNumber);

#endif