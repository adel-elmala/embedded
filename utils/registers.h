#ifndef REGISTERS_H
#define REGISTERS_H

#include "types.h"

/*------------ ------------ ------------
  ------------ DIO  Registers ----------
  ------------ ------------ ------------ */

// PORT A
#define PORTA (*(volatile uint8_t *)(0x3B))
#define DDRA (*(volatile uint8_t *)(0x3A))
#define PINA (*(volatile uint8_t *)(0x39))

// PORT B
#define PORTB (*(volatile uint8_t *)(0x38))
#define DDRB (*(volatile uint8_t *)(0x37))
#define PINB (*(volatile uint8_t *)(0x36))

// PORT C
#define PORTC (*(volatile uint8_t *)(0x35))
#define DDRC (*(volatile uint8_t *)(0x34))
#define PINC (*(volatile uint8_t *)(0x33))

// PORT D
#define PORTD (*(volatile uint8_t *)(0x32))
#define DDRD (*(volatile uint8_t *)(0x31))
#define PIND (*(volatile uint8_t *)(0x30))

/*------------ ------------ ------------ ------------
  ------------ Timer/Counter 0 Registers ------------
  ------------ ------------ ------------ ------------ */

#define TCNT0 (*(volatile uint8_t *)(0x52))
#define TCCR0 (*(volatile uint8_t *)(0x53))
#define OCR0 (*(volatile uint8_t *)(0x5C))

#define TIFR (*(volatile uint8_t *)(0x58)) // shared btw timers 0/1/2

#endif