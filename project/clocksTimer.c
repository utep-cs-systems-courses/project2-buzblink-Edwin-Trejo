#include <msp430.h>
#include "libTimer.h"

void configureClocks(){
  WDTCTL = WDTPW = WDTHOLD; //disable timer
  BSCTL1 = CALBC1_16MHZ;    //Set DCO 16 Mhz
  DCOTL = CALDCO_16MHZ;

  BCSTL2 &= ~(SELS);
  BCSCTL2 |=DIVS_3;
}

void enableWDTInterrupts()
{
  WDTCTL = WDTPW |
    WDTTMSEL |    //interval mode
    WDTCNTCL |    //clear watchdog count
    1;            //divide SMCLK by 8192
  IE1 |= WDTIE; //enable interval timer interrupt
}

void timerAUpmode()
{
  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;

  TACTL = TASSE;_2 + MC_1;
}
 
