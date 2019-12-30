/*
 * HelloWorld.c
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int cnt = 0;

ISR(TIMER0_OVF_vect) {
  if(cnt == 255){
    cnt=0;
    PORTB=cnt;
  } else {
    PORTB=cnt++;
  }
}

void interrupt_test() {
  DDRB=0xFF;
  DDRD=0x00;
  OCR0=0xFF;
  TCCR0 = 0b00000101;     // TIMER0設定（分周 = 1024)
  TIMSK |= 0b00000010;    // TIMER0オーバーフロー割り込み許可
  sei();
  while (1) 
  {
  }
}

int main(void) {
  interrupt_test();
}
