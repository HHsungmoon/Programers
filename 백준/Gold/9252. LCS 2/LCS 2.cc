#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string str1;
	string str2;

	cin >> str1;
	cin >> str2;

	vector<vector<int>> dp(str2.length()+1, vector<int>(str1.length()+1, 0));
	for (int i = 0; i < str2.length(); i++)
	{
		char c = str2[i];
		for (int t = 0; t < str1.length(); t++)
		{
			if (c == str1[t])
				dp[i + 1][t + 1] = dp[i][t] + 1;
			else
				dp[i + 1][t + 1] = max(dp[i][t + 1], dp[i + 1][t]);
		}
	}

	cout << dp[str2.length()][str1.length()]<< endl;

	int i = str2.length(); int t = str1.length();
	vector<char> answer;
	while (dp[i][t]>0)
	{
		if (dp[i][t] == dp[i][t - 1])
			t = t - 1;
		else if (dp[i][t] == dp[i - 1][t])
			i = i - 1;
		else
		{
			answer.push_back(str1[t - 1]);
			t = t - 1;
			i = i - 1;
		}
	}

	
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];

	return 0;
}