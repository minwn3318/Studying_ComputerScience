# 컴퓨터의 발전과 성능   

## 폰노이만 아키텍처   
* 폰노이만 아키텍처 이전 컴퓨터 형태 : 고정결선식
> 하드웨어 중심
  - 유지보수 하려면 전기회로 다 뜯어야 해서 힘들다
  - 조그만 잘못 건드려도 다 망가진다

* 폰노이만 아키텍처 의의 : 시스템 소프트웨어 중심 컴퓨팅
> 유지보수가 고정결선식보다 쉽고, 잘못 짜더래도 기본적으로 하드웨어에 문제가 없음

* 특징
  - 순차적 주소를 가진다
  - 명령어, 데이터 구분없이 메모리에 저장된다.

* 폰노이만 병목 : cpu와 메모리 사잇길
> 해당 사잇길에서 트랙픽이 발생함

## 성능   
### 사용자 관점 :   
응답시간이 빠르다 -> cpu의 프로그램 처리 시간이 빠르다.   
### 운영자(다수이용) 관점 :   
처리율이 높다 -> 한 번에 많을 양을 처리할 수 있다.   
   
### 성능 = 1/cpu시간   

### m2 실행 시간 = m1{(개선부분/성능향상된 수치) + (1 - 개선부분)}
   
### 프로그램 실행시 cpu시간   
### = 명령어 개수(코드수) * 사이클 개수(명령어 실행시 도는 횟수) * 시간(한 사이클당 소요)   
### = (명령어수 * 평균 사이클 개수) / 클록 속도
