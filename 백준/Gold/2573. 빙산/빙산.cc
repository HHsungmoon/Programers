#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
int answer = 0;

int dx[4] = { -1,1,0,0};
int dy[4] = { 0,0,-1,1 };

vector<vector<int>> melt_ice(vector<vector<int>> vec)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (vec[y][x] != 0)
			{
				int sea = 0;
				for (int i = 0; i < 4; i++)
				{
					if (vec[y + dy[i]][x + dx[i]] == 0)
						sea += 1;
				}

				vec[y][x] -= sea;
				if (vec[y][x] <= 0)
					vec[y][x] = -1;
			}
		}
	}
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

int DFS(vector<vector<int>> vec)
{
	vector<vector<int>> visited(N, vector<int>(M, 0));
	int cnt = 0;

	for (int py = 0; py < N; py++)
	{
		for (int px = 0; px < M; px++)
		{
			if (vec[py][px] != 0 && visited[py][px] == 0)
			{
				if (cnt == 0)
				{
					// stack 구현방식 백준 2573
					stack<pair<int, int>> st;
					st.push(make_pair(px, py));
					while (st.empty() == false)
					{
						int x = st.top().first;
						int y = st.top().second;
						st.pop();

						for (int i = 0; i < 4; i++)
						{
							if (vec[y + dy[i]][x + dx[i]] != 0 && visited[y + dy[i]][x + dx[i]] == 0)
							{
								st.push(make_pair(x + dx[i], y + dy[i]));
								visited[y + dy[i]][x + dx[i]] = 1;
							}
						}	
					}
					cnt += 1;
				}
				else // cnt가 0이 아니다. 이미 빙산이 두개로 나뉨
				{
					return 2;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M;
	vector<vector<int>> vec(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> vec[y][x];
		}
	}

	while (1)
	{
		int dfs = DFS(vec);
		if (dfs == 1)
		{
			vec = melt_ice(vec);
			answer += 1;
		}
		else if (dfs == 0)
		{
			answer = 0;
			break;
		}
		else if (dfs == 2)
			break;
	}
	cout << answer;
	return 0;
}