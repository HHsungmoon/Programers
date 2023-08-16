#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector<int> dp_l(N,1);
	for (int i = 0; i < N; i++)
	{
		int len = 0;
		for (int t = 0; t < i; t++)
		{
			if (vec[i] > vec[t] && dp_l[t] > len)
				len = dp_l[t];
		}
		dp_l[i] = len + 1;
	}

	reverse(vec.begin(), vec.end());

	vector<int> dp_r(N, 1);
	for (int i = 0; i < N; i++)
	{
		int len = 0;
		for (int t = 0; t < i; t++)
		{
			if (vec[i] > vec[t] && dp_r[t] > len)
				len = dp_r[t];
		}
		dp_r[i] = len + 1;
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < dp_l[i] + dp_r[N-i-1])
			max = dp_l[i] + dp_r[N - i - 1];
	}
	cout << max - 1;
	return 0;
}