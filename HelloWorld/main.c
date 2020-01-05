/*
 * HelloWorld.c
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int cnt = 0;

ISR(TIMER0_OVF_vect) {
  PORTC = PORTC >> 1;
  if( PORTC == 0 ) {
    PORTC = 0b10000000;
  }
}

ISR(ANA_COMP_vect) {
  PORTC = PORTC >> 1;
  if( PORTC == 0 ) {
    PORTC = 0b10000000;
  }
}

void interrupt_test() {
  PORTC=0b10000000;
  TCCR0 = 0b00000101;     // TIMER0 divider = 1024
  TIMSK |= 0b00000010;    // TIMER0 interrupt settings
  OCR0=0xFF;
  sei();
  while (1) 
  {
  }
}

void comp_test() {
  ACSR = 0b01001010;
  PORTC = 0b10101010;
  sei();
  while(1) {}
}

int main(void) {
  DDRB=0x00;
  DDRC=0xFF;
  DDRD=0x00;
  comp_test();
}
