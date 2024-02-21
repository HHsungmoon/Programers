#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<long>> DP(101, vector<long>(10,0));
	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int n = 1; n < N; n++) 
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
			{
				DP[n + 1][i] = DP[n][i + 1];
			}
			else if (i == 9)
			{
				DP[n + 1][i] = DP[n][i - 1];
			}
			else
			{
				DP[n + 1][i] = (DP[n][i - 1] + DP[n][i + 1])%1000000000;
			}
		}
	}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << DP[N][i] << " ";
	//}
	//cout << endl << endl;

	long ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += DP[N][i];
		ans = ans % 1000000000;
	}
	cout << ans;
	return 0;
}