#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(pair<int,int>a, pair<int,int>b)
{
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end(), Compare);

	vector<int> dp(N,1);
	for (int i = 0; i < N; i++)
	{
		int len = 0;
		for (int t = 0; t < i; t++)
		{
			if (vec[i].second > vec[t].second && dp[t] > len)
				len = dp[t];
		}
		dp[i] = len + 1;
	}
	cout << N-*max_element(dp.begin(), dp.end());
	return 0;
}