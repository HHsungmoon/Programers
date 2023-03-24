#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    
    vector<vector<int>> vec;
    vec.push_back(triangle[0]);
    
    for(int i=1; i<triangle.size(); i++)
    {
        vector<int> tmp(i+1);
        
        tmp[0] = vec[i-1][0] + triangle[i][0];
        tmp[0+1] = vec[i-1][0] + triangle[i][0+1];
        for(int t=0; t<vec[i-1].size(); t++)
        {
            tmp[t] = max(tmp[t],vec[i-1][t] + triangle[i][t]);
            
            tmp[t+1] = vec[i-1][t] + triangle[i][t+1];
        }
        vec.push_back(tmp);
    }
    
    answer = vec[vec.size()-1][0];
    for(int i=1; i<vec[vec.size()-1].size(); i++)
    {
        if(answer < vec[vec.size()-1][i])
            answer = vec[vec.size()-1][i];
    }
    
    
    return answer;
}