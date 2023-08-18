#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> vec(3, vector<int>(3,1));
	vec[1][1] = 0;
	int cnt = 9;
	while (cnt <= N)
	{
		int len = vec.size();
		vector <vector<int>> board(cnt, vector<int>(cnt, 0));
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (x == 1 && y == 1)
				{
					for (int i = 0; i < vec.size(); i++)
					{
						for (int t = 0; t < vec[i].size(); t++)
						{
							board[x * len + i][y * len + t] = 0;
						}
					}
				}
				else
				{
					for (int i = 0; i < vec.size(); i++)
					{
						for (int t = 0; t < vec[i].size(); t++)
						{
							board[x * len + i][y * len + t] = vec[i][t];
						}
					}
				}
			}
		}
		vec = board;
		cnt *= 3;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int t = 0; t < vec[i].size(); t++)
		{
			if (vec[t][i] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}