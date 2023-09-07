#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define Max_num 100000001

int N, E;



int Dijecstra(int st, int ed, vector<vector<pair<int, int>>> vec)
{
	vector<int> visited(N+1, 0);
	vector<int> dij(N + 1, Max_num);

	priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;

	pq.push(make_pair(0, st)); // 순서- 길이, 다음노드
	dij[st] = 0;

	while (pq.empty() == false)
	{
		int node = pq.top().second;
		int len = pq.top().first;
		pq.pop();

		if (visited[node] == 0)
		{
			visited[node] = 1;

			for (int i = 0; i < vec[node].size(); i++)
			{
				int next = vec[node][i].first;
				int next_len = len+vec[node][i].second;
				if (next_len < dij[next])
				{
					dij[next] = next_len;
					pq.push(make_pair(next_len, next));
				}
			}
		}

		if (visited[ed] == 1)
		{
			return dij[ed];
		}
	}
	return dij[ed];
}


int main()
{
	cin >> N >> E;

	vector<vector<pair<int, int>>> vec(N+1);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	int p1, p2;
	cin >> p1 >> p2;
	
	vector<int> tmp;
	
	int num12 = Dijecstra(1, p1, vec);
	int num13 = Dijecstra(1, p2, vec);
	int num24 = Dijecstra(p1, N, vec);
	int num34 = Dijecstra(p2, N, vec);
	int num23 = Dijecstra(p1, p2, vec);

	tmp.push_back(num12 + num23 + num34);
	tmp.push_back(num13 + num23 + num24);
	tmp.push_back(num12 + num12 + num13 + num34);
	tmp.push_back(num13 + num13 + num12 + num24);
	tmp.push_back(num12 + num23 + num23 + num24);
	tmp.push_back(num13 + num23 + num23 + num34);

	int ans = *min_element(tmp.begin(), tmp.end());
	if (ans >= Max_num)
		ans = -1;
	cout << ans;

	return 0;
}