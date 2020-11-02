#include <msp430.h>
#include "libTimer.h"
#include "melody.h"
#include "switches.h"

void melody_init(){
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}
void tone(int tone, int duration){
  for (int i =0; i<duration; i++){
     CCR0 = tone;
     CCR1 = tone/2;
     __delay_cycles(400);
       }
  }

void melody_play(){
  if(!switch_state_changed){
  tone(3824,10000);
  tone(3034,10000);
  tone(2551,10000);
  tone(3842,10000);
  tone(0,10000);
  }
  switch_state_changed = 1;
}
