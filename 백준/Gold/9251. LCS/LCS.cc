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

	vector<int> dp(str1.length(),0);
	for (int i = 0; i < str2.length(); i++)
	{
		char c = str2[i]; int cnt = 0;
		for (int t = 0; t < str1.length(); t++)
		{	
			if (cnt < dp[t])
				cnt = dp[t];
			else if (str1[t] == c)
				dp[t] = cnt + 1;
		}
	}
	
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}