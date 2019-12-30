/*
 * HelloWorld.c
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int cnt = 0;

ISR(TIMER0_OVF_vect) {
  PORTB = PORTB >> 1;
  if( PORTB == 0 ) {
    PORTB = 0b10000000;
  }
}

void interrupt_test() {
  DDRB=0xFF;
  DDRD=0x00;
  OCR0=0xFF;
  PORTB=0b10000000;
  TCCR0 = 0b00000101;     // TIMER0 divider = 1024
  TIMSK |= 0b00000010;    // TIMER0 interrupt settings
  sei();
  while (1) 
  {
  }
}

int main(void) {
  interrupt_test();
}
