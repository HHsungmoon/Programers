#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Y, X;

int** Map_arr;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct
{
	int x;
	int y;
	int cnt;
}Data;

int BFS(int sx, int sy)
{
	vector<vector<int>> visited(Y, vector<int>(X, 0));
	queue<Data> que;
	Data tmp; tmp.x = sx; tmp.y = sy; tmp.cnt = 0;
	que.push(tmp);
	visited[sy][sx] = 1;

	while (que.empty() == false)
	{
		Data temp = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < X && ny < Y && Map_arr[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				Data input; input.x = nx; input.y = ny; input.cnt = temp.cnt + 1;
				que.push(input);
				visited[ny][nx] = temp.cnt+1;
			}
		}
	}
	
	int max_num = 0;
	for (int i = 0; i < visited.size(); i++)
	{
		max_num = max(max_num, *max_element(visited[i].begin(), visited[i].end()));
	}

	return max_num;
}

int main()
{
	cin >> Y >> X;
	Map_arr = new int* [Y];
	for (int y = 0; y < Y; y++)
	{
		Map_arr[y] = new int[X];
	}

	
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == 'W')
				Map_arr[y][x] = 0;
			else if (tmp == 'L')
				Map_arr[y][x] = 1;
		}
	}

	int answer = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (Map_arr[y][x] == 1)
			{
				int tmp= BFS(x,y);
				answer = max(tmp, answer);
			}
		}
	}
	cout << answer;
	return 0;
}