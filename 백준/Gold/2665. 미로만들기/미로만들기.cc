#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define Max_Num 10000

int N;
vector<vector<int>> board;

typedef struct
{
	int x;
	int y;
	int cnt;
}Data;

struct cmp
{
	bool operator()(Data a, Data b)
	{
		if (a.cnt == b.cnt)
		{
			if (a.y == b.y)
			{
				return a.x < b.x;
			}
			return a.y < b.y;
		}
		return a.cnt > b.cnt;
	}
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int Dijecstra()
{
	vector<vector<int>> visited(N, vector<int>(N, Max_Num));
	priority_queue<Data, vector<Data>, cmp> pq;

	Data t; t.x = 0; t.y = 0; t.cnt = 0;
	pq.push(t);

	while (pq.empty() == false)
	{
		Data pos = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			Data tmp;
			tmp.x = pos.x + dx[i];
			tmp.y = pos.y + dy[i];

			if (tmp.x >= 0 && tmp.x < N && tmp.y >= 0 && tmp.y < N)
			{
				if (board[tmp.y][tmp.x] == 0)
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

	return visited[N - 1][N - 1];
}

int main()
{
	cin >> N;
	board.resize(N);
	for (int y = 0; y < N; y++)
	{
		string tmp;
		cin >> tmp;
		board[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			board[y][x] = tmp[x] - '0';
		}
	}

	cout << Dijecstra();

	return 0;
}