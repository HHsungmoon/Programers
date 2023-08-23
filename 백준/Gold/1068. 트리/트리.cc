#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int N;
int del;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N; int tmp;

	vector<vector<int>> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if(tmp != -1)
			vec[tmp].push_back(i);
	}
	cin >> del;

	vector<int> vec_size(N);
	for (int i = 0; i < N; i++)
	{
		vec_size[i] = vec[i].size();
	}

	for (int i = 0; i < N; i++)
	{
		for (int t = 0; t < vec[i].size(); t++)
		{
			if (vec[i][t] == del)
				vec_size[i] -= 1;
		}
	}

	stack<int> stack;
	stack.push(del);
	while (stack.empty() == false)
	{
		int node = stack.top();
		stack.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			stack.push(vec[node][i]);
		}
		vec_size[node] = -1;
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (vec_size[i] == 0)
			answer++;
	}
	cout << answer;
	return 0;
}