#ifndef switches_included
#define switches_included

#define SW1 BIT0              //switch1 is p2.0
//#define SW2 
//#define SW3 //switch 3
//define SW4 //switch 4

#define SWITCHES SW1           //4 switches on this board

void switch_init();
void switch_interrupt();

extern char switch_state_down, switch_state_changed;

#endif
