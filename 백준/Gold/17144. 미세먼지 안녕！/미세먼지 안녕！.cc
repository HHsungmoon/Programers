#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, T;

vector<vector<int>> vec;
int ax, ay;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<vector<int>> spread()
{
	vector<vector<int>> tmp(R, vector<int>(C, 0));

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			int num = vec[y][x] / 5;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < C && ny < R && vec[ny][nx] != -1)
				{
					tmp[ny][nx] += num;
					cnt++;
				}
			}
			tmp[y][x] += vec[y][x] - num * cnt;
		}
	}

	return tmp;
}

void Bleed_move()
{
	int a1x = ax;
	int a1y = ay - 1;
	int a2x = ax;
	int a2y = ay;

	for (int y = a1y; y > 0; y--)
	{
		vec[y][a1x] = vec[y - 1][a1x];
	}
	for (int x = 0; x < C-1; x++)
	{
		vec[0][x] = vec[0][x + 1];
	}
	for (int y = 0; y < a1y; y++)
	{
		vec[y][C - 1] = vec[y + 1][C - 1];
	}
	for (int x = C - 1; x > 1; x--)
	{
		vec[a1y][x] = vec[a1y][x - 1];
	}vec[a1y][1] = 0;
	//-----------------------------------------
	for (int y = a2y; y<R-1; y++)
	{
		vec[y][a2x] = vec[y+1][a2x];
	}
	for (int x = 0; x < C - 1; x++)
	{
		vec[R-1][x] = vec[R-1][x + 1];
	}
	for (int y = R-1; y>a2y; y--)
	{
		vec[y][C - 1] = vec[y-1][C - 1];
	}
	for (int x = C - 1; x > 1; x--)
	{
		vec[a2y][x] = vec[a2y][x - 1];
	}vec[a2y][1] = 0;

	vec[a1y][a1x] = -1;
	vec[a2y][a2x] = -1;
}

int main()
{
	cin >> R >> C >> T;
	vec.resize(R);
	for (int y = 0; y < R; y++)
	{
		vec[y].resize(C);
		for (int x = 0; x < C; x++)
		{
			cin >> vec[y][x];
			if (vec[y][x] == -1)
			{
				ax = x; ay = y; // 공기청정기 아랫값
			}
				
		}
	}

	for (int i = 0; i < T; i++)
	{
		vec = spread();
		Bleed_move();
	}

	int count = 2;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			count += vec[y][x];
		}
	}
	cout << count;

	return 0;
}