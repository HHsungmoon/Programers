#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), less<int>());
    
    int b_max_idx = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int t = b_max_idx; t < B.size(); t++)
        {
            if (A[i] < B[t])
            {
                answer++;
                b_max_idx = t + 1;
                if (b_max_idx == B.size())
                    return answer;
                break;
            }
            else
            {
                b_max_idx = t;
            }
        }
    }

    return answer;
}