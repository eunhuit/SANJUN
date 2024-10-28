#include <avr/interrupt.h>
#include <avr/io.h>
// 14745600 = 67.8n = 0.068u
int count=0;
ISR(TIMER0_COMP_vect) // 100ms마다 여기로 온다.
{
	count++;
	if(count==500) // 100ms
	{
		PORTA = 0xff;// PA를 모두 켜기 (LED 켜기)
	}
	else if (count==1000) // 200ms
	{
		PORTA = 0x00; // PA를 모두 끄기 (LED 끄기)
		count=0;
	}
	TCNT0 = 0; //  카운터 초기화
}

int main(void)
{
	DDRA = 0xFF; // LED PA를 출력으로 지정(PA에 LED 연결)
	TIMSK = 0b00000010; //비교일치
	TCCR0 = 0b00000110; // 256 분주 = 0.068us * 256 = 17.4us
	TCNT0 = 0; // TCNT 초기화
	OCR0 = 57; // 1ms=1000us / 17.4us = 57
	sei(); // 글로벌 인터럽트 활성화.
	while (1)
    {
    }
}