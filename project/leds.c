#include <msp430.h>
#include "leds.h"

void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (Oxff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    
  }
  switch_state_change = 0;
}