#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, R;

vector<vector<int>> vec;
vector<vector<int>> visited;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool BFS(int sx, int sy)
{
	vector<pair<int, int>> arr;

	queue<pair<int,int>> que;
	que.push(make_pair(sx, sy));
	visited[sy][sx] = 1;
	arr.push_back(make_pair(sx, sy));

	int count = vec[sy][sx];

	while (que.empty() == false)
	{
		int px = que.front().first;
		int py = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[ny][nx] == 0)
			{
				int disp = abs(vec[py][px] - vec[ny][nx]);
				if (disp >= L && disp <= R)
				{
					arr.push_back(make_pair(nx, ny));
					count += vec[ny][nx];
					que.push(make_pair(nx, ny));
					visited[ny][nx] = 1;
				}
			}
		}
	}

	if (arr.size() == 1)
		return false;
	else
	{
		count = count / arr.size();
		for (int i = 0; i < arr.size(); i++)
		{
			vec[arr[i].second][arr[i].first] = count;
		}
		return true;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	vec.resize(N);
	for (int y = 0; y < N; y++)
		vec[y].resize(N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin>>vec[y][x];
		}
	}

	int movement_cnt = 0;
	
	while (1)
	{
		bool movement = false;
		visited.resize(N);
		for (int y = 0; y < N; y++)
			visited[y].resize(N);

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (visited[y][x] == 0)
				{
					bool tmp = BFS(x, y);
					if (tmp == true)
						movement = true;
				}
			}
		}
		if (movement == false)
			break;
		else
			movement_cnt++;

		visited.clear();
	}

	cout << movement_cnt;
	return 0;
}