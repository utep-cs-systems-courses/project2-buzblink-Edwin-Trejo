#include <msp430.h>
#include "leds.h"
#include "switches.h"
#include "stateMachines.h"
#include "libTimer.h"


unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;   //no LEDS on by deafult

    ledFlags |= switch_state_downSW1 ? LED_GREEN : 0;
    ledFlags |= switch_state_downSW1 ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    
  }
  switch_state_changed = 0;
}
 

void led_dim_update(){
  enableWDTInterrupts();
  if(led_changed){
     char ledFlags = redVal[red_on] | greenVal[green_on];
  
     P1OUT &= (0xff^LEDS) | ledFlags;
     P1OUT |= ledFlags;     
     led_changed = 0;
  }
}
