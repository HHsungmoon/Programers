#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max_num 40000000

int V, E;
vector<vector<int>> vec;

int Floyd_Warshall()
{
	for (int k = 1; k <= V; k++)  // k = 거쳐가는 노드
		for (int i = 1; i <= V; i++)  // i = 출발 노드
			for (int j = 1; j <= V; j++)  // j = 도착 노드
				vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);			

	int ans = Max_num;
	for (int i = 1; i < V + 1; i++)
	{
		ans = min(vec[i][i], ans);
	}

	if (ans == Max_num)
		return -1;
	return ans;
}

int main()
{
	cin >> V >> E;
	vec.resize(V + 1);
	for (int v = 0; v < V + 1; v++)
	{
		vec[v].resize(V + 1, Max_num);
	}
	for (int e = 0; e < E; e++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a][b] = c;
	}

	cout << Floyd_Warshall();

	return 0;
}