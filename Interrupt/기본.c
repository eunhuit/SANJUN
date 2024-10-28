/*
 * GccApplication1.c
 *
 * Created: 2024-09-10 오전 11:32:53
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	PORTA=0xFF;
}

ISR(INT1_vect) {
	PORTA=0x00;
}

 int main(void)
{
	DDRA=0xff;
	EICRA=0b00001011;
	EIMSK=0b00000011;
	sei();
    while (1) 
    {
		
		
    }
}

