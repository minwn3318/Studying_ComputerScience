#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<int> arrEle = arr1.front();

    int arr_Size = arr1.size();
    int arrEle_Size = arrEle.size();

    vector<vector<int>> answerVec;
    vector<int> answerVec_1stEle;
    int answerVec_2stEle;

    for (int j = 0; j < arrEle_Size; j++)
    {
        answerVec_1stEle.push_back(0);
    }

    for (int i = 0; i < arr_Size; i++)
    {
        for (int j = 0; j < arrEle_Size; j++)
        {
            answerVec_2stEle = arr1[i][j] + arr2[i][j];
            answerVec_1stEle[j] = answerVec_2stEle;
        }

        answerVec.push_back(answerVec_1stEle);
    }

    return answerVec;
}
