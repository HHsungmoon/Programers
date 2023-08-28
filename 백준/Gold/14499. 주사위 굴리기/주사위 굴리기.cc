#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;
int SX, SY;
int K;

vector<int> Order;
int Map[21][21];

int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

deque<int> cube_LR(4,0);
deque<int> cube_UD(4, 0);

void run()
{
	int cx = SX;
	int cy = SY;
	for (int k = 0; k < K; k++)
	{
		// 주사위 이동
		if (cx + dx[Order[k]]<0 || cx + dx[Order[k]] > M - 1 || cy + dy[Order[k]] <0 || cy + dy[Order[k]] > N - 1)
		{
			continue;
		}
		cx = cx + dx[Order[k]];
		cy = cy + dy[Order[k]];
		

		// cube의 0번idx가 맨 위, 2번 idx가 바닥

		if (Order[k] == 4)// 남쪽으로
		{
			int tmp = cube_UD.back();
			cube_UD.pop_back();
			cube_UD.push_front(tmp);
			cube_LR[0] = cube_UD[0];
			cube_LR[2] = cube_UD[2];
		}
		else if (Order[k] == 3)//북쪽으로
		{
			int tmp = cube_UD.front();
			cube_UD.pop_front();
			cube_UD.push_back(tmp);
			cube_LR[0] = cube_UD[0];
			cube_LR[2] = cube_UD[2];
		}
		else if (Order[k] == 1) // 동으로 이동
		{
			int tmp = cube_LR.back();
			cube_LR.pop_back();
			cube_LR.push_front(tmp);
			cube_UD[0] = cube_LR[0];
			cube_UD[2] = cube_LR[2];
		}
		else if (Order[k] == 2) // 서쪽으로
		{
			int tmp = cube_LR.front();
			cube_LR.pop_front();
			cube_LR.push_back(tmp);
			cube_UD[0] = cube_LR[0];
			cube_UD[2] = cube_LR[2];
		}

		if (Map[cy][cx] == 0)
		{
			Map[cy][cx] = cube_LR[2];
		}
		else
		{
			cube_LR[2] = Map[cy][cx];
			cube_UD[2] = Map[cy][cx];
			Map[cy][cx] = 0;
		}
		cout << cube_UD[0] << endl;
	}
}


int main()
{
	cin >> N >> M >> SY >> SX >> K;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> Map[n][m];
		}
	}
	Order.resize(K);
	for (int k = 0; k < K; k++)
		cin >> Order[k];

	run();

	return 0;
}