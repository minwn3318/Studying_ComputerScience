# 소켓 생성함수와 소켓 닫기 
* 소켓 생성함수 선언부분
```
#include <winsock2.h>
 
// 소켓 생성 함수 -> 반환타입 소켓 
SOCKET socket(
	int af, // 주소체계 : 어떤 주소체계로 할꺼임?
	int type, // 소켓 타입 : 프로토콜에 따름
	int protocol // 사용할 프로토콜 지정
);
```
* 소켓 생성과 닫기 구현
```
#pragma comment (lib,"ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

int main()
{
	WSADATA wsa; //윈속 선언(윈도우에서 소켓을 사용하기 위한 api)
	if (WSAStartup(2.2, &wsa) != 0)//윈속 초기화 - 어떤 버전이고, 해당되는 윈속변수 필요)
	{
		return -1;
	}

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);//소켓 생성
	if (sock == INVALID_SOCKET)
	{
		return -1;
	}
	
	cout << "init compelet";

	closesocket(sock); // 소캣 닫기 - 리소스 반환

	WSACleanup(); // 윈속 청소하기 - 리소스를 다시 정리하기 위함!
	return 0;
}
```
