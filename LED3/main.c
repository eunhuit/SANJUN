/*
 * GccApplication1.c
 *
 * Created: 2024-05-21 오전 9:03:05
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC=0b00000000;
	DDRD=0xFF;
    while (1) 
    {
		PORTD=0b01110000;
		
		_delay_ms(1000);
		PORTC=0x3F;
		_delay_ms(1000);
		
		_delay_ms(1000);
		PORTC=0x06;
		_delay_ms(1000);
		
		_delay_ms(1000);
		PORTC=0x58;
		_delay_ms(1000);
		
		_delay_ms(1000);
		PORTC=0x4F;
		_delay_ms(1000);
		
		_delay_ms(1000);
		PORTC=0x66;
		_delay_ms(1000);
	}
}

