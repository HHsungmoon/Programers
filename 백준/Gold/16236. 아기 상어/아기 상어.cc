#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N;
vector<vector<int>> vec(21, vector<int>(21, 0));
int body_size = 2;
int eat_cnt = 0;
int total_cnt = 0;

typedef struct
{
	int x;
	int y;
	int len;
}Data;

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

bool cmp(Data a, Data b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

bool BFS(int sx, int sy)
{
	vector<vector<int>> visited(N, vector<int>(N));
	queue<Data> que;
	visited[sy][sx] = 1;
	Data t; t.x = sx; t.y = sy; t.len = 0;
	que.push(t);

	vector<Data> eat_point;
	while (que.empty() == false)
	{
		int que_size = que.size();
		for (int q = 0; q < que_size; q++)
		{
			Data tmp = que.front();
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = tmp.x + dx[i];
				int ny = tmp.y + dy[i];
				int length = tmp.len;

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[ny][nx] == 0 && vec[ny][nx] <= body_size)
				{
					Data input = { nx,ny,length + 1 };
					que.push(input);
					visited[ny][nx] = 1;

					if (vec[ny][nx] != 0 && vec[ny][nx] < body_size) // 먹기
					{
						eat_point.push_back(input);
					}
				}
			}
		}
		if (eat_point.size() !=0)
		{
			sort(eat_point.begin(), eat_point.end(), cmp);
			vec[sy][sx] = 0;
			vec[eat_point[0].y][eat_point[0].x] = 9;
			total_cnt += eat_point[0].len;
			eat_cnt += 1;
			return true;
		}
	}

	//먹을게 없다...
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> vec[y][x];
		}
	}


	while (1)
	{
		if (body_size == eat_cnt)
		{
			body_size++;
			eat_cnt = 0;
		}

		int sx=0, sy=0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (vec[y][x] == 9)
				{
					sx = x; sy = y;
					break;
				}
			}
		}

		bool tf = BFS(sx, sy);

		if (tf == false)
		{
			cout << total_cnt << endl;
			break;
		}
	}

	return 0;
}

