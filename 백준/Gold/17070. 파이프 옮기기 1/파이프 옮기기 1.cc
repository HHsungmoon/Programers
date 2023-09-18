#include <iostream>
#include <vector>


using namespace std;

int N;
vector<vector<int>> vec;

typedef struct
{
	int px2;
	int py2;
	int type;
}Pype;

bool Move_Right_possible(Pype p)
{
	if (p.type == 1 || p.type==2)
	{
		if (vec[p.py2][p.px2 + 1] == 0)
			return true;
	}
	return false;
}
bool Move_Down_possible(Pype p)
{
	if (p.type == 2 || p.type == 3)
	{
		if (vec[p.py2 + 1][p.px2] == 0)
			return true;
	}
	return false;
}
bool Move_Side_possible(Pype p)
{
	if (vec[p.py2 + 1][p.px2] == 0 && vec[p.py2][p.px2 + 1] == 0 && vec[p.py2 + 1][p.px2 + 1] == 0)
		return true;
	
	return false;
}

int ans = 0;
void Simul(Pype p)
{
	if (p.px2 == N && p.py2 == N)
	{
		ans++;
		return;
	}

	if (Move_Right_possible(p) == true)
	{
		Pype tmp; tmp.px2 = p.px2 + 1; tmp.py2 = p.py2; tmp.type = 1;
		Simul(tmp);
	}
	if (Move_Down_possible(p) == true)
	{
		Pype tmp; tmp.px2 = p.px2; tmp.py2 = p.py2+1; tmp.type = 3;
		Simul(tmp);
	}
	if (Move_Side_possible(p) == true)
	{
		Pype tmp; tmp.px2 = p.px2 + 1; tmp.py2 = p.py2+1; tmp.type = 2;
		Simul(tmp);
	}
}

int main()
{
	cin >> N;
	vec.resize(N + 2);
	for (int y = 0; y < N + 2; y++)
		vec[y].resize(N + 2, 1);

	for (int y = 1; y < N + 1; y++)
	{
		for (int x = 1; x < N + 1; x++)
		{
			cin >> vec[y][x];
		}
	}
	Pype tmp; tmp.py2 = 1; tmp.px2 = 2; tmp.type = 1;
	Simul(tmp);
	cout << ans;
	return 0;
}