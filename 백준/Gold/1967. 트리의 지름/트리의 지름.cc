#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int N;

int DFS(int start, vector<vector<pair<int, int>>> vec, int type)
{
	int answer = 0;

	stack<pair<int, int>> st;
	st.push(make_pair(start, 0));
	vector<int> visited(N + 1, 0);
	visited[start] = 1;
	while (st.empty() == false)
	{
		int node = st.top().first;
		int len = st.top().second;
		st.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			if (visited[vec[node][i].first] == 0)
			{
				st.push(make_pair(vec[node][i].first, len + vec[node][i].second));
				visited[vec[node][i].first] = len + vec[node][i].second;
			}
		}
	}

	if (type == 0)
	{
		answer = max_element(visited.begin(), visited.end()) - visited.begin();
	}
	else if (type == 1)
	{
		answer = *max_element(visited.begin(), visited.end());
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	vector<vector<pair<int, int>>> vec(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	int endp = DFS(1, vec, 0);
	std::cout << DFS(endp,vec,1);

	return 0;
}