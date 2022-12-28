#include "dio.h"
#include "registers.h"

void dio_init(uint8_t portName, uint8_t pinNumber, uint8_t direction)
{
    switch (portName)
    {
    case PORT_A:
    {
        if (direction == IN)
            DDRA &= ~(1 << pinNumber);
        else if (direction == OUT)
            DDRA |= (1 << pinNumber);
        else  // wrong direction param
            ; // No-op

        break;
    }
    case PORT_B:
    {
        if (direction == IN)
            DDRB &= ~(1 << pinNumber);
        else if (direction == OUT)
            DDRB |= (1 << pinNumber);
        else  // wrong direction param
            ; // No-op

        break;
    }
    case PORT_C:
    {
        if (direction == IN)
            DDRC &= ~(1 << pinNumber);
        else if (direction == OUT)
            DDRC |= (1 << pinNumber);
        else  // wrong direction param
            ; // No-op

        break;
    }
    case PORT_D:
    {
        if (direction == IN)
            DDRD &= ~(1 << pinNumber);
        else if (direction == OUT)
            DDRD |= (1 << pinNumber);
        else  // wrong direction param
            ; // No-op

        break;
    }

    default:
        break;
    }
}
void dio_read(uint8_t portName, uint8_t pinNumber, uint8_t *dst)
{
    switch (portName)
    {
    case PORT_A:
    {
        *dst = (PINA & (1 << pinNumber)) >> pinNumber;
        break;
    }
    case PORT_B:
    {
        *dst = (PINB & (1 << pinNumber)) >> pinNumber;
        break;
    }
    case PORT_C:
    {
        *dst = (PINC & (1 << pinNumber)) >> pinNumber;
        break;
    }
    case PORT_D:
    {
        *dst = (PIND & (1 << pinNumber)) >> pinNumber;
        break;
    }

    default:
        break;
    }
}
void dio_write(uint8_t portName, uint8_t pinNumber, uint8_t value)
{
    switch (portName)
    {
    case PORT_A:
    {
        if (value == LOW)
            PORTA &= ~(1 << pinNumber);
        else if (value == HIGH)
            PORTA |= (1 << pinNumber);
        else  // wrong value param
            ; // No-op

        break;
    }
    case PORT_B:
    {
        if (value == LOW)
            PORTB &= ~(1 << pinNumber);
        else if (value == HIGH)
            PORTB |= (1 << pinNumber);
        else  // wrong value param
            ; // No-op

        break;
    }
    case PORT_C:
    {
        if (value == LOW)
            PORTC &= ~(1 << pinNumber);
        else if (value == HIGH)
            PORTC |= (1 << pinNumber);
        else  // wrong value param
            ; // No-op

        break;
    }
    case PORT_D:
    {
        if (value == LOW)
            PORTD &= ~(1 << pinNumber);
        else if (value == HIGH)
            PORTD |= (1 << pinNumber);
        else  // wrong value param
            ; // No-op

        break;
    }

    default:
        break;
    }
}
void dio_toggle(uint8_t portName, uint8_t pinNumber)
{
    switch (portName)
    {
    case PORT_A:
    {
        PORTA ^= (1 << pinNumber);
        break;
    }
    case PORT_B:
    {
        PORTB ^= (1 << pinNumber);
        break;
    }
    case PORT_C:
    {
        PORTC ^= (1 << pinNumber);
        break;
    }
    case PORT_D:
    {
        PORTD ^= (1 << pinNumber);
        break;
    }

    default:
        break;
    }
}
