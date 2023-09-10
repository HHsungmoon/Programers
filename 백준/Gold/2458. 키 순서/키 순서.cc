#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;


int Floyd_warshall(vector<vector<int>> vec)
{
	vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
	queue<pair<int,int>> que;

	for (int i = 1; i < N+1; i++)
	{
		que.push(make_pair(i,1));
		que.push(make_pair(i, -1));
		DP[i][i] = 1;
		while (que.empty() == false)
		{
			int node = que.front().first;
			int type = que.front().second;
			que.pop();

			for (int t = 1; t < N+1; t++)
			{
				if (vec[node][t] == type && DP[i][t] == 0)
				{
					DP[i][t] = 1;
					que.push(make_pair(t,type));
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i < N+1; i++)
	{
		bool tf = true;
		for (int t = 1; t < N+1; t++)
		{
			if (DP[i][t] == 0)
			{
				tf = false;
				break;
			}
		}
		if (tf == true)
			cnt++;
	}
	return cnt;
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> vec(N+1,vector<int>(N+1,0));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a][b] = 1;
		vec[b][a] = -1;
	}

	cout << Floyd_warshall(vec);

	return 0;
}