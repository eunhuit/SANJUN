#include <avr/io.h>
#include <util/delay.h>
// 0 = 0.7, 90 = 1.5, 180 = 2.4

int main(void)
{
    DDRA=0xff;
    while (1) 
    {
		PORTA=0xff;
		_delay_ms(1.5);
		PORTA=0x00;
		_delay_ms(20);
    }
}
