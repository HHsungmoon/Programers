#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	
	int N; 
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	set<int> Good_arr;

	sort(arr.begin(), arr.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int low = 0; int high = N - 1;
		if (i == low)
			low += 1;
		else if (i == high)
			high -= 1;
		while (low < high)
		{
			if (arr[low] + arr[high] < arr[i])
			{
				low += 1;
				if (low == i)
					low += 1;
			}
			else if (arr[low] + arr[high] > arr[i])
			{
				high -= 1;
				if (high == i)
					high -= 1;
			}
			else if (arr[low] + arr[high] == arr[i])
			{
				answer++;
				break;
			}
		}
	}

	cout << answer;
	return 0;
}