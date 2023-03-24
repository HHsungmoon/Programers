#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int key_idx = 1; int max_lange = 1 + 2 * w;
    for (int i = 0; i < stations.size(); i++)
    {
        if (key_idx >= stations[i] - w && key_idx <= stations[i] + w)
        {
            key_idx = stations[i] + w + 1;
        }
        else
        {
            int len = stations[i] - w - key_idx;
            int tmp = len / max_lange;
            if (len % max_lange != 0)
                tmp++;
            answer += tmp;
            key_idx = stations[i] + w + 1;
        }
        
    }

    if (key_idx > n)
        return answer;

    int len = n+1 - key_idx;
    if (len <= 0)
        return answer;
    int tmp = len / max_lange;
    if (len % max_lange != 0)
        tmp++;
    answer += tmp;
    
    return answer;
}
