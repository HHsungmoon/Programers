#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<vector<int>> vec;

bool find_load(vector<int> load)
{ 
	int same_len = 1; 
	for (int i = 1; i < load.size(); i++)
	{
		if (load[i] == load[i - 1])
		{
			same_len++;
		}
		else if (load[i] > load[i - 1]) // 올라가기
		{
			if (same_len >= L && load[i] - load[i-1] == 1)
			{
				same_len = 1;
			}
			else
			{
				return false;
			}
		}
		else if (load[i] < load[i - 1])
		{
			if (load[i - 1] - load[i] == 1)
			{
				same_len = 0;
				int t;
				for (t = i; t < N; t++)
				{
					if (load[t] == load[i])
					{
						same_len++;
						if (same_len == L)
							break;
					}
					else
					{
						break;
					}
				}
				if (same_len == L)
				{
					i = t;
					same_len = 0;
				}
				else
					return false;
				
			}
			else
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> N >> L;
	vec.resize(N);
	for (int y = 0; y < N; y++)
	{
		vec[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			cin >> vec[y][x];
		}
	}


	int ans = 0;
	for (int y = 0; y < N; y++)
	{
		vector<int> tmp = vec[y];
		if (find_load(tmp) == true)
		{
			ans++;
		}
	}
	for (int x = 0; x < N; x++)
	{
		vector<int> tmp;
		for (int y = 0; y < N; y++)
		{
			tmp.push_back(vec[y][x]);
		}
		if (find_load(tmp) == true)
		{
			ans++;
		}
	}

	cout << ans;

	return 0;
}