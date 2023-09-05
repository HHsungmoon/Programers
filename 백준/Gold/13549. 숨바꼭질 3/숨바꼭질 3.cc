#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max_num 100002

vector<vector<pair<int, int>>> vec;  // 순서: 길이, to노드
int N, K;

void make_vec()
{
	vec[0].push_back(make_pair(1, 1));
	vec[0].push_back(make_pair(0, 0));

	for (int i = 1; i < 100000; i++)
	{
		vec[i].push_back(make_pair(1, i + 1));
		vec[i].push_back(make_pair(1, i - 1));
		if(i*2 <= 100000)
			vec[i].push_back(make_pair(0, i * 2));
	}

	vec[100000].push_back(make_pair(1, 100000 - 1));
}

int Dijecstra()
{
	vector<int> di(100001, Max_num);
	vector<int> visited(100001, 0);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	di[N] = 0;
	pq.push(make_pair(0, N));
	while (pq.empty() == false)
	{
		int tmp = pq.top().second;
		int len = pq.top().first;
		pq.pop();

		if (visited[tmp] == 0)
		{
			visited[tmp] = 1;

			for (int i = 0; i < vec[tmp].size(); i++)
			{
				int next_node = vec[tmp][i].second;
				int next_len = vec[tmp][i].first + len;

				if (visited[vec[tmp][i].second] == 0)
				{
					if (next_len < di[next_node])
					{
						di[next_node] = next_len;
						pq.push(make_pair(next_len, next_node));
					}
				}
			}
		}

		if (visited[K] == 1)
			return di[K];
	}

	return di[K];
}

int main()
{
	cin >> N >> K;
	vec.resize(100001);

	make_vec();

	cout << Dijecstra();

	return 0;
}