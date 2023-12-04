# 윈도우소켓 초기화와 종료   
```
#pragma comment (lib,"ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

int main()
{
	WSADATA wsa; //윈속 선언(윈도우에서 소켓을 사용하기 위한 공용api)
	if (WSAStartup(2.2, &wsa) != 0)//윈속 초기화 - 어떤 버전이고, 해당되는 윈속변수 필요)
	{
		return -1;
	}
	
	cout << "init compelet";

	WSACleanup(); // 윈속 청소하기 - 리소스를 다시 정리하기 위함!
	return 0;
}
```
