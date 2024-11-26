#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    // Servo의 배선은 PB5으로 한다.
    DDRB=0xff;
	TCCR1A = 0b10000010; // FAST PWM
	TCCR1B = 0b00011011; // 64분주
	ICR1=4608; // 4608*4.34 = 20ms
	OCR1A=346; // 346*4.34 = 1.5ms
	sei(); // 인터럽스 허용
    while (1) 
    {
		OCR1A = 145; // 0도: 630 / 4.34 = 145
		_delay_ms(2000); 
		OCR1A = 346; // 90도: 1500 / 4.34 = 346
		_delay_ms(2000);
		OCR1A = 552; // 180도: 2400 / 4.34 = 552
		_delay_ms(2000);
    }
}

