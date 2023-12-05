# 소켓 주소 구조체   
```
#pragma comment (lib,"ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

// IPv4 소켓 주소 구조체
//--------------------
struct sockaddr_in {
	short sin_family;         // 주소체계
	unsigned short sin_port;  // 포트넘   
	struct in_addr sin_addr;  // IP 주소
	char sin_zero[8];
};

// IPv6 소켓 주소 구조체
//--------------------
struct sockaddr_in6 {
	short sin6_family;      // 주소체계
	u_short sin6_port;      // 포트넘
	u_long sin6_flowinfo;   
	struct in6_addr;        // IP 주소
	u_long sin6_scope_id;   
};

// IP주소 구조체 s_addr(S_un(.S_addr, S_un_w, S_un_b))
//--------------------
struct in_addr {
	union {
		struct {
			u_char s_b1;
			u_char s_b2;
			u_char s_b3;
			u_char s_b4;
		} S_un_b; // 4개 바이트의 구성
		struct {
			u_short s_w1;
			u_short s_w2;
		}S_un_w; // 2개의 워드로 구성
		u_long S_addr; //32비트 주소를 담는 필드
	}S_un;
#define s_addr S_un.S_addr
};
```
