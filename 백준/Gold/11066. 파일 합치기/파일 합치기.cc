#include <iostream>
#include <vector>

using namespace std;

int INF = 100000000;

int T;
int K;
int input;
vector<int> answer;
vector<int> Sum;
vector<vector<int>> dp;

int REQ(int st, int end)
{
	if (st == end)
	{
		return 0;
	}
	if (dp[end][st] != INF)
	{
		return dp[end][st];
	}


	for (int i = st; i < end; i++)
	{
		int L = REQ(st, i);
		int R = REQ(i + 1, end);

		dp[end][st] = min(dp[end][st], L + R + (Sum[end+1] - Sum[st]));
	}

	return dp[end][st];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	answer.resize(T);

	for (int t = 0; t < T; t++)
	{
		cin >> K;
		Sum.resize(K + 1); Sum[0] = 0;
		dp.clear();
		dp.resize(K);
		for (int k = 0; k < K; k++)
			dp[k].resize(K,INF);

		for (int k = 0; k < K; k ++)
		{
			cin >> dp[0][k];
			Sum[k+1] = Sum[k] + dp[0][k];
		}

		int ans = REQ(0, K - 1);
		answer[t] = ans;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}