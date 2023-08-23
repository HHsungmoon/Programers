#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int DFS1(int stnode, vector<vector<pair<int, int>>> vec)
{
	int answer = 0;

	vector<int> visited(N + 1);
	stack<pair<int, int>> stack;
	stack.push(make_pair(stnode, 0));
	visited[stnode] = 1;
	while (stack.empty() == false)
	{
		int node = stack.top().first;
		int length = stack.top().second;
		stack.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			if (visited[vec[node][i].first] == 0)
			{
				int next_node = vec[node][i].first;
				int next_len = vec[node][i].second + length;
				stack.push(make_pair(next_node, next_len));
				visited[vec[node][i].first] = next_len;
			}
		}
	}
	answer = max_element(visited.begin(), visited.end()) - visited.begin();
	
	return answer;
}

int DFS2(int stnode, vector<vector<pair<int, int>>> vec)
{
	int answer = 0;

	vector<int> visited(N + 1);
	stack<pair<int, int>> stack;
	stack.push(make_pair(stnode, 0));
	visited[stnode] = 1;
	while (stack.empty() == false)
	{
		int node = stack.top().first;
		int length = stack.top().second;
		stack.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			if (visited[vec[node][i].first] == 0)
			{
				int next_node = vec[node][i].first;
				int next_len = vec[node][i].second + length;
				stack.push(make_pair(next_node, next_len));
				visited[vec[node][i].first] = next_len;
			}
		}
	}
	int tmp_max = *max_element(visited.begin(), visited.end());
	answer = max(answer, tmp_max);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<vector<pair<int, int>>> vec(N + 1);
	
	for (int i = 0; i < N; i++)
	{
		int st = 0;
		cin >> st;
		int end, len;
		while (true)
		{
			cin >> end;
			if (end == -1)
				break;
			else
			{
				cin >> len;
				vec[st].push_back(make_pair(end, len));
			}
		}
	}

	int endp = DFS1(1, vec);
	cout << DFS2(endp,vec);

	return 0;
}