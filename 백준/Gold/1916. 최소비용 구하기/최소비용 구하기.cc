#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max_num 100000001

int N, Bus_num;

typedef struct
{
	int sx;
	int ay;
	int len;
}Node;

vector<Node> vec;
int Start, End;


int Dijecstra_Algorithm()
{
	vector<int> visited(N+1,0);
	vector<int> dijecstra(N+1, Max_num);

	visited[Start] = 1;
	dijecstra[Start] = 0;
	pair<int, int> tmp = make_pair(Start, 0);
	while (visited[End] == 0)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].sx == tmp.first && visited[vec[i].ay] == 0)
			{
				dijecstra[vec[i].ay] = min(dijecstra[vec[i].ay], tmp.second + vec[i].len);
			}
		}
		int idx=0; int min_len = Max_num;
		for (int i = 1; i < dijecstra.size(); i++)
		{
			if (visited[i] == 0)
			{
				if (min_len > dijecstra[i])
				{
					idx = i;
					min_len = dijecstra[i];
				}
			}
		}
		tmp = make_pair(idx, min_len);
		visited[idx] = 1;
	}

	return dijecstra[End];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Bus_num;
	for (int i = 0; i < Bus_num; i++)
	{
		Node tmp;
		cin >> tmp.sx >> tmp.ay >> tmp.len;
		vec.push_back(tmp);
	}
	cin >> Start >> End;

	int ans = Dijecstra_Algorithm();
	cout << ans;

	return 0;
}