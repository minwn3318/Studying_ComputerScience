# 포인터(들은거 대로 적기 - 1차 메모) 
링크 : https://www.youtube.com/watch?v=u65F4ECaKaY   

### 포인터의 역할 : 
* 변수가 메모리에서 몇번째에 있는지 주소를 저장하고 가리킴   
* 해당 변수의 타입 크기만큼의 메모리를 할당함
  
**사용 이유** : 포인터는 사용자가 컴퓨터의 메모리를 직접 처리할 수 있도록 함   
* 효과 : 다른 곳에서 값을 사용하여야 할 때 굳이 복사하지 않고 주소를 가리켜서 하면 됨   
> 예 : 함수, 어떤 변수 집합에 여러 클라이언트가 참가했는데, 한 클라이언트가 포인터를 통해 내용을 변경하면 그 내용이 반영되는 것

## 실습 예제
```
#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int* b = &a;

	cout << a << endl;
	cout << &a << endl;

	cout << b << endl;
	cout << &b << endl;
	cout << *b << endl;

	*b = 20;

	cout << *b << endl;
	cout << a << endl;
	return 0;
}
```

#### 20번째 줄 설명   
* b : 정수형 포인터로 정수타입의 주소를 할당하기 위한 메모리 공간을 차지함
* &a : a의 주소값을 계산
> 최종적으로 b는 a의 주소를 가리키게 됨

#### 25, 26, 27번째 줄 설명   
* b : b를 출력한다는 것은 b에 할당된 값을 출력한다는 의미, 여기서는 &a, a의 주소를 출력한다는 의미가 된다.
* &b : b의 주소를 출력한다는 의미, 그러니까 b가 할당하고 있는 a의 주소를 출력하는 것이 아니라 실제 int *b가 할당된 위치를 말한다.
* *b : b에 할당된 주소의 실제 값을 출려한다느 의미, a의 실제 값을 출력한다는 뜻이 된다.

#### 29번째 줄 설명   
b에 할당된 주소의 실제 값을 20으로 변경한다는 의미, 따라서 a의 값이 변한다.   
> 그 이유는 메모리 주소로 가리키면 컴퓨터가 메모리 주소에 가서 그 값을 변경하는 것으로 인식하기 때문!(나중에 더 공부할 필요가 있음)

#### 출력값
```
10 // a의 실제값
000000AA44AFFB84 // a의 주소값 
000000AA44AFFB84 // b에 할당된 주소값
000000AA44AFFBA8 // b의 실제 주소값
10 // b에 할당된 주소값의 실제 값
20 // b에 할당된 주소값의 실제 값 변경 내용
20 // 할당된 주소값이 a였기에 a의 값이 변경
```
