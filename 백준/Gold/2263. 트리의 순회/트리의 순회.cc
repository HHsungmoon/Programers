#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> inorder;
vector<int> post;

void preorder(int in_s, int in_e, int post_s, int post_e)
{
	if (in_s > in_e || post_s > post_e)
		return;

	int i; int root = post[post_e];
	for (i = in_s; i <= in_e; i++)
	{
		if (root == inorder[i])
			break;
	}

	cout << root << " ";
	
	int left_len = i - in_s;

	preorder(in_s, i - 1, post_s, post_s+left_len-1);
	preorder(i + 1, in_e, post_s+ left_len, post_e - 1);


	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	inorder.resize(N);
	post.resize(N);

	for (int i = 0; i < N; i++)
		cin>> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];

	preorder(0, inorder.size()-1, 0, post.size()-1);

	return 0;
}