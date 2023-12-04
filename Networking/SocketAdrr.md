# 소켓 생성함수와 소켓 닫기 
```
#include <winsock2.h>
 
// 소켓 생성 함수 -> 반환타입 소켓 
SOCKET socket(
	int af, // 주소체계 : 어떤 주소체계로 할꺼임?
	int type, // 소켓 타입 : 프로토콜에 따름
	int protocol // 사용할 프로토콜 지정
);
```
