#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    DDRB=0xff;
	TCCR1A = 0b10000010;
	TCCR1B = 0b00011011; 
	ICR1=4608;
	OCR1A=346;
	sei();
    while (1) 
    {
	for(int i=145; i < 554; i++) {
		OCR1A = i;
		_delay_ms(10);
		}
	for(int i=553; i > 146; i--) {
		OCR1A = i;
		_delay_ms(10);
		}
    }
}
