#include <stdio.h>
#include <vector>
using namespace std;

vector<int> input = { 1,1,2,2 };

int solution(vector<int> nums)
{
    int count = 1;
    vector<int>::iterator input_Iter1;
    for (input_Iter1 = nums.begin(); input_Iter1 < nums.end(); input_Iter1++)
    {
        vector<int>::iterator input_Iter2;
        //for(input_Iter2 = nums[count]; )
    }
    int answer = 0;
    return answer;
}

int main()
{
    vector<int>::iterator input_Iter = input.begin();
    printf("%x \n", &(*input_Iter));
    input_Iter++;
    printf("%x \n", &(*input_Iter));
    input_Iter++;
    printf("%x \n", &(*input_Iter));

    return 0;
}
