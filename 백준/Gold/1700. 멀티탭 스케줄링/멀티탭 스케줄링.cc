#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	vector<int> mtap(N, 0);
	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	int count = 0;
	for (int k = 0; k < K; k++)
	{
		if (find(mtap.begin(), mtap.end(), arr[0]) != mtap.end()) // 지금 사용할 플러그가 이미 꽂힌 경우
		{
		}
		else if (find(mtap.begin(), mtap.end(), 0) != mtap.end()) // 빈 칸이 있다 
		{
			for (int i = 0; i < N; i++)
			{
				if (mtap[i] == 0)
				{
					mtap[i] = arr[0];
					break;
				}
			}
		}
		else
		{
			// case 1 - 안쓰는 놈이 있을 때
			bool case_type = false;
			for (int i = 0; i < N; i++)
			{
				if (find(arr.begin(), arr.end(), mtap[i]) == arr.end())  // 더 안쓰는 플러그가 있다
				{
					mtap[i] = arr[0];
					count++;
					case_type = true;
					break;
				}
			}

			// case 2 - 안쓰는 놈이 없을때 우선순위
			if (case_type == false)
			{
				int max_dist = 0; int out_tmp = 0;
				for (int i = 0; i < N; i++)
				{
					for (int t = 0; t < size(arr); t++)
					{
						if (arr[t] == mtap[i])
						{
							if (max_dist < t)
							{
								max_dist = t;
								out_tmp = i;
							}
							break;
						}
					}
				}
				// 뽑을 플러그 결정됨
				mtap[out_tmp] = arr[0];
				count++;
			}
		}

		arr.erase(arr.begin());
	}
	cout << count;

	return 0;
}