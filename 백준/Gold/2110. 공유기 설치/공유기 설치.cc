#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(vector<int> vec, int min_dist)
{
	int prev = vec[0]; int wifi = 1;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] - prev >= min_dist)
		{
			wifi += 1;
			prev = vec[i];
		}
	}
	return wifi;
}

int main()
{
	int N, C;
	cin >> N >> C;
	vector<int> vec; int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());

	int low = 1; int high = vec[N-1]; int mid;

	int result = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		int cnt = func(vec, mid);
		if (C>cnt)
		{
			high = mid - 1;
		}
		else
		{
			result = max(mid, result);
			low = mid + 1;
		}
	}
	cout << result;
	return 0;
}