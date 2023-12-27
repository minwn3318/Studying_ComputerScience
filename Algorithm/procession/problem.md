# 문제 링크   
https://github.com/minwn3318/Studying_ComputerScience/blob/main/Algorithm/procession/procession.md

## 문제인식   
* 2차원 벡터를 어떻게 순차적으로 순회할까?

### 분석   
* 함수의 입력 파라미터에 정수가 없기에 벡터의 길이를 넣는 건 없다
  > 따라서 반복자를 활용해야할 것이다.
* 그러면 반복자는 벡터의 길이만큼 생성해야 할 텐데, 생성할 때 이름을 어떻게 지어야 하지?
  > 시간이 너무 오래 걸리므로 이건 아니다.
* 벡터의 길이는 입력 받고 난 뒤에도 얻을 수 있다.
  > 그러면 인덱스를 이용해보자

### 결과   
* 이중 반복문과 벡터 인덱싱을 이용하여 벡터의 요소를 순회하는 이중반복문을 구현하였다.
* 먼저 입력된 파라미가 이중벡터이므로 요소인 벡터를 얻기 위해 front를 활용하였다.   
* 이중벡터의 요소 갯수와 이중벡터의 요소의 요소갯수를 구하여 각 벡터들의 길이를 구한다.
* 벡터들의 길이를 활용해 인덱싱을 사용하여 이중반복문을 구현한다. 
```
    vector<int> arrEle = arr1.front();

    int arr_Size = arr1.size();
    int arrEle_Size = arrEle.size();

   for (int i = 0; i < arr_Size; i++)
    {
        for (int j = 0; j < arrEle_Size; j++)
        {

        }
    }
```

## 문제인식   
* 어떻게 더하는 걸 구현하지?

### 분석   
* 입력되는 파라미터가 되는 이중벡터들은 행과 열의 길이가 같다
  > 즉 첫번째 이중벡터의 길이는 두번째 이중벡터의 길이와 같다
  > 따라서 두 이중벡터의 같은 인덱싱 값을 더해 정수에 저장하면 된다.

### 결과   
```
    int answerVec_2stEle;

    vector<int> arrEle = arr1.front();

    int arr_Size = arr1.size();
    int arrEle_Size = arrEle.size();

   for (int i = 0; i < arr_Size; i++) 
    {
        for (int j = 0; j < arrEle_Size; j++)
        {
            answerVec_2stEle = arr1[i][j] + arr2[i][j];
        }
    }
```

## 문제인식   
* 더한걸 어떻게 벡터에 넣지?

### 분석   
* 함수에 벡터를 선언하고 해당 벡터에 푸쉬백하자!
  > 그러니까 벡터의 길이가 길어져서 (2, 2) (2,2) 가 아니라 (2,2,2,2) 형태가 되어버림
* 선언한 벡터를 초기화 하고 해당 벡터의 인덱싱 위치의 값을 더한 값으로 수정하자!
  > 인덱싱 위치는 이중벡터 안의 벡터의 인덱싱과 같게 하자!

### 결과   
```
    vector<int> answerVec_1stEle;
    int answerVec_2stEle;

    vector<int> arrEle = arr1.front();

    int arr_Size = arr1.size();
    int arrEle_Size = arrEle.size();

   for (int i = 0; i < arr_Size; i++) 
    {
        for (int j = 0; j < arrEle_Size; j++)
        {
            answerVec_2stEle = arr1[i][j] + arr2[i][j];
            answerVec_1stEle[j] = answerVec_2stEle;
        }
    }
```
