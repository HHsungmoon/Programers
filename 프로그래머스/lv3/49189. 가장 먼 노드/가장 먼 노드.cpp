#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    map<int, vector<int>> node;
    for (int i = 0; i < edge.size(); i++)
    {
        vector<int>& tmp = node[edge[i][0]];
        tmp.push_back(edge[i][1]);
        vector<int>& tmp2 = node[edge[i][1]];
        tmp2.push_back(edge[i][0]);
    }
    vector<int> visited(n + 1, 0);
    visited[1] = 1;

    queue<int> que; que.push(1);

    while (que.empty() == false)
    {
        int num = que.front();
        que.pop();
        
        for (int i = 0; i < node[num].size(); i++)
        {
            if (visited[node[num][i]] == 0)
            {
                visited[node[num][i]] = visited[num] + 1;
                que.push(node[num][i]);
            }
        }
    }

    int max_num = *max_element(visited.begin(), visited.end());
    answer = count(visited.begin(), visited.end(), max_num);

    return answer;
}