#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M, K;

vector<vector<int>> Map;
vector<int> ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS()
{
	vector<vector<int>> visited(N, vector<int>(M, 0));
	
	for (int sx = 0; sx < N; sx++)
	{
		for (int sy = 0; sy < M; sy++) 
		{
			if (Map[sx][sy] == 0 && visited[sx][sy] == 0)
			{
				stack<pair<int,int>> ST;
				int size = 1;
				ST.push(make_pair(sx, sy));
				visited[sx][sy] = 1;

				while (ST.empty() == false)
				{
					int tx = ST.top().first;
					int ty = ST.top().second;
					ST.pop();

					for (int i = 0; i < 4; i++) {
						int nx = tx + dx[i];
						int ny = ty + dy[i];
						if (nx > -1 && nx < N && ny>-1 && ny < M)
						{
							if (Map[nx][ny] == 0 && visited[nx][ny] == 0)
							{
								ST.push(make_pair(nx, ny));
								visited[nx][ny] = 1;
								size++;
							}
						}
					}
				}
				ans.push_back(size);
			}
		}
	}
}

int main()
{
	cin >> M >> N >> K;
	
	Map.resize(N);
	for (int i = 0; i < N; i++) {
		Map[i].resize(M,0);
	}
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				Map[x][y] = 1;
			}
		}
	}

	DFS();

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end(), less<int>());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}

