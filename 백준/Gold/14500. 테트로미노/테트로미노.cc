#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Tetromino_type1(int N, int M, int** arr)
{
	// 1번 ㅁㅁㅁㅁ
	int type1_max_num = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M - 3; x++)
		{
			int tmp = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
			if (type1_max_num < tmp)
				type1_max_num = tmp;
		}
	}
	return type1_max_num;
}

int Tetromino_type2(int N, int M, int** arr)
{
	int type1_max_num = 0;
	for (int y = 0; y < N-3; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int tmp = arr[y][x] + arr[y+1][x] + arr[y+2][x] + arr[y+3][x];
			if (type1_max_num < tmp)
				type1_max_num = tmp;
		}
	}
	return type1_max_num;
}

int Tetromino_type3(int N, int M, int** arr)
{
	// type2  ㅁ3x2ㅁ
	int type3_max_num = 0;
	int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
	vector<int> type_arr(10);
	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < M - 2; x++)
		{
			// 블럭 6개값 입력
			tmp1 = arr[y][x]; tmp2 = arr[y][x + 1]; tmp3 = arr[y][x + 2];
			tmp4 = arr[y + 1][x]; tmp5 = arr[y + 1][x + 1]; tmp6 = arr[y + 1][x + 2];
			//case1 4각형
			type_arr[0] = tmp1 + tmp2 + tmp4 + tmp5;
			type_arr[1] = tmp2 + tmp3 + tmp5 + tmp6;
			//
			type_arr[2] = tmp1 + tmp2 + tmp5 + tmp6;
			type_arr[3] = tmp2 + tmp3 + tmp4 + tmp5;
			//
			type_arr[4] = tmp2 + tmp4 + tmp5 + tmp6;
			type_arr[5] = tmp1 + tmp2 + tmp3 + tmp5;
			//
			type_arr[6] = tmp1 + tmp4 + tmp5 + tmp6;
			type_arr[7] = tmp3 + tmp4 + tmp5 + tmp6;
			type_arr[8] = tmp1 + tmp2 + tmp3 + tmp6;
			type_arr[9] = tmp1 + tmp2 + tmp3 + tmp4;

			int tmp = *max_element(type_arr.begin(), type_arr.end());

			if (type3_max_num < tmp)
				type3_max_num = tmp;
		}
	}

	return type3_max_num;
}
int Tetromino_type4(int N, int M, int **arr)
{

	//type3 ㅁ3x2ㅁ

	int type4_max_num = 0;
	int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
	vector<int> type_arr(10);
	for (int y = 0; y < N - 2; y++)
	{
		for (int x = 0; x < M - 1; x++)
		{
			// 블럭 6개값 입력
			tmp1 = arr[y][x]; tmp2 = arr[y][x +1]; 
			tmp3 = arr[y+1][x]; tmp4 = arr[y + 1][x+1]; 
			tmp5 = arr[y + 2][x]; tmp6 = arr[y + 2][x + 1];
			//case1 4각형
			type_arr[0] = tmp1 + tmp2 + tmp3 + tmp4;
			type_arr[1] = tmp2 + tmp3 + tmp5 + tmp4;
			//
			type_arr[2] = tmp1 + tmp3 + tmp4 + tmp6;
			type_arr[3] = tmp2 + tmp3 + tmp4 + tmp5;
			//
			type_arr[4] = tmp2 + tmp4 + tmp3 + tmp6;
			type_arr[5] = tmp1 + tmp4 + tmp3 + tmp5;
			//
			type_arr[6] = tmp1 + tmp3 + tmp5 + tmp6;
			type_arr[7] = tmp1 + tmp3 + tmp5 + tmp2;
			type_arr[8] = tmp2 + tmp4 + tmp6 + tmp1;
			type_arr[9] = tmp2 + tmp4 + tmp6 + tmp5;

			int tmp = *max_element(type_arr.begin(), type_arr.end());

			if (type4_max_num < tmp)
				type4_max_num = tmp;
		}
	}
	return type4_max_num;
}


int main()
{
	int N, M;

	cin >> N >> M;

	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> arr[y][x];
		}
	}
	vector<int> max_can = { Tetromino_type1(N,M,arr),Tetromino_type2(N,M,arr),Tetromino_type3(N,M,arr),Tetromino_type4(N,M,arr) };
	cout << *max_element(max_can.begin(),max_can.end()) << endl;

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
	
	return 0;
}