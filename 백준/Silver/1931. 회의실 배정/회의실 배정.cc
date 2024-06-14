#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
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

	sort(vec.begin(), vec.end(), cmp);
	int cnt = 0;

	int endtime = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (endtime <= vec[i].first)
		{
			cnt++;
			endtime = vec[i].second;
		}
	}
	cout << cnt << endl;
	return 0;
}