#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> dp(N,1);

	for (int i = 0; i < N; i++)
	{
		int len = 0;
		for (int t = 0; t < i; t++)
		{
			if (arr[t]<arr[i] && dp[t] > len)
				len = dp[t];
		}
		dp[i] = len + 1;
	}
	
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}