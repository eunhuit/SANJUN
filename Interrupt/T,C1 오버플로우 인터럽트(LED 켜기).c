#include <avr/io.h>          // AVR 입출력 헤더 파일 포함
#include <util/delay.h>      // 지연 함수 헤더 파일 포함
#include <avr/interrupt.h>   // 인터럽트 관련 함수 헤더 파일 포함

int cc = 0;  // 카운트용 변수 (100ms마다 증가)

ISR(TIMER1_OVF_vect) { // Timer1 오버플로우 인터럽트 벡터
    cc++;  // 100ms마다 1씩 증가
    if (cc == 1) { // 100ms 지났을 때
        PORTA = 0xFF; // PORTA의 모든 비트를 1로 설정 (LED를 모두 켬)
    }
    if (cc == 2) { // 200ms 지났을 때
        PORTA = 0x00; // PORTA의 모든 비트를 0으로 설정 (LED를 모두 끔)
        cc = 0; // 카운트용 변수 초기화 (다시 0부터 시작)
    }
    TCNT1 = 0x10000 - 23041; // Timer1 카운터 값을 설정하여 오버플로우 주기를 설정
}

int main(void) {
    DDRA = 0xFF;  // PORTA를 출력으로 설정 (LED 제어용)
    TCCR1A = 0x00; // Timer1의 제어 레지스터 A 설정 (일반적인 모드로 설정)
    TCCR1B = 0x03; // Timer1의 제어 레지스터 B 설정 (프리스케일러 64 설정)
    TCNT1 = 0x10000 - 23041; // Timer1 초기 카운터 값 설정 (정확한 100ms 주기를 위해 설정)
    TIMSK = 0b00000100; // Timer1의 오버플로우 인터럽트 활성화 (TIMER1_OVF_vect 사용)
    sei(); // 전역 인터럽트 활성화 (인터럽트 처리 시작)
    while (1) {
        // 메인 루프에서는 아무 동작도 하지 않음 (인터럽트 방식으로 처리)
    }
}
