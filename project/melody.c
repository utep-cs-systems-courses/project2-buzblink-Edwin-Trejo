#include <msp430.h>
#include "libTimer.h"
#include "melody.h"

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
      __delay_cycles(500);
       }
  }

void melody_play(){
  int i = 1;
  while(i = 1){
  tone(1046,10000);
  tone(1318,10000);
  tone(1568,10000);
  tone(2093,10000);
  tone(1568,10000);
  tone(1318,10000);
  tone(1046,10000);
  i = 1;
  }
}
