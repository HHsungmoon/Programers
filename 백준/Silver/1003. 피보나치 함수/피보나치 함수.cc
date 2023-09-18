#include <iostream>
#include <vector>
using namespace std;


int cnt_0 = 0;
int cnt_1 = 0;

vector<pair<int,int>> dp(41);


void fibonacci(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    cout << dp[n].first << " " << dp[n].second << endl;
}

int main()
{
    int c;
    cin >> c;

    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;

    for (int i = 0; i < c; i++)
    {
        int tmp;
        cin >> tmp;
        fibonacci(tmp);
        
    }
    
    return 0;
}