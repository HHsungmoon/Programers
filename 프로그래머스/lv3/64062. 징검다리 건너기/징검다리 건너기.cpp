#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

bool success_fail(int mid, vector<int> stones, int k)
{
    int idx = 0; 
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid < 0)
        {
            idx++;
            if (idx >= k)// 건너기 실패
            {
                return false;
            }
        }
        else
        {
            idx = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;

    int start = 1; int end = *max_element(stones.begin(), stones.end());
    int prev_ans = 0; 
    while (start < end)
    {
        int mid = (start + end)/2;

        if (success_fail(mid,stones,k) == true)
        {
            if (answer >= mid)// 이미 다 찾음
                break;
            else
                answer = mid;
            start = mid;
        }
        else
        {
            end = mid-1;
        }
    }

    while (1)
    {
        answer += 1;
        if (success_fail(answer, stones, k) == false)
        {
            answer -= 1;
            break;
        }
    }

    return answer;
}