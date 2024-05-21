/*
 * GccApplication1.c
 *
 * Created: 2024-05-21 오전 9:03:05
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>
int ctt=0;
int main(void)
{
    DDRA=0b00000000;
	DDRD=0b11111111;
    while (1) 
    {
		if ((PINA & 0x01) !=0)
		{
			ctt++;
			PORTD = ctt;
			while((PINA & 0x01) !=0);
		}
	}
}

