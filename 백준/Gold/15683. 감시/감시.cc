#include <iostream>
#include <vector>

using namespace std;

int N, M;

int cnt_cctv = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

vector<pair<int, int>> cctv;

vector<vector<int>> checked(vector<vector<int>> board, int dir, int x, int y)
{
	int cx = x + dx[dir];
	int cy = y + dy[dir];
	while (cx >= 0 && cy >= 0 && cx < M && cy < N)
	{
		if (board[cy][cx] == 0)
		{
			board[cy][cx] = -1;
			
		}
		else if (board[cy][cx] == 6)
		{
			break;
		}
		cx = cx + dx[dir];
		cy = cy + dy[dir];
	}
	return board;
}

int count(vector<vector<int>> board, vector<pair<int, int>> tv)
{
	if (tv.size() > 0)
	{
		int x = tv.back().first;
		int y = tv.back().second;
		tv.pop_back();

		if (board[y][x] == 1)
		{
			board[y][x] = -1;
			int d1 = count(checked(board, 0, x, y),tv);
			int d2 = count(checked(board, 1, x, y), tv);
			int d3 = count(checked(board, 2, x, y),tv);
			int d4 = count(checked(board, 3, x, y), tv);
			int t1 = min(d1, d2); int t2 = min(d3, d4);
			return min(t1, t2);
		}
		else if (board[y][x] == 2)
		{
			board[y][x] = -1;
			int d1 = count(checked(checked(board, 0, x, y), 2, x, y), tv);
			int d2 = count(checked(checked(board, 1, x, y), 3, x, y), tv);
			return min(d1, d2);
		}
		else if (board[y][x] == 3)
		{
			board[y][x] = -1;
			int d1 = count(checked(checked(board, 0, x, y), 1, x, y), tv);
			int d2 = count(checked(checked(board, 1, x, y), 2, x, y), tv);
			int d3 = count(checked(checked(board, 2, x, y), 3, x, y), tv);
			int d4 = count(checked(checked(board, 3, x, y), 0, x, y), tv);
			int t1 = min(d1, d2); int t2 = min(d3, d4);
			return min(t1, t2);
		}
		else if (board[y][x] == 4)
		{
			board[y][x] = -1;
			int d1 = count(checked(checked(checked(board, 0, x, y), 1, x, y), 2, x, y), tv);
			int d2 = count(checked(checked(checked(board, 1, x, y), 2, x, y), 3, x, y), tv);
			int d3 = count(checked(checked(checked(board, 2, x, y), 3, x, y), 0, x, y), tv);
			int d4 = count(checked(checked(checked(board, 3, x, y), 0, x, y), 1, x, y), tv);
			int t1 = min(d1, d2); int t2 = min(d3, d4);
			return min(t1, t2);
		}
		else if (board[y][x] == 5)
		{
			board[y][x] = -1;
			int d1 = count(checked(checked(checked(checked(board, 0, x, y), 1, x, y), 2, x, y), 3, x, y), tv);
			return d1;
		}
	}
	else
	{
		int tmp = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (board[y][x] == 0)
				{
					tmp++;
				}
			}
		}
		return tmp;
	}
}

int main()
{
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
			if (board[y][x] >= 1 && board[y][x] <= 5)
				cctv.push_back(make_pair(x, y));
		}
	}

	cout << count(board,cctv);

	return 0;
}