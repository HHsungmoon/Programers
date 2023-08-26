#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int cx;
	int ry;
	int dir;
}Robot;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int Y, X; 
vector<vector<int>> board(51, vector<int>(51, 0));
Robot rb;

int answer = 0;

bool run()
{
	if (board[rb.ry][rb.cx] == 0) // case 1
	{
		answer++;
		board[rb.ry][rb.cx] = 2;
	}
	
	bool tf = false;
	for (int i = 0; i < 4; i++)
	{
		if (board[rb.ry + dy[i]][rb.cx + dx[i]] == 0)
		{
			tf = true;
			break;
		}
	}

	if (tf == true)
	{
		for (int t = rb.dir + 4-1; t >= rb.dir; t--)
		{
			int i = t % 4;
			if (board[rb.ry + dy[i]][rb.cx + dx[i]] == 0) // 앞으로 전진
			{
				rb.cx = rb.cx + dx[i];
				rb.ry = rb.ry + dy[i];
				rb.dir = i;
				return true;
			}
		}
	}
	else // case 2번
	{
		int i = (rb.dir + 2) % 4;
		if (board[rb.ry + dy[i]][rb.cx + dx[i]] == 2)
		{
			rb.cx = rb.cx + dx[i];
			rb.ry = rb.ry + dy[i];
			return true;
		}
		if (board[rb.ry + dy[i]][rb.cx + dx[i]] == 1)
		{
			return false;
		}
	}
	
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Y >> X;
	cin >> rb.ry >> rb.cx >> rb.dir;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> board[y][x];
		}
	}

	bool a = run();
	while (a == true)
	{
		a = run();
	}
	cout << answer << endl;
	

	return 0;
}