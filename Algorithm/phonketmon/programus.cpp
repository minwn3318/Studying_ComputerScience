#include <stdio.h>
#include <vector>
using namespace std;

vector<int> input = { 3,3,3,4,3,4 };

int solution(vector<int> nums)
{
    int len = nums.size();
    int choose = (nums.size()/2);
    int count = 0;
    int differnt = 0;
    int answer;

    int iter1_el = 0;
    int iter2_el = 0;

    vector<int>::iterator input_Iter = nums.begin();

    while(count < (nums.size() - 1))
    {
        iter1_el = *input_Iter;
        input_Iter++;
        iter2_el = *input_Iter;
        printf("%d \n", iter1_el);
        printf("%d \n", iter2_el);
        if (iter1_el != iter2_el)
        {
            differnt++;
        }
        count++;
    }

    if (differnt >= choose)
    {
        answer = choose;
    }
    else
    {
        answer = differnt + 1;
    }
    return answer;
}

int main()
{

    printf("결과 : %d", solution(input));

    return 0;
}
