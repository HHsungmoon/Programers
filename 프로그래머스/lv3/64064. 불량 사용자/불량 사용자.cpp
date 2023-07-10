#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool check_string_equel(string user, string ban)
{
    for (int i = 0; i < user.size(); i++)
    {
        if (user[i] == ban[i] || ban[i] == '*') {} // 통과
        else // 다른거
            return false;
    }
    return true;
}

void createCombinations(vector<vector<int>>& vec, int index, vector<int>& combination, set<vector<int>>& combinations)
{
    if (index == vec.size()) 
    {
        combinations.insert(combination);
        return;
    }

    for (auto& num : vec[index])
    {
        if (find(combination.begin(), combination.end(), num) == combination.end())
        {
            combination.push_back(num);
            createCombinations(vec, index + 1, combination, combinations);
            combination.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    int answer = 0;
   
    vector<vector<int>> vec(banned_id.size());
    map<string, int> map_data;

    int idx = 1;
    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int t = 0; t < user_id.size(); t++)
        {
            if(user_id[t].size() == banned_id[i].size())
            {
                if(check_string_equel(user_id[t], banned_id[i])==true) // 
                {
                    if (map_data.find(user_id[t]) != map_data.end()) // 이미 있는 숫자를 사용할 것
                    {
                        vec[i].push_back(map_data.find(user_id[t])->second);
                    }
                    else
                    {
                        map_data.insert({ user_id[t], idx });
                        vec[i].push_back(idx);
                        idx++;
                    }
                }
            }
        }
    }

    set<vector<int>> combinations;

    vector<int> combination;
    createCombinations(vec, 0, combination, combinations);

   
    vector<int> tmp_vec;
    for (auto& combination : combinations)
    {
        vector<int> tmp;
        for (auto& num : combination)
        {
            tmp.push_back(num);
        }
        sort(tmp.begin(), tmp.end());
        string tmp_str = "";
        for (int i = 0; i < tmp.size(); i++)
            tmp_str += to_string(tmp[i]);
        tmp_vec.push_back(stoi(tmp_str));
    }
    
    // unique 사용시 vector가 sort된 상태여야 한다.
    sort(tmp_vec.begin(), tmp_vec.end());
    tmp_vec.erase(unique(tmp_vec.begin(), tmp_vec.end()), tmp_vec.end());
    answer = tmp_vec.size();
    return answer;
}