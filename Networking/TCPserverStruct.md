# TCP 서버 구조   

### 서버측 사용 소켓함수   
1. SOCKET socket(int saddr_inFamilty, int socktype, int protocol )
   * 역할 : 소켓을 생성한다.
   * 매개변수 : 소켓 주소 체계, 소켓 타입, 프로토콜 타입
   * 반환값 : 소켓 핸들러
2. int bind(SOCKET s, SOCKADDR_IN* saddr, int addr_size)
   * 역할 : 소켓에 주소를 바인딩, 예약한다. 미리 주소가 정해지게 만든다.
   * 매개변수 : 소켓, 소켓주소구조체, 구조체 사이즈
   * 반환값 : 정수, 오류 확인
3. int listen(SOCKET s, int connectsize)
   * 역할 : 대기열 소켓, 얼굴마담 소켓을 만든다.
   * 매개변수 : 소켓, 접속가능한 클라이언트 갯수
   * 반환값 : 정수, 오류확인
4. SOCKET accept(SOCKET s, SOCKADDR_IN* caddr, int caddr_size)
   * 역할 : 클라이언트와 통신할 소켓을 만든다.
   * 매개변수 : 대기열 소켓, 클라이언트의 소켓주소구조체, 구조체 사이즈
   * 반환값 : 소켓 핸들러 
5. int recv(SOCKET c, char* buf, int bufsize, int op)
   * 역할 : 운영체제 수신버퍼에서 값을 받아온다
   * 매개변수 : 통신 소켓, 수신할 버퍼 포인터, 복사할 값 크기, 옵션
   * 반환값 : 정수, 오류확인   
6. int send(SOCKET c, char* buf, int buf size, int op)   
   * 역할 : 운영체제 송신버퍼로 값을 보낸다
   * 매개변수 : 통신소켓, 송신할 버퍼 포인터, 보낼 값 크기, 옵션
   * 반환값 : 정수, 오류확인

**송수신 함수에서 보낼 혹은 받는 데이터의 크기가 버퍼의 크기와 딱 알맞을 필요는 없다**   
**하지만 데이터 크기가 버퍼보다 크다면 오버풀로우가 발생하면서 서버가 터져버린다**

---------------

### 서버 구성 방법(윈도우)   
## 서버측
1. 윈속 변수 선언 및 초기화
2. 소켓함수로 소켓 생성
3. 소켓주소구조체 선언으로 주소체계, 포트번호, 아이피주소 선언
4. 바인드함수를 통해 소켓의 아이피주소, 주소체계, 포트번호를 정해준다
5. 소켓을 이용해 리슨함수를 통해 얼굴마담소켓을 만들어준다.
6. 클라이언트와 통신할 소켓주소구조체를 선언한다
7. 얼굴마담소켓을 매개변수로 클라이언트와 통신할 소켓을 만든다.
8. 버퍼를 만든다
9. 반복문 안에 리시브함수와 샌드함수를 만든다
10. 반복문이 끝나면, 통신소켓과 얼굴마담 소켓을 닫는 함수를 호출한다
11. 윈속을 정리하는 함수를 호출한다.

**예시 코드**
```
#pragma comment (lib,"ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <stdio.h>

#define SRVERPORT 9000
using namespace std;
```
* 사용되는 소스파일들을 선언해준다.
     
```
int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		erro_display("Init Error");
		return -1;
	}
```
* 윈속을 초기화 시켜준다.
* 오류가 발생하였는 지 확인한다.
  
```
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		erro_display("socket");
		return -1;
	}
```
* 소켓을 생성한다.
* 오류가 발생하였는지 확인한다.
  
```
	SOCKADDR_IN saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(SRVERPORT);
	saddr.sin_addr.s_addr = ntohl(INADDR_ANY);
	if (bind(sock, (SOCKADDR*)&saddr, sizeof(saddr)))
	{
		erro_display("bind");
		return -1;
	}
```
* 소켓 주소 구조체를 선언하고 해당 주소구조체를 소켓에다 할당한다
* 오류가 발생하였는지 확인한다.
  
```
	if (listen(sock, SOMAXCONN))
	{
		erro_display("listen");
		return -1;
	}
```
* 접속대기 소켓을 만들어준다
* 오류가 발생하였는 지 확인한다.
  
```
	SOCKADDR_IN caddr;
	int caddrlen = sizeof(caddr);
	SOCKET c_sock = accept(sock, (SOCKADDR*)&caddr, &caddrlen);
	if (c_sock == INVALID_SOCKET)
	{
		erro_display("accept");
		return -1;
	}
```
* 클라이언트용 소켓주소구조체를 할당하고 실제 통신할 소켓을 만든다.
* 오류가 발생하였는지 확인한다.
  
```
	cout << "client connect " << endl;
	cout << "port number : " << ntohs(caddr.sin_port) << endl;

	int retval;
	char buf[BUFSIZ];
```
* 버퍼와 버퍼크기를 선언한다.
  
```
	while (1)
	{

		retval = recv(c_sock, buf, BUFSIZ, 0);
		if (retval == SOCKET_ERROR)
		{
			erro_display("recv");
			break;
		}
		if (retval == 0)
		{
			break;
		}
```
* 통신소켓에서 수신버퍼에서 정해진 크기만큼 데이터를 가져온다.
  
