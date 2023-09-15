
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Y, X;
vector<vector<int>> vec;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<vector<int>> BFS()
{
	vector<vector<int>> up_vec = vec;
	queue<pair<int, int>> que;

	que.push(make_pair(0, 0));
	up_vec[0][0] = -1;
	while (que.empty() == false)
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < X && ny < Y)
			{
				if (vec[ny][nx] == 0 && up_vec[ny][nx] == 0)
				{
					up_vec[ny][nx] = -1;
					que.push(make_pair(nx, ny));
				}
			}
		}
	}

	return up_vec;
}

void update_map()
{
	for (int y = 0; y < vec.size(); y++)
	{
		for (int x = 0; x < vec[y].size(); x++)
		{
			if (vec[y][x] == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (vec[y + dy[i]][x + dx[i]] == -1)
					{
						vec[y][x] = 0;
						break;
					}
				}
			}
		}
	}
}

void rebind()
{
	for (int y = 0; y < vec.size(); y++)
	{
		for (int x = 0; x < vec[y].size(); x++)
		{
			if (vec[y][x] == -1)
				vec[y][x] = 0;
		}
	}
}

int count_che()
{
	int cnt = 0;
	for (int y = 0; y < vec.size(); y++)
	{
		for (int x = 0; x < vec[y].size(); x++)
		{
			if (vec[y][x] == 1)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> Y >> X;
	vec.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		vec[y].resize(X);
		for (int x = 0; x < X; x++)
		{
			cin >> vec[y][x];
		}
	}

	int cheese = count_che(); int cnt = 0;
	while (1)
	{
		vec = BFS();
		update_map();
		int up_che = count_che();
		if (up_che == 0)
			break;
		else
			cheese = up_che;
		rebind();
		cnt++;
	}

	cout << cnt + 1 << " " << cheese << endl;

	return 0;
}