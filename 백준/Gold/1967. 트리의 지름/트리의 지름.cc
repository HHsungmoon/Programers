#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int N;
vector<int> leaf_node;


int DFS(vector<vector<pair<int, int>>> vec)
{
	int answer = 0;

	while (leaf_node.size() > 1)
	{
		int start = leaf_node.back();
		leaf_node.pop_back();

		stack<pair<int,int>> st;
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

		int max_len = *max_element(visited.begin(), visited.end());
		answer = max(max_len, answer);
	}

	return answer;
}

int main()
{
	cin >> N;
	vector<vector<pair<int,int>>> vec(N+1);
	
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (vec[i].size() == 1)
			leaf_node.push_back(i);
	}
	sort(leaf_node.begin(), leaf_node.end(), greater<int>());

	cout << DFS(vec);

	return 0;
}