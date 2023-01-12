#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_3

#define ISR(vector)                                  \
    void vector(void) __attribute__((signal, used)); \
    void vector(void)

void sei(void);
void cli(void);
void enable_ext0(void);

#endif