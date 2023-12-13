# 바이트 정렬 함수   

### 바이트 순서 구조   
**0x12345678**
* 바이트 데이터에서는 왼쪽이 가장 큰자리 수 위치
     
### 바이트 정렬   
* 빅 엔디안 : 최상위 바이트부터 차례로 저장
  > 0x12345678 -> 0x12345678
* 리틀 엔디안 : 최하위 바이트부터 차례로 저장
  > 0x12345678 -> 0x78563412

-------------   

### 호스트 바이트 <-> 네트워크 바이트   
* 호스트 바이트 = 빅 엔디안
* 네트워크 바이트 = 리틀 엔디안
  
#### short 타입
   > u_short htons(u_short hostshort) : 호스트 -> 네트워크

   > u_short ntohs(u_short networkshort) : 네트워크 -> 호스트
#### long 타입
   > u_long htonl(u_long hostlong) : 호스트 -> 네트워크

   > u_long ntohl(u_long networklong) : 네트워크 -> 호스트

------------   

### ip 문자열 <-> 네트워크 바이트   
   > INT Inet_ptonW(int addrFamliy, PCWSTR addrstring, LPVOID addr_inIp) : 문자열 -> 네트워크
* 매개변수 내용 :
  소켓 주소 구조체의 체계, 주소 구조체의 ip주소 문자열, ip주소를 저장할 구조체의 ip주소 부분
* 기능 :
  문자열을 네트워크 바이트로 전환하여 ip주소 부분에 저장,
* 반환값 : 오류가 없을 시 1을 반환
  
> INT Inet_NtopW(int addrFamliy, LPVOID addr_inIp, PWSTP addrbuffer, size_t addrbufSize) : 네트워크 - > 문자열
* 매개변수 내용 :
  소켓 주소 구조체의 체계, ip주소체계가 있는 주소체의 부분, 전환된 문자열을 저장할 버퍼, 버퍼크기
* 기능 :
  네트워크 바이트를 문자열로 전환하여 버퍼에다 저장
* 반환값 : 오류가 없을 시 1을 전환
