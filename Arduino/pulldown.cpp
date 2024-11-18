void setup()
{
  pinMode(3, INPUT_PULLUP);  // 버튼을 풀업저항으로 설정 (풀다운을 내부에서 처리)
  pinMode(4, OUTPUT);        // LED 핀을 출력으로 설정
}

void loop()
{
  int pb1_value = digitalRead(3);  // 버튼의 상태 읽기

  if (pb1_value == HIGH) {  // 버튼이 눌렸을 때 (풀다운 상태에서 HIGH)
    digitalWrite(4, HIGH);  // LED 켜기
    delay(2000);            // 2초 대기
    digitalWrite(4, LOW);   // LED 끄기
    delay(1000);            // 1초 대기
  }
}
