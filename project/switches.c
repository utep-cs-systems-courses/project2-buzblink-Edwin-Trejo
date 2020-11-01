#include <msp430.h>
#include "switches.h"
#include "leds.h"
#include "libTimer.h"

char switch_state_downSW1, switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES); //sense if down
  P2IES &= (p2val | ~SWITCHES); //sense if up

  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_downSW1 = (p2val & SW1) ? 0 : 1; //if SW1 is up, then is 0
  switch_state_changed = 1;
  led_dim_update();
  
}
