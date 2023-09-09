#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define Max_num 100000

int M, N; // m이 가로
vector<vector<int>> board;

typedef struct
{
	int x;
	int y;
	int cnt;
}Data;

struct cmp {
	bool operator()(Data a, Data b)
	{
		if (a.cnt == b.cnt)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.cnt > b.cnt;
	}
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int Movement()
{
	vector<vector<int>> visited(N, vector<int>(M, Max_num));
	visited[0][0] = 0;

	priority_queue<Data, vector<Data>, cmp> pq;
	Data t; t.x = 0; t.y = 0; t.cnt = 0;
	pq.push(t);

	while (pq.empty() == false)
	{
		Data pos = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N)
			{
				Data tmp; tmp.x = nx; tmp.y = ny;
				if (board[ny][nx] == 1) // 다음이 벽일 때
					tmp.cnt = pos.cnt + 1;
				else
					tmp.cnt = pos.cnt;

				if (visited[tmp.y][tmp.x] > tmp.cnt)
				{
					visited[tmp.y][tmp.x] = tmp.cnt;
					pq.push(tmp);
				}
			}
		}
	}
	return visited[N - 1][M - 1];
}

int main()
{
	cin >> M >> N;

	board.resize(N);
	for (int y = 0; y < N; y++)
	{
		string str; 
		cin >> str;

		board[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			board[y][x] = str[x] - '0';
		}
	}

	cout << Movement();

	return 0;
}