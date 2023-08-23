#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>>vec(2000+1);
bool visited[2000 + 1];
int answer=0;

void DFS(int idx, int len)
{
	if (len == 4)
	{
		answer = true;
		return;
	}

	visited[idx] = true;
	for (int i = 0; i < vec[idx].size(); i++)
	{
		int n_idx = vec[idx][i];
		if (visited[n_idx] == false)
			DFS(n_idx, len + 1);
		if (answer == true)
			return;
	}
	visited[idx] = false;
}

int main()
{
	int N, M; 
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < N; i++) 
	{
		memset(visited, false, sizeof(visited));
		DFS(i, 0);
		if (answer == true) break;
	}
	if (answer == true) 
		cout << 1 << "\n";
	else 
		cout << 0 << "\n";

	return 0;
}