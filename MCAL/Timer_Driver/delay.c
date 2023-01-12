#include "delay.h"
#include "registers.h"
#include <math.h>
// unsigned int ceil(double num)
// {
//     unsigned int inum = (unsigned int)num;
//     if (num == (double)inum)
//         return inum;

//     return inum + 1;
// }

void delay_ms(unsigned int ms)
{
    double counts_0_prescale = ms / (TICK_TIME_0_PRESCALE * 1000);
    // float counts_8_prescale = ms / TICK_TIME_8_PRESCALE;
    // float counts_64_prescale = ms / TICK_TIME_64_PRESCALE;
    // float counts_256_prescale = ms / TICK_TIME_256_PRESCALE;
    // float counts_1024_prescale = ms / TICK_TIME_1024_PRESCALE;

    unsigned int nOverFlows_0_prescale = ceil((counts_0_prescale / (double)MAX_COUNT));
    // float nOverFlows_8_prescale    = counts_8_prescale  / MAX_COUNT;
    // float nOverFlows_64_prescale   = counts_64_prescale  / MAX_COUNT;
    // float nOverFlows_256_prescale  = counts_256_prescale  / MAX_COUNT;
    // float nOverFlows_1024_prescale = counts_1024_prescale  / MAX_COUNT;

    // set timer control
    uint8_t counts_per_overflow = counts_0_prescale / nOverFlows_0_prescale;

    while (nOverFlows_0_prescale)
    {
        TCNT0 = counts_per_overflow; // set initial value of timer
        TCCR0 = 0x01;                // start timer in normal mode - no prescale
        while ((TIFR & 0x01) == 0)   // poll overflow flag
            ;

        TCCR0 = 0x00; // stop timer
        TIFR |= 0x01; // clear overflow flag

        nOverFlows_0_prescale--;
    }
}
void delay_us(unsigned int us)
{
    float counts_0_prescale = us / (TICK_TIME_0_PRESCALE * 1000000);

    unsigned int nOverFlows_0_prescale = (((counts_0_prescale / MAX_COUNT) + 0.5) * 2) / 2;

    // set timer control
    uint8_t counts_per_overflow = counts_0_prescale / nOverFlows_0_prescale;

    while (nOverFlows_0_prescale)
    {
        TCNT0 = counts_per_overflow; // set initial value of timer
        TCCR0 = 0x01;                // start timer in normal mode - no prescale
        while ((TIFR & 0x01) == 0)   // poll overflow flag
            ;

        TCCR0 = 0x00; // stop timer
        TIFR |= 0x01; // clear overflow flag

        nOverFlows_0_prescale--;
    }
}
