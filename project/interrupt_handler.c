#include <msp430.h>
#include "statemachines.h"
#include "switches.h"

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){
    P2IGF &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