```
		buf[retval] = '\0';

		cout << "client : " << buf << endl;

		retval = send(c_sock, buf, retval, 0);
		if (retval == SOCKET_ERROR)
		{
			erro_display("send");
			break;
		}

		//cout << "size send retval : " << retval << endl;

		//cout << "size : " << retval << endl;
	}
```
* 에코서비스이기에 받은 데이터의 끝자리를 null값으로 변경한 후
* 버퍼에서 데이터를 정해진 크기만 큼 통신소켓을 통해 보낸다.

```
	closesocket(c_sock);
	closesocket(sock);
	cout << "end" << endl;
	WSACleanup();
	return 0;
}
```
* 접속이 끝났다면 소켓을 닫아준다. 이 때 서버는 접속대기 소켓과 실제통신 소켓이 있으니 두개 다 닫아주어야한다
* 윈속에 할당된 리소스를 반환하고 프로그램을 종료한다.

## 클라이언트측
1. 윈속 변수 선언 및 초기화
2. 소켓함수로 소켓 생성
3. 소켓주소구조체 선언으로 주소체계, 포트번호, 아이피주소 선언
4. 소켓주소구조체를 매개변수로 connect 함수 작성
5. 버퍼를 만든다
6. 반복문 안에 리시브함수와 샌드함수를 만든다
7. 반복문이 끝나면, 통신소켓과 얼굴마담 소켓을 닫는 함수를 호출한다
8. 윈속을 정리하는 함수를 호출한다.

**예시 코드**   
```
#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <stdio.h>

#define SERVERPORT 9000
using namespace std;
```
* 사용되는 소스파일들을 선언해준다.
  
```
int main()
{
	WSADATA cwsa;
	if(WSAStartup(MAKEWORD(2, 2), &cwsa))
	{
		error_display("WSAStartup");
		return -1;
	}
```
* 윈속을 초기화 시켜준다.
* 오류가 발생하였는 지 확인한다.
  
```
	SOCKET c_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (c_sock == INVALID_SOCKET)
	{
		error_display("socket");
		return -1;
	}
```
* 소켓을 생성한다.
* 오류가 발생하였는지 확인한다.
  
```
	SOCKADDR_IN caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(SERVERPORT);
	PCWSTR ipaddr = L"127.0.0.1";
	if (!InetPtonW(AF_INET, ipaddr, &caddr.sin_addr))
	{
		error_display("InetPtonW");
		return -1;
	}

	if (connect(c_sock, (SOCKADDR*)&caddr, sizeof(caddr)))
	{
		error_display("connect");
		return -1;
	}
```
* 소켓 주소 구조체를 선언하고 해당 주소구조체를 소켓에다 할당한다
* 오류가 발생하였는지 확인한다.
  
```
	int retval;
	int len;
	char buf[BUFSIZ + 1];
```
* 버퍼와 버퍼크기를 선언한다.
  
```
	while (1)
	{
		cout << "input : ";
		fgets(buf, BUFSIZ + 1, stdin);
		if (*buf == '\n')
			break;

		len = strlen(buf);
		
		//cout << "size len : " << len << endl;

		retval = send(c_sock, buf, len, 0);
		if (retval == SOCKET_ERROR)
		{
			error_display("send");
			break;
		}
```
* 글자를 입력받아 버퍼에 저장하고 버퍼에서 글자크기만큼 데이터를 보낸다.
  
```
		//cout << "size send retval : " << retval << endl;

		retval = recv(c_sock, buf, retval, 0);
		if (retval == SOCKET_ERROR)
		{
			error_display("recv");
			break;
		}

		//cout << "size recv retval : " << retval << endl;

		buf[retval] = '\0';
		cout << "sever : " << buf << endl;
	}
```
* 통신소켓에서 수신버퍼에서 정해진 크기만큼 데이터를 가져온다.
* 정해진 크기는 이미 송신버퍼에서 정해졌으므로 해당 값을 그대로 쓴다.
  
```
	closesocket(c_sock);
	cout << "endl" << endl;
	WSACleanup();
	return 0;
}
```
* 접속이 끝났다면 소켓을 닫아준다. 이 때 서버는 접속대기 소켓과 실제통신 소켓이 있으니 두개 다 닫아주어야한다
* 윈속에 할당된 리소스를 반환하고 프로그램을 종료한다.
  
-------------   

### TCP서버 문제점   
1. 다수 클라이언트 접속은 가능한데 서비스 처리는 불가능함
   > 서버에 있는 접속하고 서비스를 대기하는 소켓을 만드는 listen함수로 만들어진 연결큐는 앞에것만 확인할 수 있는 구조다.
   > 실제로 여러 클라이언트가 접속했지만 큐를 통해 직접 확인하고 서비스를 처리할 수 있는 것은 맨 앞에 접속된 클라이언트 뿐이다
2. 데드락 발생
   > 서버와 클라가 동시에 송신함수를 호출하는 것처럼,  둘다 자원을 가지고 있고, 다른 상대의 자원을 호출하는데, 동시에 호출하여 발생한다.
