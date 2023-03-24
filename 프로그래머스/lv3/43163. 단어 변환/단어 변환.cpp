#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 50;
bool visited[50];

bool check_changeble(string str1, string str2)
{
    int cnt = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            cnt++;
        
        if (cnt == 2)
            return false;
    }
    return true;
}

void DFS(string begin, string target, vector<string>words, int step) 
{
    if (answer <= step)
        return;

    if (begin == target)
    {
        answer = min(answer, step);
        return;
    }

    for (int i = 0; i < words.size(); i++) 
    {
        if (check_changeble(begin, words[i]) && visited[i]!=1)
        {
            visited[i] = true;
            DFS(words[i], target, words, step + 1);
            visited[i] = false;
        }
    }

    return;
}
int solution(string begin, string target, vector<string> words) 
{
    DFS(begin, target, words, 0);

    if (answer == 50)
        return 0;

    return answer;
}