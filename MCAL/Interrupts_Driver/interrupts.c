#include "interrupts.h"
#include "registers.h"
void sei(void)
{
    SREG |= 0x80;
}

void cli(void)
{
    SREG &= 0x7F;
}

void enable_ext0(void)
{
    sei();
    MCUCR |= 0x03;
    GICR |= 0x40;
}