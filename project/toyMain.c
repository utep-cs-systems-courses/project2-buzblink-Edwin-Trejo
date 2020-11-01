#include <msp430.h>


int main(void){
  led_init();

  or_sr(0x18);
}
