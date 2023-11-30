# 윈도우소켓에서 오류코드를 반환해주는 함수 FormatMessage() 
```
#include <windows.h>

DWORD FormatMessage(
	DWORD dwFlasgs,
	LPVOID ipSource,
	DWORD dwMessageId,
	DWORD dwLanguageId,
	LPTSTR ipBuffer,
	DWORD nSize,
	va_list *Arguments
);
```
