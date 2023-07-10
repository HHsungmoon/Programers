#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    if (sticker.size() == 1)
        return sticker[0];
    if (sticker.size() == 2)
        return max(sticker[0], sticker[1]);

    vector<int> dp1(sticker.size(),0);
    vector<int> dp2(sticker.size(),0);

    dp1[0] = sticker[0]; dp1[1] = sticker[0];
    for (int i = 2; i < sticker.size()-1; i++)
    {
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
    }
    answer = dp1[sticker.size() - 2];

    dp2[0] = 0; dp2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
    {
        dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);
    }
    if (dp2[sticker.size() - 1] > answer)
        answer = dp2[sticker.size() - 1];

    //std::cout << answer << endl;
    return answer;
}