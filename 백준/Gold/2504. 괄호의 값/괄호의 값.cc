#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	stack<char> stack;
	int tmp = 1; bool tf = false;
	int ans = 0;

	for (int t = 0; t < str.length(); t++)
	{
		char c = str[t];
		if (c == '(')
		{
			stack.push(c);
			tmp *= 2;
			tf = true;
		}
		else if (c == '[')
		{
			stack.push(c);
			tmp *= 3;
			tf = true;
		}
		else if (c == ')')
		{
			if (stack.empty()==true || stack.top() == '[')
			{
				cout << 0;
				return 0;
			}

			if (tf == true)
			{
				ans += tmp;
				tf = false;
			}

			if (stack.top() == '(')
			{
				tmp = tmp / 2;
				stack.pop();
			}
		}
		else if (c == ']')
		{
			if (stack.empty() == true || stack.top() == '(')
			{
				cout << 0;
				return 0;
			}

			if (tf == true)
			{
				ans += tmp;
				tf = false;
			}

			if (stack.top() == '[')
			{
				tmp = tmp / 3;
				stack.pop();
			}
			
		}
	}

	if (stack.empty() == false)
		cout << 0;
	else
		cout << ans;

	return 0;
}