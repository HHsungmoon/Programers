#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    sort(works.begin(), works.end(), greater<int>());
    works.push_back(0);

    int idx = 0;
    for (int i = 0; i < works.size() - 1; i++)
    {
        if (n <= 0)
            break;

        int cut = works[i] - works[i + 1];
        if (cut * (i+1) <= n) // 다음 idx와 같게끔 자르기
        {
            for (int t = 0; t <= i; t++)
            {
                works[t] = works[t] - cut;
                n -= cut;
            }
        }
        else // i까지의 일을 같은 크기만큼 줄이기
        {
            idx = i + 1;
            int tmp = n % idx;
            cut = n / idx;

            for (int t = 0; t <= i; t++)
            {
                works[t] = works[t] - cut;
                n -= cut;
                if (tmp > 0)
                {
                    works[t]--;
                    tmp--;
                    n--;
                }
            }
        }
    }
    
    for (int i = 0; i < works.size() - 1; i++)
    {
        answer += works[i]*works[i];
    }

    return answer;
}