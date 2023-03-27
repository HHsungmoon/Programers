#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

bool check_visited(string str, vector<string> visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (str.compare(visited[i]) == 0) // 이미 방문했다.
            return false;
    }
    return true;
}

int gems_type_vec(vector<string> gems)
{
    //set<string> s(gems.begin(), gems.end());
    //return s.size();

    sort(gems.begin(), gems.end());
    auto last = unique(gems.begin(), gems.end());

    vector<string> re_vec(gems.begin(), last);

    return re_vec.size();
}

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    vector<pair<int, int>> lange;

    int gems_type_len = gems_type_vec(gems);

    int start_idx = 0; int end_idx = 0;

    map<string, int> visited;
    
    while (1)
    {
        if (gems_type_len == visited.size())  // 모두 방문했다. // start를 증가시키자
        {
            auto iter = visited.find(gems[start_idx]);
            if (iter->second == 0) // 삭제 불가능
            {
                // 현재 구간을 저장 해야 된다.
                lange.push_back(make_pair(start_idx, end_idx - 1));
                visited.erase(gems[start_idx]);
                start_idx++; end_idx - 1;
            }
            else // 가능
            {
                iter->second--;
                start_idx++;
            }
        }
        else if (end_idx >= gems.size()) // 더이상 방법이 없다.
        {
            break;
        }
        else // end 를 늘려줘야 된다.
        {
            // 중복이 아니라면 visited 채우기. 중복이면 값 증가
            auto iter = visited.find(gems[end_idx]);
            if (iter != visited.end())// 있다.
                iter->second++;
            else
                visited.insert({ gems[end_idx], 0 });

            end_idx++;
        }
    }

    int min_idx = 0;
    for (int i = 1; i < lange.size(); i++)
    {
        if (lange[min_idx].second - lange[min_idx].first > lange[i].second - lange[i].first)
            min_idx = i;
    }
    answer.push_back(lange[min_idx].first + 1);
    answer.push_back(lange[min_idx].second + 1);

    return answer;
}