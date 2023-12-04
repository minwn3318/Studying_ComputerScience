# 윈도우소켓에서 오류코드를 반환해주는 함수 FormatMessage() 
```
#pragma comment (lib,"ws2_32.lib") //윈속 초기화할 수 있는 라이브러리
#include <WinSock2.h> // 윈속 헤더파일 포함

void err_display(const char* msg)
{
	LPVOID lpMsgBuf; //오류를 담을 주소값을 할당할 공간
	//오류코드에 따라 오류 메시지를 반환한다. - 반환형태(더블워드) 오류메세지 길이 반환
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, // 초기화(더블워드)
		NULL, // 초기화에 따른 상태(어느 타입의 전역 상수 포인터)
		WSAGetLastError(), //오류 코드 찾기(더블 워드)
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 언어반환(시스템 언어, 사용자 정의 언어) (더블워드)
		(LPWSTR)lpMsgBuf, //문자열 시작 주소 할당 
		0, //길이
		NULL); // 옵션
}
```
