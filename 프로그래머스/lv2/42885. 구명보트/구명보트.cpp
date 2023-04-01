#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    int last_idx = people.size() - 1;
    
    for (int i = 0; i <= last_idx; i++)
    {
        int tmp_w = people[i];
        answer++;

        if (i == last_idx)
        {
            break;
        }   

        while (i < last_idx)
        {
            if (tmp_w + people[last_idx] <= limit)
            {
                tmp_w += people[last_idx];
                last_idx--;
            }
            else
            {
                break;
            }
        }
    }
    

    return answer;
}