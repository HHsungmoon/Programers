#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max_num 100000001

typedef struct
{
	int from;
	int to;
	int len;
}Node;

int N, M;
int Start, End;
vector<Node> vec;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // first가 길이, second가 다음노드
//priority_queue<pair<int, int>> pq;

int Dijecstra()
{
	vector<int> visited(N + 1, 0);
	vector<int> Dij(N + 1, Max_num);

	Dij[Start] = 0;
	pq.push(make_pair(0, Start));

	while (pq.empty() == false)
	{
		int node = pq.top().second;
		int length = pq.top().first;
		pq.pop();

		if (visited[node] != 1)
		{
			visited[node] = 1;
			
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].from == node && visited[vec[i].to] == 0)
				{
					//Dij[vec[i].to] = min(Dij[vec[i].to], length + vec[i].len);
					// Dij의 값이 최소로 업데이트 되는 상황에서만 pq에 넣는다
					if (Dij[vec[i].to] > length + vec[i].len)
					{
						Dij[vec[i].to] = length + vec[i].len;
						pq.push(make_pair(Dij[vec[i].to], vec[i].to));
					}
				}
			}
			if (visited[End] == 1)
				return Dij[End];
		}
	}
	return Dij[End];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vec.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> vec[i].from >> vec[i].to >> vec[i].len;
	}
	cin >> Start >> End;

	cout << Dijecstra();

	return 0;
}