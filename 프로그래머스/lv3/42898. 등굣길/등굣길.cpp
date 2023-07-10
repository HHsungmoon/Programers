#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    int** board = new int* [n+1];
    for (int y = 0; y < n+1; y++)
        board[y] = new int[m+1];

    for (int x = 1; x < m+1; x++)
        for (int y = 1; y < n + 1; y++)
            board[y][x] = 0;

    for (int i = 0; i < puddles.size(); i++)
    {
        board[puddles[i][1]][puddles[i][0]] = -1;
    }

    int cnt_x = 1;
    for (int x = 1; x < m + 1; x++)
    {
        if (board[1][x] == -1)
            cnt_x = -1;
        
        board[1][x] = cnt_x;
        visited[1][x] = 1;
    }
    int cnt_y = 1;
    for (int y = 1; y < n + 1; y++)
    {
        if (board[y][1] == -1)
            cnt_y = -1;
        board[y][1] = cnt_y;
        visited[y][1] = 1;
    }


    queue<pair<int, int>> que;
    pair<int, int> tmp;
    tmp.first = 2; // m
    tmp.second = 2; // n
    que.push(tmp);
    visited[2][2] = 1;

    while (que.empty() != true)
    {
        pair<int, int> point = que.front();
        que.pop();

        if(board[point.second][point.first] == 0) // 아직 지나가지 않은 지점
        {
            if(board[point.second - 1][point.first] != -1)
                board[point.second][point.first] += board[point.second - 1][point.first];
            if (board[point.second][point.first - 1] != -1)
                board[point.second][point.first] += board[point.second][point.first - 1];

            board[point.second][point.first] = board[point.second][point.first] % 1000000007;
            if (point.second + 1 != n + 1 && visited[point.second + 1][point.first] == 0)
            {
                que.push(make_pair(point.first, point.second + 1));
                visited[point.second + 1][point.first] = 1;
            }
            if (point.first + 1 != m + 1 && visited[point.second][point.first + 1] == 0)
            {
                que.push(make_pair(point.first + 1, point.second));
                visited[point.second][point.first + 1] = 1;
            }
                
        }

        if (point.second + 1 != n + 1 && visited[point.second + 1][point.first] == 0)
        {
            que.push(make_pair(point.first, point.second + 1));
            visited[point.second + 1][point.first] = 1;
        }
        if (point.first + 1 != m + 1 && visited[point.second][point.first + 1] == 0)
        {
            que.push(make_pair(point.first + 1, point.second));
            visited[point.second][point.first + 1] = 1;
        }
    }

    answer = board[n][m];
    return answer;
}