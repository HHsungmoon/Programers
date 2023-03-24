#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;
    
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
        
    
    int avg = s/n;
    int nam = s%n;
    
    for(int i=0; i<n-nam; i++)
    {
        answer.push_back(avg);
    }
    for(int i=n-nam; i<n; i++)
    {
        answer.push_back(avg+1);
    }
    
    return answer;
}