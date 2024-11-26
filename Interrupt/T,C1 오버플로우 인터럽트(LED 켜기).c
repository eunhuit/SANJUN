#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int cc = 0; // 카운트용 변수
ISR(TIMER1_OVF_vect) { // 1ms마다 인터럽트 작동.
    cc ++; // 1ms마다 1씩 추가
    if(cc == 1) { // 만약 1ms 라면?
	PORTA = 0xff; // PORTA를 모두 작동(LED 모두 켜기)
    }
    if(cc == 2) { // 만약 2ms라면?(켜지고 1ms지남)
	PORTA = 0x00; // POARTA를 모두 끄기(LED 모두 끄기)
	cc = 0; // 카운트용 변수 초기화
    }
    TCNT1=0x10000-23041; // 오버플로우 인터럽터 초기화
}

int main(void)
{
    DDRA = 0xff; // A를 출력으로 지정
    TCCR1A=0x00; // 기본 타이머 모드로 작동
    TCCR1B=0x03; // 64분주비로 작동해라
    TCNT1=0x10000-23041; // Timer1 초기 카운터 값 설정 (정확한 1ms 주기를 위해 설정)
    TIMSK = 0b00000100; // Timer1의 오버플로우 인터럽트 활성화
    sei(); // 인터럽터 기능 활성화
    while (1) 
    {
    }
}


