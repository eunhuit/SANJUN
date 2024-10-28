#include <avr/interrupt.h>
#include <avr/io.h>
// 14745600 = 67.8n = 0.068u
int count=0;
ISR(TIMER0_OVF_vect) // 100ms마다 여기로 온다.
{
	count++;
	if(count==100)
	{
		PORTA = 0xff;// PA를 모두 켜기 (LED 켜기)
	}
	else if (count==200)
	{
		PORTA = 0x00; // PA를 모두 끄기 (LED 끄기)
		count=0;
	}
	TCNT0 = 256 - 14; // 오버플로 초기화
}

int main(void)
{
	DDRA = 0xFF; // LED PA를 출력으로 지정(PA에 LED 연결)
	TIMSK = 0b00000001; //오버플로
	TCCR0 = 0b00000111; // 1024 분주 = 69.4us
	TCNT0 = 256 - 14; // 1ms = 1000us/69.4us = 14
	sei(); // 글로벌 인터럽트 활성화.
	while (1)
    {
    }
}