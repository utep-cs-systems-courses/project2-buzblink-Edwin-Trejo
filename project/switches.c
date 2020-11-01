#include <msp430.h>
#include "switches.h"
#include "leds.h"
#include "libTimer.h"

char switch_state_downSW1,switch_state_downSW2, switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES1 | p2val & SWITCHES2 | p2val & SWITCHES3 | p2val & SWITCHES4); //sense if down
  if(P2IES |= p2val & SWITCHES1){
    P2IES &= (p2val| ~SWITCHES1); //sense if up
  }
  if(P2IES |= p2val & SWITCHES2){
    P2IES &= (p2val| ~SWITCHES2); //sense if up
  }
  
  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES1;
  P2IE |= SWITCHES1;
  P2OUT |= SWITCHES1;
  P2DIR &= ~SWITCHES1;
  P2REN |= SWITCHES2;
  P2IE |= SWITCHES2;
  P2OUT |= SWITCHES2;
  P2DIR &= ~SWITCHES2;
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handlerSW1()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_downSW1 = (p2val & SW1) ? 0 : 1; //if SW1 is up, then is 0
  switch_state_changed = 1;
  led_dim_update();
  
}
void
switch_interrupt_handlerSW2()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_downSW2 = (p2val & SW2) ? 0 : 1; //if SW1 is up, then is 0
  switch_state_changed = 1;
  led_update();
  
}
