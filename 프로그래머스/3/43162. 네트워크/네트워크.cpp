#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int visited[200] = { 0, };

void DFS(int n, vector<vector<int>> computers, int idx)
{
    visited[idx] = 1;
    for (int t = 0; t < n; t++)
    {
        if (computers[idx][t] == 1 && visited[t] != 1)
        {
            DFS(n, computers, t);
        }
    }

}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(n, computers, i);
            answer++;
        }
    }
    //cout << answer << endl;
    return answer;
}