#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) 
{
    int answer = 0;

    sort(routes.begin(), routes.end(), cmp);

    for (int i = 0; i < routes.size(); i++)
    {
        int tmp_last = routes[i][1];
        int idx = 0;

        for (int t = i+1; t < routes.size(); t++)
        {
            int cmp_first = routes[t][0];
            if (tmp_last >= cmp_first)
            {
                idx++;
                if (tmp_last > routes[t][1])
                    tmp_last = routes[t][1];
            }
            else
            {
                break;
            }
        }
        i += idx;
        answer++;
    }

    cout << answer << endl;
    return answer;
}