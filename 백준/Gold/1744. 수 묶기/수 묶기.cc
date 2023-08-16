#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; 	int answer = 0;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	vector<int> minus; vector<int> zero; vector<int> plus;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
			minus.push_back(arr[i]);
		else if (arr[i] == 0)
			zero.push_back(arr[i]);
		else if (arr[i] == 1)
			answer++;
		else
			plus.push_back(arr[i]);
	}

	sort(plus.begin(), plus.end(), greater<int>());
	for (int i = 0; i < plus.size() / 2; i++)
	{
		answer += plus[i*2] * plus[i*2 + 1];
	}
	if (plus.size() % 2 == 1)
		answer += *(plus.end() - 1);

	for (int i = 0; i < minus.size()/2; i++)
	{
		answer += minus[i * 2] * minus[i * 2 + 1];
	}
	if (minus.size() % 2 == 1)
	{
		if (zero.size() == 0)
		{
			answer += *(minus.end() - 1);
		}
	}
	cout << answer;

	return 0;
}