#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int Map[102][102];
int N;
int K;
vector<pair<int, char>> dir;
int cnt = 0;
int head_dir = 0;

// 동 북 서 남
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

deque<pair<int, int>> sxy;

bool Move_snake()
{
	int nx = sxy[0].first + dx[head_dir];
	int ny = sxy[0].second + dy[head_dir];

	if (Map[ny][nx] == 0)
	{
		Map[sxy.back().second][sxy.back().first] = 0;
		Map[ny][nx] = 1;

		sxy.push_front(make_pair(nx, ny));
		sxy.pop_back();
	}
	else if (Map[ny][nx] == 2) // 사과먹기
	{
		Map[ny][nx] = 1;
		sxy.push_front(make_pair(nx, ny));
	}
	else if (Map[ny][nx] == -1 || Map[ny][nx] == 1) // 종료
	{
		return false;
	}
	return true;
}

int main()
{
	cin >> N;
	cin >> K;

	for (int y = 0; y < N+2; y++)
	{
		for (int x = 0; x < N+2; x++)
		{
			if (y == 0 || x == 0 || y == N + 1 || x == N + 1)
				Map[y][x] = -1;
			else
				Map[y][x] = 0;
		}
	}

	Map[1][1] = 1;
	sxy.push_back(make_pair(1, 1));

	for (int k = 0; k < K; k++)
	{
		int x, y;
		cin >> y >> x;
		Map[y][x] = 2; // 사과 2
	}
	int d_num;
	cin >> d_num;
	for (int i = 0; i < d_num; i++)
	{
		int n; char c;
		cin >> n >> c;
		dir.push_back(make_pair(n, c));
	}

	bool end = true; int idx=0;
	while (end)
	{
		end = Move_snake();
		cnt++;

		if ( idx< d_num && dir[idx].first == cnt)
		{
			if (dir[idx].second == 'D') // 오른쪽 90도
			{
				head_dir = (4-1 + head_dir) % 4;
			}
			else if (dir[idx].second == 'L')
			{
				head_dir = (head_dir + 1) % 4;
			}
			idx++;
		}
	}
	cout << cnt << endl;
	return 0;
}

