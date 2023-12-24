#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    vector<int>::iterator input_iter = nums.begin();
    vector<int> storage = {0};

    int choose = (nums.size() / 2);
    int element_Nums = 1;

    storage.at(0) = *input_iter;
    input_iter++;

    for (input_iter; input_iter < nums.end(); input_iter++)
    {
        auto has_element = count(storage.begin(), storage.end(), *input_iter);
        if (has_element == 0)
        {
            element_Nums++;
        }
        storage.push_back(*input_iter);
    }

    if (element_Nums > choose)
    {
        element_Nums = choose;
    }
    return element_Nums;
}
