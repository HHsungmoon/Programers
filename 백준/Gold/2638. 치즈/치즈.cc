#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<vector<int>> make_board(vector<vector<int>> vec)
{
	stack<pair<int, int>> stack;
	stack.push(make_pair(0, 0));
	vec[0][0] = -1;

	while (stack.empty() == false)
	{
		int px = stack.top().first;
		int py = stack.top().second;
		stack.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx >= 0 && ny >= 0 && nx<M &&  ny <N && vec[ny][nx] == 0)
			{
				stack.push(make_pair(nx, ny));
				vec[ny][nx] = -1;
			}
		}
	}
	return vec;
}

vector<vector<int>> remake_board(vector<vector<int>> vec)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (vec[y][x] == -1)
				vec[y][x] = 0;
		}
	}
	return vec;
}

vector<vector<int>> Melt(vector<vector<int>> vec)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (vec[y][x] == 1)
			{
				int cnt = 0;
				for (int i = 0; i < 4; i++)
				{
					if (vec[y + dy[i]][x + dx[i]] == -1)
						cnt++;
				}
				if (cnt >= 2)
				{
					vec[y][x] = 0;
				}
			}
		}
	}
	return vec;
}

bool check_end(vector<vector<int>> vec)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (vec[y][x] == 1)
				return false;
		}
	}
	return true;
}

int main()
{

	cin >> N >> M;
	vector<vector<int>> vec(N, vector<int>(M, 0));

	for (int y= 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> vec[y][x];
		}
	}

	int answer = 0;
	while (check_end(vec) == false)
	{
		vec = make_board(vec);
		vec = Melt(vec);
		answer++;
		vec = remake_board(vec);
	}
	cout << answer;


	return 0;
}