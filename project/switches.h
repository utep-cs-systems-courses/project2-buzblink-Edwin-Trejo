#ifndef switches_included
#define switches_included

#define SW1 BIT0              //SW1 is p2.0
//#define SW2 BIT1              //SW2 is p2.1
//#define SW3 //switch 3
//define SW4 //switch 4

#define SWITCHES SW1
//#define SWITCHES SW2
//#define SWITCHES SW3
//#define SWITCHES SW4

void switch_init();
void switch_interrupt_handler();

extern char switch_state_downSW1, switch_state_changed;

#endif
