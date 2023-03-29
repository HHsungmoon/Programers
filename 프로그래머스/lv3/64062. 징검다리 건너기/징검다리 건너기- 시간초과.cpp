#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 200000001;

    int start_idx = 0; int end_idx = start_idx + k - 1;

    deque<int> que;
    for (int i = start_idx; i <= end_idx; i++)
        que.push_back(stones[i]);

    int max_num = *max_element(que.begin(), que.end());
    if (answer > max_num)
        answer = max_num;

    for (int i = 0; i < stones.size() - k; i++)
    {
        end_idx++;
        que.push_back(stones[end_idx]);
        que.pop_front();
        start_idx++;
        max_num = *max_element(que.begin(), que.end());
        if (answer > max_num)
            answer = max_num;

    }
    return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    solution(stones, 3);
    return 0;
}