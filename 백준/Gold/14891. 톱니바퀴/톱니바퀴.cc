#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <math.h>

using namespace std;

vector<deque<int>> vec(5, deque<int>(8,0));

int visited[5] = { 0,0,0,0,0 };

void Rotation_Right(int num);

void Rotation_Left(int num) // 반시계
{
	visited[num] = 1;
	if (num == 1)
	{
		if (vec[num][2] != vec[num + 1][6] && visited[num+1] ==0) // 반대로 회전
		{
			Rotation_Right(num + 1);
		}
	}
	else if (num == 4)
	{
		if (vec[num][6] != vec[num -1][2] && visited[num-1] == 0) // 반대로 회전
		{
			Rotation_Right(num-1);
		}
	}
	else if(num==2 || num==3)// 2,3
	{
		if (vec[num][2] != vec[num + 1][6] && visited[num + 1] == 0) // 반대로 회전
		{
			Rotation_Right(num + 1);
		}
		if (vec[num][6] != vec[num - 1][2] && visited[num - 1] == 0) // 반대로 회전
		{
			Rotation_Right(num-1);
		}
	}
	int tmp = vec[num].front();
	vec[num].pop_front();
	vec[num].push_back(tmp);
}

void Rotation_Right(int num) // 시계방향
{
	visited[num] = 1;
	if (num == 1)
	{
		if (vec[num][2] != vec[num + 1][6] && visited[num + 1] == 0) // 반대로 회전
		{
			Rotation_Left(num + 1);
		}
	}
	else if (num == 4)
	{
		if (vec[num][6] != vec[num - 1][2] && visited[num - 1] == 0) // 반대로 회전
		{
			Rotation_Left(num - 1);
		}
	}
	else// 2,3
	{
		if (vec[num][2] != vec[num + 1][6] && visited[num + 1] == 0) // 반대로 회전
		{
			Rotation_Left(num + 1);
		}
		if (vec[num][6] != vec[num - 1][2] && visited[num - 1] == 0) // 반대로 회전
		{
			Rotation_Left(num - 1);
		}
	}

	int tmp = vec[num].back();
	vec[num].pop_back();
	vec[num].push_front(tmp);
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		string tmp = "";
		cin >> tmp;
		for (int t = 0; t < 8; t++)
		{
			if (tmp[t] == '0')
				vec[i][t] = 0;
			else if (tmp[t] == '1')
				vec[i][t] = 1;
		}
	}

	int K;
	cin >> K;

	for (int k = 0; k < K; k++)
	{
		int num, dir;
		cin >> num >> dir;
		if (dir == 1)
		{
			Rotation_Right(num);
		}
		else if (dir == -1)
		{
			Rotation_Left(num);
		}

		for (int i = 0; i <= 4; i++)
		{
			visited[i] = 0;
		}
	}

	int answer = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (vec[i].front() == 1) // s극 이면
		{
			answer += pow(2, i-1);
		}
	}
	cout << answer;
	return 0;
}