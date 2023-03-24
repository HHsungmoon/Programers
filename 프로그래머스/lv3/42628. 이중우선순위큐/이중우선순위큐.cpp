#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    vector<int> vec;
    reverse(operations.begin(), operations.end());

    while (operations.empty() != true)
    {
        string str_tmp = operations.back();
        operations.pop_back();
        
        char str1 = str_tmp[0];
        int num = stoi(str_tmp.substr(2));

        if (str1 == 'I') // 삽입
        {
            vec.push_back(num);
        }
        else if (str1 == 'D')
        {
            if (num == 1)
            {
                if (vec.size() > 1)
                {
                    for (int i = 1; i < vec.size(); i++)
                    {
                        if (vec[i - 1] > vec[i])
                        {
                            int tmp = vec[i];
                            vec[i] = vec[i - 1];
                            vec[i - 1] = tmp;
                        }
                    }
                }
                // 오름차순 정렬
                if(vec.size() > 0)
                    vec.pop_back();
            }
            else if (num == -1)
            {
                if (vec.size() >= 2)
                {
                    for (int i = 1; i < vec.size(); i++)
                    {
                        if (vec[i - 1] < vec[i])
                        {
                            int tmp = vec[i];
                            vec[i] = vec[i - 1];
                            vec[i - 1] = tmp;
                        }
                    }
                }
                // 내림차순 정렬
                if (vec.size() > 0)
                    vec.pop_back();
            }
        }
    }

    if (vec.empty() != true)
    {
        int min = *min_element(vec.begin(), vec.end());
        int max = *max_element(vec.begin(), vec.end());
        answer.push_back(max);
        answer.push_back(min);
    }
    else
    {
        answer.push_back(0); answer.push_back(0);
    }

    return answer;
}