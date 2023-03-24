#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int check_1(string tmp_str, vector<pair<string, int>> total_play)
{
    for (int t = 0; t < total_play.size(); t++)
    {
        if (tmp_str.compare(total_play[t].first) == 0) // 같다면
        {
            return t;
        }
    }
    return -1;
}

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    vector<pair<string, int>> total_play;

    for (int i = 0; i < genres.size(); i++)
    {
        int tmp_n = plays[i];
        string tmp_str = genres[i];

        int idx = check_1(tmp_str, total_play);
        if (idx != -1)
            total_play[idx].second += tmp_n;
        else
            total_play.push_back(make_pair(tmp_str, tmp_n));
    }

    sort(total_play.begin(), total_play.end(), compare);
    //for (int i = 0; i < total_play.size(); i++)
    //    cout << total_play[i].first << " " << total_play[i].second << endl;

    for (int i = 0; i < total_play.size(); i++)
    {
        vector<pair<int,int>> vec;  // idx, playnum
        string find_str = total_play[i].first;
        for (int t = 0; t < genres.size(); t++)
        {
            if (genres[t].compare(find_str) == 0)
            {
                vec.push_back(make_pair(t, plays[t]));
            }
        }
        sort(vec.begin(), vec.end(),compare2);
        answer.push_back(vec[0].first);
        if(vec.size() >= 2)
            answer.push_back(vec[1].first);
    }
    //for (int i = 0; i < answer.size(); i++)
    //    cout << answer[i] << " ";

    return answer;
}