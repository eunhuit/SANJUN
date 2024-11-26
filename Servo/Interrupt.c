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
    }
}
