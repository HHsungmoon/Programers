#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<int> vec;
	vec.push_back(-1);
	
	int ans = 0; 

	for (int i = 0; i < str.length(); i++)
	{
		int idx = vec.size()-1;
		char c = str[i];
		if (c == '(' || c == '[')
		{
			if (vec[idx] == -2 || vec[idx] == -3)
				vec.push_back(-5);
			else
				vec.push_back(-4);

			if (c == '(')
				vec.push_back(-2);
			else
				vec.push_back(-3);
		}
		else if (c == ')' || c == ']')
		{
			if (vec[idx] == -2 && c == ')')
			{
				vec.pop_back();
				vec.push_back(2);
			}
			else if (vec[idx] == -3 && c == ']')
			{
				vec.pop_back();
				vec.push_back(3);
			}
			else 
			{
				int tmp = idx;
				while (1)
				{
					tmp--;
					if (tmp <= 0)
					{
						cout << 0;
						return 0;
					}
					if (vec[tmp] == -3 || vec[tmp] == -2)
						break;
				}

				if (vec[tmp] == -2 && c == ']' || vec[idx] == -3 && c == ')')
				{
					cout << 0;
					return 0;
				}

				if (vec[tmp] == -2 && c == ')')
				{
					vec[tmp] = 2;
				}
				else if (vec[tmp] == -3 && c == ']')
				{
					vec[tmp] = 3;
				}

				int tmp_ans =vec[idx]; int num = 0;
				vec.pop_back(); idx--;
				while (idx >= tmp)
				{
					if (vec[idx] == -4)
					{
						tmp_ans += vec[idx - 1];
						idx -= 2;
						vec.pop_back();
						vec.pop_back();
					}
					else
					{
						tmp_ans *= vec[idx - 1];
						idx -= 2;
						vec.pop_back();
						vec.pop_back();
					}
				}
				vec.push_back(tmp_ans);
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > 0)
		{
			ans += vec[i];
		}
		else if (vec[i] == -2 || vec[i] == -3)
		{
			ans = 0;
			break;
		}
	}
	cout << ans;
	return 0;
}